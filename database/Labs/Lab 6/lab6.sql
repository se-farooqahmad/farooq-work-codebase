use [lab5]

--Exercise 1

--i. This query returns distinct names of employees who have a dependent or are a manager of a department
select e.fname, e.lname
from employee e inner join dependent d on e.ssn=d.essn
union 
select e.fname, e.lname
from department d inner join employee e on e.ssn=d.Mgr_ssn
order by fname, lname

--ii. This query returns all names of employees who have a dependent or are a manager of a department
select fname, lname
from employee e inner join dependent d on e.ssn=d.essn
union all
select e.fname, e.lname
from DEPARTMENT d inner join employee e on e.ssn=d.Mgr_ssn
order by fname, lname

--iii. This query returns names of employees who have a dependent and are managers of their respective departments 
select fname, lname
from employee e inner join dependent d on e.ssn=d.essn
intersect 
select e.fname, e.lname
from DEPARTMENT d inner join employee e on e.ssn=d.Mgr_ssn
order by fname, lname

--iv. This query returns only those employees who have a dependent but are not managers of a department
select fname, lname
from employee e inner join dependent d on e.ssn=d.essn
except
select e.fname, e.lname
from DEPARTMENT d inner join employee e on e.ssn=d.Mgr_ssn
order by fname, lname


--Exercise 2

--v. Subquery returns maximum salary value from employee table and main query compares the salary with it and displays a name
--Single row subquery
select fname, lname 
from employee  
where salary = (select MAX(salary) from employee)

--vi. Subquery returns essn from dependent and main query returns those employees that exist in that column (have a dependent)
--Multiple row subquery
select fname, lname
from employee  where ssn in (select essn from dependent)

--vii. Subquery returns essn from dependent and main query returns any employee that matches with essn in dependent
--Multiple row subquery
select fname, lname
from employee  where ssn = any (select essn from dependent)

--viii. Subquery returns a table of employees who have a dependent and the main query verifies the existances of employees in that table and returns a separate table
--Correlated subquery
select e.fname, e.Lname
from employee e where exists (select * from dependent d where d.essn=e.ssn)

--ix. Subquery returns the number of locations of each department number. Main query returns the name of department that has the greatest number of locations
--Correlated subquery
select d.dname
from department d join dept_locations lo on d.Dnumber=lo.Dnumber
group by d.Dname, d.Dnumber
having COUNT(*) >= all (select COUNT(*)from dept_locations li group by li.dnumber)


--Exercise 3

--1.
select distinct e.fname, e.Lname
from employee e inner join works_on w on e.ssn = w.essn
where w.Pno in
(select p.Pnumber
from project p
where p.Pname = 'ProductX' or p.Pname = 'ProductY')

--2.
select distinct e.fname, e.Lname
from employee e inner join works_on w on e.ssn = w.essn
where w.Pno in
(select p.Pnumber
from project p
where p.Pname = 'ProductX')
intersect
select distinct e.fname, e.Lname
from employee e inner join works_on w on e.ssn = w.essn
where w.Pno in
(select p.Pnumber
from project p
where p.Pname = 'ProductY')

--3
select distinct e.fname, e.Lname
from employee e inner join works_on w on e.ssn = w.essn
where w.Pno in
(select p.Pnumber
from project p
where p.Pname = 'ProductY')
except
select distinct e.fname, e.Lname
from employee e inner join works_on w on e.ssn = w.essn
where w.Pno in
(select p.Pnumber
from project p
where p.Pname = 'ProductX')

--4
select e.fname, e.Lname
from employee e
where e.salary = 
(select min(e.salary)
from employee e)

--5
select e.fname, e.Lname
from employee e inner join works_on w on e.ssn = w.essn
where e.fname <> 'Jennifer' and e.Lname <> 'Wallace'
group by e.fname, e.Lname
having count(*) =
(select count(*)
from employee e inner join works_on w on e.ssn = w.essn
where e.fname = 'Jennifer' and e.Lname = 'Wallace')

--6
select distinct e.fname, e.Lname
from employee e inner join works_on w on e.ssn = w.essn 
		inner join project p on w.Pno = p.Pnumber
where e.Dno <> p.Dnum