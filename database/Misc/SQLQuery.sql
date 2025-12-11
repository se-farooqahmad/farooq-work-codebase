use [A24407]
create table Student
(
StudID int primary key,
StudName varchar(40),
DeptID int,
bdate date,
GPA float,
)
 
create table Department 
(
DeptId int primary key,
DeptName varchar(25),
)

create table Course
(
CourseId int primary key,
CourseName varchar(30),
Cost int,
PreReq int,
)

create table instructor 
(
InstructorId int primary key,
InstrName varchar(25),
DeptId int,
)

create table Section
(
SectionId int primary key,
SecName varchar(20),
stime time,
CourseId int,
RoomId int,
InstrId int,
)

create table Room
(
RoomId int primary key,
roomName varchar(20),
)
create table Enrolled 
(
StudId int not null,
SectionId int not null,
Status varchar(20) not null,
Primary key(StudId,SectionId,Status),
)
alter table Student add constraint dfk foreign key(DeptID) references Department (DeptId)
alter table Course add constraint pfk foreign key(PreReq) references Course (CourseId)
alter table Instructor add constraint dpfk foreign key(DeptId) references Department (DeptId)
alter table Section add constraint cfk foreign key(CourseId) references Course (CourseId)
alter table Section add constraint ifk foreign key(InstrId) references Instructor (InstructorId)
alter table Section add constraint rfk foreign key(RoomId) references Room (RoomId)
alter table Enrolled add constraint sfk foreign key(StudId) references Student (StudID)
alter table Enrolled add constraint scfk foreign key(SectionId) references Section (SectionId)
select * from Student
select * from Department
select * from Course
select * from instructor
select * from Section
select * from Room
select * from Enrolled
-- (a)
select StudName
from Student s
inner join Enrolled e on s.StudID=e.StudId
inner join Section sec on sec.SectionId=e.SectionId
inner join course c on c.CourseId=sec.CourseId
where c.CourseName like '%Electronics-2%' and e.Status='Enrolled'
intersect
select StudName 
from Student s
inner join Enrolled e on s.StudID=e.StudId
inner join Section sec on sec.SectionId=e.SectionId
inner join course c on c.CourseId=sec.CourseId
where c.CourseName like '%Database Systems%' and e.Status='Enrolled'

--(b)
select SecName from Section s
inner join Room r on r.RoomId=s.RoomId
where r.roomName like '%E&M-5%'
union 
select SecName from section s
inner join Enrolled e on s.SectionId=e.SectionId
group by SecName
having count(e.SectionId) > 5


--(c)
select StudName
from Student s
inner join Enrolled e on s.StudID=e.StudId
inner join Section sec on sec.SectionId=e.SectionId
inner join course c on c.CourseId=sec.CourseId
group by StudName
having sum(c.Cost) > 50000




--(d)
select year(bdate), round(avg(gpa),2)
from student 
group by year(bdate)



--(e)
select s.StudName, sec.stime from student s
inner join enrolled e on s.StudID=e.StudId
inner join Section sec on sec.SectionId=e.SectionId
group by s.StudName, e.StudId,e.Status, sec.stime
having count(Sec.SectionId)>=2 and e.Status='Enrolled' 


--(f)
select  i.instrName, i.InstructorId from instructor i
where not exists
(select * from room r join section s 
on r.roomid=s.roomid and r.roomid not in
(select s.roomId from section s 
where s.instrid=i.instructorId))


--(g)
select s.StudName from student s
join Enrolled e on s.StudID=e.StudId
join section sec on sec.SectionId=e.SectionId
join Course c on c.CourseId=sec.CourseId
where e.Status='completed' and c.CourseId = (select PreReq from Course
where c.CourseName like 'Electronics-2') and not exists 
( select * from Enrolled e1 join Section sec1 on sec1.SectionId=e1.SectionId
join Course c1 on c1.CourseId=sec1.CourseId
where c1.CourseName='Electronics-2')

--(i)
select d.DeptName, i.InstrName
from department d
left outer join instructor i on i.deptid=d.deptid

--(j)
select c.coursename, count(*) No_of_Students
from course c join section s on c.courseid=s.courseid 
inner join enrolled e on s.sectionid=e.sectionid
group by c.coursename
having count(*)>= all (select count(*)
from course c join section s on c.courseid=s.courseid 
inner join enrolled e on s.sectionid=e.sectionid
group by c.coursename)


