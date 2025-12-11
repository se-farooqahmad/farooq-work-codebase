use [Airline Management System]

create table Users
(
reg_no varchar(30) primary key
)

create table Passengers
(
Passenger_NO int primary key,
PassengerName varchar(30),
Address_P varchar(100),
GoldFlg   int,
Magazine  varchar(30),
SilverFlg int,
Seatingarrangement varchar(30)
)

create table Booking
(
BookingID int primary key,
Passno int,
classid int ,
Flightno int 
)
alter table Booking add constraint bookingPassnoFK foreign key(Passno) references Passengers(Passenger_NO)

create table Class
(
Class_ID int primary key,
classType varchar(30),
seats_available int
)

alter table Booking add constraint bookingclassidFK foreign key(classid) references Class(Class_ID)

create table Administrator
(
Email_ID varchar(80) primary key ,
Password_A varchar(20),
flightno_A int
)
create table Flight
(
FlightNO int primary key,
pilotid varchar(30) ,
aircraft_id varchar(10) ,
meals_id int,
Arrival_time time,
Departure_time time,
)

alter table Booking add constraint bookingflightnoFK foreign key(Flightno) references Flight(FlightNO)
alter table Administrator add constraint adminflightnoFK foreign key(flightno_A) references Flight(FlightNO)


create table Pilot
(
Pilot_ID varchar(30) primary key,
Pilot_Name varchar(30),
Experience int,
Pilot_Age int,
planetypeNo varchar(30) 
)

alter table Flight add constraint FlightpilottidFK foreign key(pilotid) references Pilot(Pilot_ID)


create table PlaneType
(
PlaneType_No varchar(30) primary key,
PlaneTypeName varchar(30) 
)

alter table Pilot add constraint PilotplanetypetFK foreign key(planetypeNo) references PlaneType(PlaneType_No)

create table Aircraft
(
Aircraft_ID varchar(10) primary key,
no_of_seats int,
planetypeno varchar(30) 
)
alter table Flight add constraint FlightaircraftidFK foreign key(aircraft_id) references Aircraft(Aircraft_ID)
alter table Aircraft add constraint ACplanetypetFK foreign key(planetypeNo) references PlaneType(PlaneType_No)----------
create table City
(
CityID int primary key,
Distance float,
CityName varchar(30),
TicketPrice float,
)
create table Meals
(
Meal_ID int primary key,
no_of_dishes int,
no_of_drinks int,
)

alter table Flight add constraint FlightmealsidFK foreign key(meals_id) references Meals(Meal_ID)







--alter table Booking add constraint bookingPassnoFK foreign key(Passno) references Passenger(Passenger_NO)
--alter table Booking add constraint bookingclassidFK foreign key(classid) references Class(Class_ID)
--alter table Booking add constraint bookingflightnoFK foreign key(Flightno) references Flight(FlightNO)
--alter table Administrator add constraint adminflightnoFK foreign key(Flightno) references Flight(FlightNO)
--alter table Flight add constraint FlightpilottidFK foreign key(pilotid) references Pilot(Pilot_ID)
--alter table Pilot add constraint PilotplanetypetFK foreign key(planetypeNo) references PlaneType(PlaneType_No)
--alter table Flight add constraint FlightaircraftidFK foreign key(aircraft_id) references Aircraft(Aircraft_ID)
--alter table Aircraft add constraint ACplanetypetFK foreign key(planetypeNo) references PlaneType(PlaneType_No)
--alter table Flight add constraint FlightmealsidFK foreign key(meals_id) references Meals(Meal_ID)

--alter table Arrival add constraint arrivalflightnoFK foreign key(Arrival_flightno) references Flight(FlightNO)
--alter table Departure add constraint departureflightnoFK foreign key(Departure_flightno) references Flight(FlightNO)
--alter table Departure add constraint depcityIdFK foreign key(Departure_cityid) references City(CityID)
--alter table Arrival add constraint arrivalcityidFK foreign key(Arrival_cityid) references City(CityID)
