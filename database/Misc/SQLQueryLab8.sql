

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
 select * from TriggerEmployee

CREATE	TRIGGER Trigger_ForUpdate
ON		TriggerEmployee
FOR		UPDATE
AS 
UPDATE TriggerEmployee
SET Description = 'changed with For update trigger'
WHERE EmployeeID= 1

UPDATE TriggerEmployee
SET Name = 'New Name'
WHERE EmployeeID= 4

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
select * from TriggerEmployee

go
UPDATE TriggerEmployee
SET Name = 'New Name'
WHERE EmployeeID= 2
go

select *from  TriggerEmployee
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
ON	DatabASE
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

go




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


create table Auditing
(
AuditID int identity(1,1) primary key,
LastChangeOn date null,
)
drop table Auditing
drop trigger departmentTrigger
drop trigger studentTrigger

create trigger studentTrigger 
on t_student
for insert,update, delete
as 
--declare @LastChangeON date
--select @LastChangeON = convert(varchar(10), getdate(),101)
insert into Auditing(LastChangeOn) values(GETDATE())
--values (@LastChangeON)
--insert into t_student values (4407,'Farooq','EE',21)
create trigger departmentTrigger 
on t_department
for insert,update, delete
as 
--declare @LastChangeON date
--select @LastChangeON = convert(varchar(10), getdate(),101)
insert into Auditing(LastChangeOn) values (GETDATE())
--values (count(*),@LastChangeON)


insert into t_department(dept_name, building, budget)
values('CS', 'CSdept', 150000)

select * from t_department
select * from auditing

insert into t_student values (4402,'Altamash','EE',19)
select * from t_student
select * from t_department
select * from auditing

alter table auditing 
add description varchar(50)

alter trigger studentTrigger
on t_student
for insert,update
as
declare @dept varchar(50)
select @dept = dept_name from inserted 
insert into Auditing(LastChangeON,description) 
values (GETDATE(),'table updated with dep_name='+ @dept)

insert into t_department values('CE', 'Civil_dept', 125000)
select * from t_department
select * from auditing
delete from t_department where dept_name = 'CE'
delete from auditing where auditID = '3'
insert into t_student values (4498,'Nayab','EE',24)
select * from t_student
select * from auditing

alter trigger studentTrigger
on t_student
for delete
as
declare @dept varchar(50)
select @dept = dept_name from deleted 
insert into Auditing(LastChangeON,description) 
values (GETDATE(),'table deleted with dep_name='+ @dept)

delete from t_student where ID = '4498'
select * from t_student
select * from auditing

alter trigger departmentTrigger
on t_department
for insert,update
as
declare @dept varchar(50)
select @dept = dept_name from inserted 
insert into Auditing(LastChangeON,description) 
values (GETDATE(),'table updated with dep_name='+ @dept)

insert into t_department values('CE', 'Civil_dept', 125000)
select * from t_department
select * from auditing


alter trigger departmentTrigger
on t_department
for delete
as
declare @dept varchar(50)
select @dept = dept_name from deleted
insert into Auditing(LastChangeON,description) 
values (GETDATE(),'table deleted with dep_name='+ @dept)

delete from t_department where dept_name = 'CS'
select * from t_department
select * from auditing