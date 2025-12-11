use[lab8]

----------Inlab Trigger exercise for lecture---------------
create table TriggerEmployee
	(
	 Name		varchar(max),
	 EmployeeID		int,
	 ContactID		int,
	 ManagerID		int,
	 Gender			varchar(10),
	 Description		varchar(max),
	 primary key (EmployeeID)
	);
	
insert into TriggerEmployee (Name, EmployeeID,ContactID,ManagerID,Gender,Description) values ('Ahmed',1,2,2,'M','xyz')
insert into TriggerEmployee (Name, EmployeeID,ContactID,ManagerID,Gender,Description) values ('Osama',2,1,2,'M','sadsd')
insert into TriggerEmployee (Name, EmployeeID,ContactID,ManagerID,Gender,Description) values ('Qasim',3,1,2,'M','sadsff')


CREATE	TRIGGER Trigger_ForUpdate
ON		TriggerEmployee
FOR		UPDATE
AS 
UPDATE TriggerEmployee
SET Description = 'changed with For update trigger'

UPDATE TriggerEmployee
SET Name = 'New Name'
WHERE EmployeeID= 4

select * from TriggerEmployee

--refreshing the data
truncate table TriggerEmployee
insert into TriggerEmployee (Name, EmployeeID,ContactID,ManagerID,Gender,Description) values ('Ahmed',1,2,2,'M','xyz')
insert into TriggerEmployee (Name, EmployeeID,ContactID,ManagerID,Gender,Description) values ('Osama',2,1,2,'M','sadsd')
insert into TriggerEmployee (Name, EmployeeID,ContactID,ManagerID,Gender,Description) values ('Qasim',3,1,2,'M','sadsff')

select * from triggerEmployee
go

alter	TRIGGER Trigger_ForUpdate
ON		TriggerEmployee
FOR		UPDATE
AS 
declare @Employeeid int -- variable declaration
-- get the value from the table of employee id that was updated
select @Employeeid=EmployeeID from inserted 
UPDATE TriggerEmployee
SET Description = 'changed with For update trigger'
WHERE EmployeeID= @EmployeeID


go
UPDATE TriggerEmployee
SET Name = 'New Name'
WHERE EmployeeID= 2
go


create TRIGGER SampleTrigger_select
ON TriggerEmployee
INSTEAD OF   INSERT
AS 
SELECT * FROM TriggerEmployee
--print 'sorry this table cannot be modified'

go 

INSERT INTO TriggerEmployee(EmployeeID,NAME,ContactID,ManagerID,Gender)
VALUES(5, 'Instead of insert "Select Trigger" ' , 1108, 1, 'M' )

go

SELECT * FROM TriggerEmployee -- NO CHANGE IN THE TABLE

Go


create TRIGGER T_DeleteEmployee
ON	TriggerEmployee
INSTEAD OF delete
AS
	IF 
		(
			SELECT COUNT(*)
			FROM TriggerEmployee A
					
		) >0
		
	BEGIN
		PRINT 'CAN NOT BE deleted'
	END

go

DELETE from TriggerEmployee WHERE EmployeeID= 1
go
select *From TriggerEmployee
go


CREATE TRIGGER T_DeleteTable
ON	Database
FOR DROP_TABLE
AS
	PRINT 'CAN NOT BE dropped'
	RollBack  -- we dont have instead of in DDL so we use rollback
go 

DROP TABLE TriggerEmployee
go


create TRIGGER T_AlterTable_DT
ON	DatabASE
FOR ALTER_TABLE
AS
	PRINT 'Table alterd succesfully'
	
go

ALTER TABLE TriggerEmployee ALTER COLUMN [NAME] VARCHAR(60)
-- select * from TriggerEmployee
go

select * from TriggerEmployee

drop trigger T_DeleteTable on database



--InLab Exercise
create table t_classroom
	(building		varchar(15),
	 room_number		varchar(7),
	 capacity		numeric(4,0),
	 primary key (building, room_number)
	);

