# Airline Management System

A comprehensive web-based airline management system for handling flight bookings, passenger management, pilot assignments, and aircraft operations. The system includes both administrator and passenger interfaces.

## Project Overview

This project is a full-stack airline management system with:
- **Database Backend**: SQL Server database for managing flights, passengers, bookings, pilots, and aircraft
- **Frontend**: Interactive web interface for passenger bookings and administrator management
- **Features**: Flight scheduling, passenger management, class-based bookings, seating arrangements, and meal service

## Project Structure

```
Airline Management System/
├── backend/
│   ├── AMS.sql                 # Database schema and tables
│   └── requirements.txt         # Python dependencies (if needed)
├── frontend/
│   ├── index.html              # Home/Landing page
│   ├── passenger.html          # Passenger booking interface
│   ├── admin.html              # Administrator interface
│   ├── AMS.html                # Main application page
│   ├── css/                    # Stylesheets
│   ├── js/                     # JavaScript files
│   ├── fonts/                  # Font files
│   ├── img/                    # Images and assets
│   └── airplane.jpg            # Header image
├── .gitignore                  # Git ignore rules
├── README.md                   # This file
├── LICENSE                     # Project license
└── SETUP.md                    # Setup instructions
```

## Database Schema

The system uses the following main tables:

### Core Tables
- **Users**: User registration information
- **Passengers**: Passenger details (name, address, loyalty status)
- **Booking**: Booking records linking passengers to flights and classes
- **Flight**: Flight information (departure, arrival times, pilot, aircraft, meals)

### Supporting Tables
- **Administrator**: Admin accounts and flight assignments
- **Pilot**: Pilot information and experience
- **Aircraft**: Aircraft details and capacity
- **Class**: Ticket classes and available seats
- **PlaneType**: Aircraft type information
- **City**: Destination cities and ticket pricing
- **Meals**: Meal service information

## Setup Instructions

### Prerequisites
- SQL Server (or compatible database)
- Web Server (Apache, IIS, or similar)
- Web Browser (Chrome, Firefox, Edge, Safari)

### Database Setup

1. Open SQL Server Management Studio
2. Create a new database named "Airline Management System"
3. Run the SQL script:
   ```sql
   -- Connect to your SQL Server instance
   CREATE DATABASE [Airline Management System]
   -- Then execute the contents of backend/AMS.sql
   ```
4. Verify all tables are created successfully

### Frontend Setup

1. Copy the `frontend/` folder to your web server's root directory
2. Update database connection strings (if using backend services)
3. Access the application through your web browser:
   - **Home**: `http://localhost/index.html`
   - **Passenger**: `http://localhost/passenger.html`
   - **Admin**: `http://localhost/admin.html`

### Database Tables Details

#### Passengers Table
```sql
CREATE TABLE Passengers (
    Passenger_NO INT PRIMARY KEY,
    PassengerName VARCHAR(30),
    Address_P VARCHAR(100),
    GoldFlg INT,
    Magazine VARCHAR(30),
    SilverFlg INT,
    Seatingarrangement VARCHAR(30)
)
```

#### Booking Table
```sql
CREATE TABLE Booking (
    BookingID INT PRIMARY KEY,
    Passno INT,
    classid INT,
    Flightno INT,
    FOREIGN KEY(Passno) REFERENCES Passengers(Passenger_NO),
    FOREIGN KEY(classid) REFERENCES Class(Class_ID),
    FOREIGN KEY(Flightno) REFERENCES Flight(FlightNO)
)
```

#### Flight Table
```sql
CREATE TABLE Flight (
    FlightNO INT PRIMARY KEY,
    pilotid VARCHAR(30),
    aircraft_id VARCHAR(10),
    meals_id INT,
    Arrival_time TIME,
    Departure_time TIME,
    FOREIGN KEY(pilotid) REFERENCES Pilot(Pilot_ID),
    FOREIGN KEY(aircraft_id) REFERENCES Aircraft(Aircraft_ID),
    FOREIGN KEY(meals_id) REFERENCES Meals(Meal_ID)
)
```

## Features

### Passenger Features
- Browse available flights
- Book seats in different classes (Economy, Business, First Class)
- View seating arrangements
- Manage passenger profile (Gold/Silver membership)
- Subscribe to magazine
- View booking history

### Administrator Features
- Manage flights and schedules
- Assign pilots to flights
- Monitor bookings
- Manage aircraft and capacity
- Update class availability
- Configure meal services

## Tech Stack

### Backend
- **Database**: SQL Server
- **Server**: Windows/Apache/IIS

### Frontend
- **HTML5**: Page structure
- **CSS3**: Styling and layout
- **JavaScript**: Interactivity
- **Bootstrap 5**: Responsive design framework

## Key Relationships

- Each **Flight** is operated by one **Pilot** and uses one **Aircraft**
- Each **Aircraft** belongs to one **PlaneType**
- Each **Pilot** is trained on one **PlaneType**
- Each **Booking** links a **Passenger** to a **Flight** and **Class**
- Each **Flight** offers multiple **Classes** with different seat availability
- Each **Flight** has **Meals** service configuration

## Files Included

### Documentation
- `Final Version.docx` - Final project documentation
- `(4402_4407_4498)Project phase1.doc` - Phase 1 requirements
- `(4498_4407_4402)Project phase2.doc` - Phase 2 specifications
- `Tableprojpt2.docx` - Table documentation

### Database
- `backend/AMS.sql` - Complete database schema

### Frontend
- `frontend/index.html` - Home page
- `frontend/passenger.html` - Passenger interface
- `frontend/admin.html` - Admin interface
- `frontend/AMS.html` - Main application
- `frontend/css/` - Stylesheets
- `frontend/js/` - JavaScript functions
- `frontend/fonts/` - Font resources
- `frontend/img/` - Images and assets

## Usage

1. **For Passengers**:
   - Navigate to `passenger.html`
   - Enter your passenger details
   - Select a flight and class
   - Complete the booking

2. **For Administrators**:
   - Navigate to `admin.html`
   - Login with admin credentials
   - Manage flights, pilots, and aircraft
   - Monitor bookings and seat availability

## Future Enhancements

- Payment integration
- Online check-in system
- Mobile application
- Real-time flight tracking
- Email notification system
- Advanced reporting and analytics
- Multi-language support
- Baggage management system

## Notes

- Ensure all foreign key relationships are maintained when managing data
- Backup the database regularly
- Update SQL Server credentials as needed
- Clear browser cache if interface updates don't appear

## Authors

Farooq Ahmad and Team

## License

This project is for educational purposes.

## Contact

For questions or support, please contact: se.farooqahmad@gmail.com
