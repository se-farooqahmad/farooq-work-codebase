use [lab5]

create table hotel(
hotelno varchar(10) primary key,
hotelname varchar(20),
city varchar(20),
)

insert into hotel values('fb01', 'Grosvenor', 'Houston');
insert into hotel values('fb02', 'Watergate', 'Paris');
insert into hotel values('ch01', 'Omni Shoreham', 'London');
insert into hotel values('ch02', 'Phoenix Park', 'Amsterdam');
insert into hotel values('dc01', 'Latham', 'Berlin');
insert into hotel values('ch03', 'Sheraton', 'London');

 -- create a table named hotel

 create table room(

roomno numeric(5),
hotelno varchar(10),
type varchar(10),
price decimal(5,2),
primary key (roomno, hotelno),
foreign key (hotelno) REFERENCES hotel(hotelno)
)

insert into room values(501, 'fb01', 'single', 19);
insert into room values(601, 'fb01', 'double', 29);
insert into room values(701, 'fb01', 'family', 39);
insert into room values(1001, 'fb02', 'single', 58);
insert into room values(1101, 'fb02', 'double', 86);
insert into room values(1001, 'ch01', 'single', 29.99);
insert into room values(1101, 'ch01', 'family', 59.99);
insert into room values(701, 'ch02', 'single', 10);
insert into room values(801, 'ch02', 'double', 15);
insert into room values(901, 'dc01', 'single', 18);
insert into room values(1001, 'dc01', 'double', 30);
insert into room values(1101, 'dc01', 'family', 35);
insert into room values(1102, 'dc01', 'family', 40);
insert into room values(1103, 'ch03', 'family', 40);

create table guest(
guestno numeric(5),
guestname varchar(20),
guestaddress varchar(50),
primary key (guestno)
)

insert into guest values(10001, 'John Kay', '56 High St, London');
insert into guest values(10002, 'Mike Ritchie', '18 Tain St, London');
insert into guest values(10003, 'Mary Tregear', '5 Tarbot Rd, Aberdeen');
insert into guest values(10004, 'Joe Keogh', '2 Fergus Dr, Aberdeen');
insert into guest values(10005, 'Carol Farrel', '6 Achray St, Glasgow');
insert into guest values(10006, 'Tina Murphy', '63 Well St, Glasgow');
insert into guest values(10007, 'Tony Shaw', '12 Park Pl, Glasgow');


create table booking(
hotelno varchar(10),
guestno numeric(5),
datefrom datetime,
dateto datetime,
roomno numeric(5),
primary key (hotelno, guestno, datefrom),
foreign key (roomno, hotelno) REFERENCES room(roomno, hotelno),
foreign key (guestno) REFERENCES guest(guestno)
)

 

insert into booking values('fb01', 10001, '04-04-01', '04-04-08', 501);
insert into booking values('fb01', 10004, '04-04-15', '04-05-15', 601);
insert into booking values('fb01', 10005, '04-05-02', '04-05-07', 501);
insert into booking values('fb01', 10001, '04-05-01', null, 701);
insert into booking values('fb02', 10003, '04-04-05', '10-04-04', 1001);
insert into booking values('ch01', 10006, '04-04-21', null, 1101);
insert into booking values('ch02', 10002, '04-04-25', '04-05-06', 801);
insert into booking values('dc01', 10007, '04-05-13', '04-05-15', 1001);
insert into booking values('dc01', 10003, '04-05-20', null, 1001);


select g.guestname, g.guestaddress
from guest g
where g.guestaddress like '%London'
order by g.guestname

select g.guestname
from guest g inner join booking b on g.guestno = b.guestno
where b.dateto is null

select * from hotel
select * from booking
select * from guest
select distinct h.hotelname, h.city
from hotel h inner join room r on h.hotelno = r.hotelno
		inner join booking b on r.hotelno = b.hotelno
			inner join guest g on b.guestno = g.guestno
where g.guestaddress like '%London'

select avg(r.price) avgPrice
from room r inner join hotel h on r.hotelno = h.hotelno
where h.city = 'London'

select * from room
select r.type, max(r.price) maxPrice
from room r
where r.type = 'double'
group by r.type

select r.type, max(r.price) maxPrice
from room r
where r.type = 'single'
group by r.type

select r.type, max(r.price) maxPrice
from room r
where r.type = 'family'
group by r.type


select h.hotelname, count(*) noOfRooms
from hotel h inner join room r on h.hotelno = r.hotelno
group by hotelname

select h.hotelname, h.city, count(*) familyCount
from hotel h inner join room r on h.hotelno = r.hotelno
where r.type = 'family'
group by h.hotelname, h.city

select h.hotelname, h.city, count(*) singleCount
from hotel h inner join room r on h.hotelno = r.hotelno
where r.type = 'single'
group by h.hotelname, h.city

select h.hotelname, h.city, count(*) doubleCount
from hotel h inner join room r on h.hotelno = r.hotelno
where r.type = 'double'
group by h.hotelname, h.city

select distinct h.hotelname, b.datefrom
from hotel h inner join room r on h.hotelno = r.hotelno
		 left outer join booking b on r.hotelno = b.hotelno
order by h.hotelname


--Post Lab 5

--Q1
select h.hotelname, b.roomno, b.guestno, year(b.datefrom) year
from hotel h inner join booking b on h.hotelno = b.hotelno
where year(b.datefrom) = '2001' or year(b.datefrom) = '2002'

select * from hotel
select * from booking

--Q2
select h.hotelname, h.hotelno, r.roomno, r.type, r.price
from hotel h left outer join room r 
on h.hotelno = r.hotelno and r.type = 'family'

--Q3
select h.city, count(*) hotels
from hotel h
group by h.city

--Q4
select sum(r.price) totalrevenue
from room r
where r.type = 'double'

--Q5
select count(distinct b.guestno) guests
from booking b 
where b.dateto <= '2015-05-01'

--Q6
select min(r.price) minPrice, h.city
from room r inner join hotel h
on r.hotelno = h.hotelno
group by h.city

--Q7
select g.guestname, count(b.roomno) rooms
from guest g inner join booking b 
on g.guestno = b.guestno
group by g.guestname
having count(b.roomno) > 1

--Q8
select h.hotelname, h.city, count(distinct b.datefrom) reservations
from hotel h inner join room r 
on h.hotelno = r.hotelno inner join booking b
on r.hotelno = b.hotelno
group by h.hotelname, h.city
order by reservations desc

select *
from hotel h inner join room r 
on h.hotelno = r.hotelno inner join booking b
on r.hotelno = b.hotelno

select g.guestname, count(b.roomno) NoofRoomsBooked
from guest g inner join booking b on g.guestno=b.guestno
group by g.guestname
having count(b.roomno)>1

select g.guestname, b.roomno
--count(distinct b.roomno) NoofRoomsBooked
from guest g inner join booking b on g.guestno=b.guestno
--group by g.guestname