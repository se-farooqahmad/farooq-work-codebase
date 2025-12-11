use [movie]

create table Movie 
(
	Title varchar(150) not null,
	Year varchar(4),
	Length int,
	StudioName varchar(150),
	ProductionCost bigint,
	constraint MOVIEPK primary key (Title)
);

create table StarsIn
(
	ActorID varchar(20) not null,
	MovieTitle varchar(150) not null,
	constraint STARSINPK primary key (ActorID, MovieTitle),
	constraint STARSINFK2 foreign key (MovieTitle) references Movie (Title)
);

create table Actor
(
	ID varchar(20) not null,
	Name varchar(150),
	birthdate date,
	Gender varchar(1),
	constraint ACTORPK primary key (ID)
);

alter table StarsIn add constraint STARSINFK1 foreign key (ActorID) references Actor (ID)

create table Studio
(
	Name varchar(150) not null,
	Address varchar(150),
	Networth bigint,
	constraint STUDIOPK primary key (Name)
);
 
alter table Movie add constraint MOVIEFK foreign key (StudioName) references Studio (Name)

create table Student
(
	Rollnumber varchar(20) not null,
	Name varchar(150),
	constraint STUDENTPK primary key (Rollnumber)
);

create table Rating
(
	MovieTitle varchar(150) not null,
	Rnumber varchar(20) not null,
	rating int check (rating >=1 and rating <=5)
	constraint RATINGPK primary key (MovieTitle, Rnumber),
	constraint RATINGFK1 foreign key (MovieTitle) references Movie (Title),
	constraint RATINGFK2 foreign key (Rnumber) references Student (Rollnumber)
);

insert into Actor 
values ('54761', 'Joaquin Phoenix', '28-Oct-74', 'M')

insert into Studio 
values ('DC COMICS', 'Burbank,California', 4000000000)

insert into Student 
values ('16L-4450', 'Duaa Ali')

insert into Movie 
values ('JOKER', '2019', 120, 'DC COMICS', 55000000)

insert into StarsIn 
values ('54761', 'JOKER')

insert into Rating 
values ('JOKER', '16L-4450', 2)


select * from Movie
select * from StarsIn
select * from Actor
select * from Studio
select * from Student
select * from Rating


--i.
select a.Name, datediff(year, a.birthdate, getdate()) Age
from Actor a
where datediff(year, a.birthdate, getdate()) > 60
order by Age, a.Name

--ii.
select m.Title, m.Year, m.StudioName, st.Networth
from Movie m inner join Studio st on m.StudioName = st.Name
where (m.Year between '2000' and '2010') and (st.Networth > 1000000000)

--iii.
select a.Name, si.MovieTitle
from Actor a left outer join StarsIn si on a.ID = si.ActorID 
where a.birthdate < '1960-01-01'
order by si.MovieTitle

--iv
select m.Title, min(r.rating) MinRating, max(r.rating) MaxRating, avg(r.rating) AvgRating
from Rating r inner join Movie m on r.MovieTitle = m.Title
		inner join Studio st on m.StudioName = st.Name
where (st.Address like '%California%') and m.StudioName in
(
	select m.StudioName
	from Movie m 
	group by m.StudioName
	having count(m.StudioName) >= 15
)
group by m.Title

select min(rt.rating) MinRating, max(rt.rating) MaxRating, avg(rt.rating) AvgRating
from
(
	select r.rating
	from Rating r inner join Movie m on r.MovieTitle = m.Title
			inner join Studio st on m.StudioName = st.Name
	where (st.Address like '%California%') and m.StudioName in
	(
		select m.StudioName
		from Movie m 
		group by m.StudioName
		having count(m.StudioName) >= 5
	)
	group by st.Name, r.rating
) rt

--v.
select a.Name, si.MovieTitle
from Actor a inner join StarsIn si on a.ID = si.ActorID
where si.MovieTitle in 
(
	select si.MovieTitle
	from StarsIn si
	group by si.MovieTitle
	having count(si.MovieTitle) >= 2
)
order by si.MovieTitle

select min(x.Actor) A1, max(x.Actor) A2, x.MovieTitle
from
(
	select a.Name Actor, si.MovieTitle
	from Actor a inner join StarsIn si on a.ID = si.ActorID
	where si.MovieTitle in 
	(
		select si.MovieTitle
		from StarsIn si
		group by si.MovieTitle
		having count(si.MovieTitle) >= 2
	)
) x
group by x.MovieTitle

select a1.Name A1, a2.Name A2, si.MovieTitle
from Actor a1, Actor a2, StarsIn si
where (a1.ID = si.ActorID) and si.MovieTitle in 
(
	select s.MovieTitle
	from StarsIn s 
	where a2.ID = s.ActorID and a2.Name > a1.Name
)
order by si.MovieTitle

--vi
select std.Name, std.Rollnumber
from Student std
where std.Rollnumber not in
(
	select r.Rnumber
	from rating r
)

--vii.
select std.Name, std.Rollnumber
from Rating r inner join Student std on r.Rnumber = std.Rollnumber
group by std.Name, std.Rollnumber
having count(*) =
(
	select count(m.Title)
	from Movie m
)

--viii.
select m.Title, m.ProductionCost
from Movie m 
where m.ProductionCost = 
(
	select max(m.ProductionCost)
	from Movie m 
	where m.ProductionCost <>
	(
		select max(m.ProductionCost)
		from Movie m
	)
)

--ix.
select r.MovieTitle
from Rating r
group by r.MovieTitle
having count(*) =
(
	select max(r1.RatingCount) count
	from 
	(
		select r2.MovieTitle, count(*) RatingCount
		from Rating r2
		group by r2.MovieTitle
	) r1
)

--x
select a.Name, si.ActorID, count(*) MovieCount
from Actor a inner join StarsIn si on a.ID = si.ActorID
where a.Gender = 'M'
group by a.Name, si.ActorID
having count(*) >
(
	select max(amc.ActressMovieCount) MaxActressMovieCount
	from
	(
		select count(*) ActressMovieCount
		from Actor a inner join StarsIn si on a.ID = si.ActorID
		where a.Gender = 'F'
		group by si.ActorID
	) amc
)

--xi.
select distinct a.Name
from Studio st inner join Movie m on st.Name = m.StudioName
		inner join StarsIn si on m.Title = si.MovieTitle
			inner join Actor a on si.ActorID = a.ID
where (m.StudioName = 'UNIVERSAL PICTURES') and m.StudioName <> all
(
	select distinct a.Name
	from Studio st inner join Movie m on st.Name = m.StudioName
			inner join StarsIn si on m.Title = si.MovieTitle
				inner join Actor a on si.ActorID = a.ID
	where m.StudioName = 'TWENTIETH CENTURY FOX'
)

--xii.
select std.Name
from Student std inner join Rating r on std.Rollnumber = r.Rnumber
where r.MovieTitle = 'GLADIATOR'
intersect
select std.Name
from Student std inner join Rating r on std.Rollnumber = r.Rnumber
where r.MovieTitle = 'BORN FREE'