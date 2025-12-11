use [lab5]

--1.
select g.guestname
from guest g inner join booking b on g.guestno = b.guestno
		inner join hotel h on b.hotelno = h.hotelno
where h.hotelname = 'Watergate'
intersect
select g.guestname
from guest g inner join booking b on g.guestno = b.guestno
		inner join hotel h on b.hotelno = h.hotelno
where h.hotelname = 'Latham'

--2.
select distinct g.guestname
from guest g inner join booking b on g.guestno = b.guestno
		inner join hotel h on b.hotelno = h.hotelno
where h.hotelname = 'Watergate' or h.hotelname = 'Latham'

--3.
select g.guestname
from guest g inner join booking b on g.guestno = b.guestno
		inner join hotel h on b.hotelno = h.hotelno
where (h.hotelname = 'Latham') and g.guestname not in
(
	select g.guestname
	from guest g inner join booking b on g.guestno = b.guestno
			inner join hotel h on b.hotelno = h.hotelno
	where h.hotelname = 'Watergate'
)

--4.
select g.guestname
from booking b inner join guest g on b.guestno = g.guestno
group by b.guestno, g.guestname
having count(distinct b.hotelno) =
(
	select max(sc.StayCount)
	from 
	(
		select count (b.hotelno) StayCount
		from booking b
		group by b.guestno
	) sc
)

--5.
select h.hotelname
from room r inner join hotel h on r.hotelno = h.hotelno
where h.hotelname <> 'Latham'
group by r.hotelno, h.hotelname
having count(*) = 
(
	select count(*) RoomCount
	from room r inner join hotel h on r.hotelno = h.hotelno
	where h.hotelname = 'Latham'
	group by r.hotelno
)

--6.
select h.hotelname
from room r inner join hotel h on r.hotelno = h.hotelno
where r.price = 
(
	select min(r.price)
	from room r
)