Use Lab10ex2
go

--Create table
Create table items
(ItemNo int,
ItemName varchar(15),
TotalUnits int
)
go

--insert values
insert into items
values
(1, 'Soap' , 10 )
insert into items
values
(2,'Handwash', 20)
insert into items
values
(3,'Shampoo',5)
go

Insert into items
values(4, 'Sanitizer', 3)


--This procedure takes the name of item input as parameter 
--Output Found 1 if item is found , 0 if not found 
--Result set contains the Row of Item with that Item Name

create procedure SearchItem
@itemName varchar(15),
@Found int output

/*declare @F int
exec 
searchitem 'soap',@found=@F output

select @f*/
AS
SELect * from items where itemName=@itemName

if @@ROWCOUNT>0 --item found
set @Found=1
else 
set @Found=0


create procedure SearchItemGreaterThan5
@itemName varchar(15),
@Found int output

/*declare @F int
exec 
searchitem 'soap',@found=@F output

select @f*/
AS
SELect * from items where (itemName=@itemName) and (TotalUnits > 5)

if @@ROWCOUNT>0 --item found
set @Found=1
else 
set @Found=0

select * from items

drop procedure SearchItemGreaterThan5

Create PROCEDURE [dbo].[deleteItem] 
	@ID int
AS
BEGIN
	SET NOCOUNT ON;

DELETE FROM Items WHERE ItemNo = @ID
END

CREATE PROCEDURE [dbo].[UpdateItem] 
	@itemNo int,	@itemname varchar(100), @totalUnits int
AS
BEGIN	SET NOCOUNT ON;
Update items set ItemName=@itemname, TotalUnits=@totalUnits 
where ItemNo=@itemno;
END

CREATE PROCEDURE [dbo].[InsertItem] 
	@itemNo int,
	@itemname varchar(100),
	@totalUnits int
AS
BEGIN
	SET NOCOUNT ON;
insert into items values(@itemno, @itemname, @totalUnits );
END