create table t_department
	(dept_name		varchar(20), 
	 building		varchar(15), 
	 budget		        numeric(12,2) check (budget > 0),
	 primary key (dept_name)
	);

create table t_course
	(course_id		varchar(8), 
	 title			varchar(50), 
	 dept_name		varchar(20),
	 credits		numeric(2,0) check (credits > 0),
	 primary key (course_id),
	 foreign key (dept_name) references t_department
		on delete set null
	);

create table t_instructor
	(ID			varchar(5), 
	 name			varchar(20) not null, 
	 dept_name		varchar(20), 
	 salary			numeric(8,2) check (salary > 29000),
	 primary key (ID),
	 foreign key (dept_name) references t_department
		on delete set null
	);

create table t_section
	(course_id		varchar(8), 
         sec_id			varchar(8),
	 semester		varchar(6)
		check (semester in ('Fall', 'Winter', 'Spring', 'Summer')), 
	 year			numeric(4,0) check (year > 1701 and year < 2100), 
	 building		varchar(15),
	 room_number		varchar(7),
	 time_slot_id		varchar(4),
	 primary key (course_id, sec_id, semester, year),
	 foreign key (course_id) references t_course
		on delete cascade,
	 foreign key (building, room_number) references t_classroom
		on delete set null
	);

create table t_teaches
	(ID			varchar(5), 
	 course_id		varchar(8),
	 sec_id			varchar(8), 
	 semester		varchar(6),
	 year			numeric(4,0),
	 primary key (ID, course_id, sec_id, semester, year),
	 foreign key (course_id,sec_id, semester, year) references t_section(course_id, sec_id, semester, year)
		on delete cascade,
	 foreign key (ID) references t_instructor(ID)
		on delete cascade
	);

create table t_student
	(ID			varchar(5), 
	 name			varchar(20) not null, 
	 dept_name		varchar(20), 
	 tot_cred		numeric(3,0) check (tot_cred >= 0),
	 primary key (ID),
	 foreign key (dept_name) references t_department
		on delete set null
	);

create table t_takes
	(ID			varchar(5), 
	 course_id		varchar(8),
	 sec_id			varchar(8), 
	 semester		varchar(6),
	 year			numeric(4,0),
	 grade		        varchar(2),
	 primary key (ID, course_id, sec_id, semester, year),
	 foreign key (course_id,sec_id, semester, year) references t_section(course_id, sec_id, semester, year)
		on delete cascade,
	 foreign key (ID) references t_student(ID)
		on delete cascade
	);

create table t_advisor
	(s_ID			varchar(5),
	 i_ID			varchar(5),
	 primary key (s_ID),
	 foreign key (i_ID) references t_instructor (ID)
		on delete set null,
	 foreign key (s_ID) references t_student (ID)
		on delete cascade
	);

create table t_time_slot
	(time_slot_id		varchar(4),
	 day			varchar(1),
	 start_hr		numeric(2) check (start_hr >= 0 and start_hr < 24),
	 start_min		numeric(2) check (start_min >= 0 and start_min < 60),
	 end_hr			numeric(2) check (end_hr >= 0 and end_hr < 24),
	 end_min		numeric(2) check (end_min >= 0 and end_min < 60),
	 primary key (time_slot_id, day, start_hr, start_min)
	);

create table prereq
	(course_id		varchar(8), 
	 prereq_id		varchar(8),
	 primary key (course_id, prereq_id),
	 foreign key (course_id) references t_course
		on delete cascade,
	 foreign key (prereq_id) references t_course
	);

--1.
--(a)
create table Auditing
(
	AuditId int not null identity(1,1),
	LastChangeOn date,
	constraint AUDITINGPK primary key (AuditId)
)

create trigger T_StudentTrigger
on t_student
for insert, delete, update
as
declare @LastChangeOn date
select @LastChangeOn = convert(varchar(10), getdate(), 101)
insert into Auditing(LastChangeOn)
values (@LastChangeOn)

