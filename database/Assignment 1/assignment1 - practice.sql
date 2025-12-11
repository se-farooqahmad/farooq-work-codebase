--3.
--i.
select a.Name, DATEDIFF(yy, a.birthdate, GETDATE()) Age
from Actor a
where DATEDIFF(yy, a.birthdate, GETDATE()) > 60
order by Age, a.Name

--ii.
select m.Title, m.Year 
from Movie m inner join Studio stu on m.StudioName = stu.Name
where (m.Year between '2000' and '2010') and (stu.Networth > 1000000000)

--iii.
select a.Name, si.MovieTitle
from Actor a left outer join StarsIn si on a.ID = si.ActorID
where a.birthdate < '01-01-1960'
order by si.MovieTitle

--iv.
select m.Title, max(r.rating), min(r.rating), avg(r.rating)
from Rating r inner join Movie m on r.MovieTitle = m.Title
where m.StudioName in 
(
	select stu.Name
	from Studio stu inner join Movie m on stu.Name = m.StudioName
	where (stu.Address like '%California%')
	group by m.StudioName, stu.Name
	having (COUNT(m.Title) > 6)
)
group by m.Title

--v.
select a1.Name A1, a2.Name A2, si.MovieTitle
from Actor a1, Actor a2, StarsIn si
where a1.ID = si.ActorID
group by si.MovieTitle, a1.Name, a2.Name, a1.ID, a2.ID
having si.MovieTitle in 
(
	select s.MovieTitle
	from StarsIn s 
	where a2.ID = s.ActorID and a2.Name > a1.Name
)
order by si.MovieTitle

--vi.
select s.Rollnumber, s.Name
from Student s
where s.Rollnumber not in
(
	select r1.Rnumber
	from Rating r1
)

--vii.
select s.Name, s.Rollnumber
from Rating r inner join Student s on r.Rnumber = s.Rollnumber
group by s.Rollnumber, s.Name
having COUNT(*) =
(
	select COUNT(*)
	from Movie m
)

--viii.
select m.Title, m.ProductionCost
from Movie m
where m.ProductionCost = 
(
	select max(m2.ProductionCost)
	from Movie m2
	where m2.ProductionCost <>
	(
		select max(m1.ProductionCost)
		from Movie m1 
	)
)

--ix.
select r.MovieTitle
from Rating r
group by r.MovieTitle
having COUNT(*) = 
(
	select max(s1.RatingCount)
	from 
	(
		select COUNT(*) RatingCount
		from Rating r1
		group by r1.MovieTitle
	) s1
)

--x.
select a.Name, a.ID, COUNT(*) ActorMovieCount
from Actor a inner join StarsIn si on a.ID = si.ActorID
group by si.ActorID, a.Name, a.ID
having COUNT(*) >
(
	select max(s1.ActressMovieCount)
	from
	(
		select COUNT(*) ActressMovieCount
		from StarsIn si1 inner join Actor a1 on si1.ActorID = a1.ID
		where a1.Gender = 'F'
		group by si1.ActorID 
	) s1
)

--xi.
select distinct a.Name
from Actor a inner join StarsIn si on a.ID = si.ActorID
		inner join Movie m on si.MovieTitle = m.Title
where (m.StudioName like 'UNIVERSAL PICTURES') and a.ID not in
(
	select si1.ActorID 
	from StarsIn si1 inner join Movie m1 on si1.MovieTitle = m1.Title
	where m1.StudioName like 'TWENTIETH CENTURY FOX'
)

--xii.
select s.Name 
from Student s inner join Rating r on s.Rollnumber = r.Rnumber
where r.MovieTitle like 'GLADIATOR'
intersect
select s.Name 
from Student s inner join Rating r on s.Rollnumber = r.Rnumber
where r.MovieTitle like 'BORN FREE'