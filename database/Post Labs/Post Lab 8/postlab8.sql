use [lab8]

--1.
create trigger T_NoChangeInDeparment
on t_department
instead of insert, delete, update
as
print 'CAN NOT MODIFY DEPARTMENT'

insert into t_department(dept_name, building, budget)
values('EE', 'BuildingEE', 20000)

update t_department set budget = 25000 where dept_name = 'C'

delete from t_department where dept_name = 'C'

select * from t_department


--2.
create trigger T_NoChangeInAuditing
on Auditing
instead of delete, update
as
print 'CAN NOT DELETE OR UPDATE AUDITING'

insert into Auditing(LastChangeOn, Description)
values('2019-10-26', 'ABC')

update Auditing set LastChangeOn = '2019-10-27' where AuditId = 2

delete from Auditing where AuditId = 1

select * from Auditing

truncate table Auditing