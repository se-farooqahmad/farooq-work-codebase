use [lab5]

--1.
create table T_EmployeeDetail
(
	EmployeeSSN varchar(9),
	Name varchar(30),
	salary int,
	Address varchar(200)
)

create procedure SP_NewEmployeeDetail
as
insert into T_EmployeeDetail 
select e.ssn, e.fname + ' ' + e.Lname, e.salary, e.address
from employee e

SP_NewEmployeeDetail
select * from T_EmployeeDetail


--2.
create procedure GetMaxSalaryEarner @departmentName varchar(50) = NULL, @earnerName varchar(50) output
as
select @earnerName = (e.fname + ' ' + e.Lname)
from employee e inner join department d on e.Dno = d.Dnumber
where (d.Dname = @departmentName) and e.salary = 
(
	select max(e1.depSalary)
	from 
	(
		select e2.salary depSalary
		from employee e2 inner join department d on e2.Dno = d.Dnumber
		where d.Dname = @departmentName
	) e1
)

declare @eName varchar(50)
exec GetMaxSalaryEarner 'Research', @eName output
select @eName Name

declare @eName varchar(50)
exec GetMaxSalaryEarner 'Headquarters', @eName output
select @eName Name

declare @eName varchar(50)
exec GetMaxSalaryEarner 'Administration', @eName output
select @eName Name

declare @eName varchar(50)
exec GetMaxSalaryEarner 'Accounts', @eName output
select @eName Name


--3.
create view EmployeeView 
as
(
	select e.fname + ' ' + e.Lname Name, e.salary
	from employee e inner join works_on w on e.ssn = w.essn
	group by w.essn, e.fname, e.Lname, e.salary
	having count(w.Pno) = 
	(
		select max(w1.projectCount)
		from 
		(
			select w2.essn, count (w2.Pno) projectCount
			from works_on w2
			group by w2.essn
		) w1
	)
)

select * from employee
select * from works_on
select * from EmployeeView