use [lab5]

CREATE VIEW v_employeeNames
As
SELECT fname, lname FROM employee

select * from v_employeeNames

Alter  VIEW v_employeeNames
As
SELECT ssn, fname, lname FROM employee

DROP VIEW v_employeeNames

create procedure getEmployeeNames
as
select fname, lname from employee

EXEC getEmployeeNames

getEmployeeNames

create procedure getEmployeeAddress @City varchar(20)
as
select fname, lname, address from employee
where address like '%'+@City+'%'

exec getEmployeeAddress @City='Houston'

alter procedure getEmployeeAddress @City varchar(20)=NULL
as
select fname, lname, address from employee
where address like '%'+@City+'%'

alter procedure getEmployeeAddress @City varchar(20)=NULL
as
select fname, lname, address from employee
where address like '%'+ISNULL(@City, address)+'%'

create procedure getEmployeeDetails @City varchar(20)=NULL, @pSal int=NULL
as
select * from employee
where address like '%'+ISNULL(@City, address)+'%'
and salary=isnull(@pSal, salary)

Exec getEmployeeDetails

getEmployeeDetails @City='Houston'

Exec getEmployeeDetails @City='Houston', @pSal=55000

create procedure getEmployeeCount @City varchar(20)=NULL, @empCount int OUT
as
select @empCount=COUNT(*) from employee
where address like '%'+ISNULL(@City, address)+'%'

Declare @empCnt int
Exec getEmployeeCount 'Houston', @empCnt output
select @empCnt

alter procedure getEmployeeAddress @City varchar(20)=NULL
as
select fname, lname, address from employee
where address like '%'+ISNULL(@City, address)+'%'

drop view y_EmployeeInfo
--1.
create view y_EmployeeInfo as
(
	select top (100) percent e.fname, e.Lname, e.salary, count(d.essn) dependents
	from employee e left outer join dependent d on e.ssn = d.essn
	group by e.fname, e.Lname, e.salary
	order by e.fname, e.Lname
)

select *
from y_EmployeeInfo

--2.
drop view y_EmployeeInfo

--3.
create procedure p_getManagers_with_Deps
as
(
	select e.fname, e.Lname
	from employee e inner join department dep on e.ssn = dep.Mgr_ssn
	where e.ssn in
	(
		select d.essn
		from dependent d
	)
)

p_getManagers_with_Deps

--4.
alter procedure p_getManagers_with_Deps
as
(
	select e.fname, e.Lname, e.salary
	from employee e inner join department dep on e.ssn = dep.Mgr_ssn
	where e.ssn in
	(
		select d.essn
		from dependent d
	)
)

p_getManagers_with_Deps