create trigger T_DepartmentTrigger
on t_department
for insert, delete, update
as
declare @LastChangeOn date
select @LastChangeOn = convert(varchar(10), getdate(), 101)
insert into Auditing(LastChangeOn)
values (@LastChangeOn)


insert into t_department(dept_name, building, budget)
values('A', 'BuildingA', 12000)

select * from Auditing

insert into t_student(ID, name, dept_name, tot_cred)
values('5443', 'Haasin', 'A', 16)


--(b)
alter table Auditing add Description varchar(100)
select * from Auditing

--DEPARTMENT TRIGGERS
create trigger T_DepartmentInsert
on t_department
for insert
as
--storing date
declare @LastChangeOn date
select @LastChangeOn = convert(varchar(10), getdate(), 101)
--storing department name 
declare @dept_name varchar(20)
select @dept_name = dept_name from inserted
--storing description
declare @Description varchar(100)
select @Description = 'table inserted with dep_name = ' + @dept_name 
insert into Auditing(LastChangeOn, Description)
values (@LastChangeOn, @Description)



create trigger T_DepartmentDelete
on t_department
for delete
as
--storing date
declare @LastChangeOn date
select @LastChangeOn = convert(varchar(10), getdate(), 101)
--storing department name 
declare @dep_name varchar(20)
select @dep_name = dept_name from deleted
--storing description
declare @Description varchar(100)
select @Description = 'table deleted with dep_name = ' + @dep_name 
insert into Auditing(LastChangeOn, Description)
values (@LastChangeOn, @Description)



create trigger T_DepartmentUpdate
on t_department
for update
as
--storing date
declare @LastChangeOn date
select @LastChangeOn = convert(varchar(10), getdate(), 101)
--storing department name 
declare @dept_name varchar(20)
select @dept_name = dept_name from inserted
--storing description
declare @Description varchar(100)
select @Description = 'table updated with dep_name = ' + @dept_name 
insert into Auditing(LastChangeOn, Description)
values (@LastChangeOn, @Description)



--STUDENT TRIGGERS
create trigger T_StudentInsert
on t_student
for insert
as
--storing date
declare @LastChangeOn date
select @LastChangeOn = convert(varchar(10), getdate(), 101)
--storing student id
declare @ID varchar(5)
select @ID = ID from inserted
--storing description
declare @Description varchar(100)
select @Description = 'table inserted with ID = ' + @ID
insert into Auditing(LastChangeOn, Description)
values (@LastChangeOn, @Description)



create trigger T_StudentDelete
on t_student
for delete
as
--storing date
declare @LastChangeOn date
select @LastChangeOn = convert(varchar(10), getdate(), 101)
--storing student id
declare @ID varchar(5)
select @ID = ID from deleted
--storing description
declare @Description varchar(100)
select @Description = 'table deleted with ID = ' + @ID
insert into Auditing(LastChangeOn, Description)
values (@LastChangeOn, @Description)



create trigger T_StudentUpdated
on t_student
for update
as
--storing date
declare @LastChangeOn date
select @LastChangeOn = convert(varchar(10), getdate(), 101)
--storing student id
declare @ID varchar(5)
select @ID = ID from inserted
--storing description
declare @Description varchar(100)
select @Description = 'table updated with ID = ' + @ID
insert into Auditing(LastChangeOn, Description)
values (@LastChangeOn, @Description)



drop trigger T_DepartmentInsert
drop trigger T_DepartmentDelete
drop trigger T_DepartmentUpdate
drop trigger T_StudentInsert
drop trigger T_StudentUpdated
drop trigger T_StudentDelete

insert into t_student(ID, name, dept_name, tot_cred)
values('1234', 'Ali', 'C', 17)

insert into t_department(dept_name, building, budget)
values('F', 'BuildingF', 13000)

delete from t_department where dept_name = 'D'

update t_student set dept_name = 'C' where ID = '5443'

select * from t_student
select * from t_department
select * from Auditing

truncate table Auditing