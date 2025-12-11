# Setup Instructions for Airline Management System

## Prerequisites

Before setting up the project, ensure you have:

1. **SQL Server** (SQL Server 2016 or later)
   - Download from: https://www.microsoft.com/en-us/sql-server/sql-server-downloads
   - Installation Guide: https://docs.microsoft.com/en-us/sql/database-engine/install-windows/install-sql-server

2. **SQL Server Management Studio (SSMS)**
   - Download from: https://docs.microsoft.com/en-us/sql/ssms/download-sql-server-management-studio-ssms

3. **Web Server** (IIS, Apache, or built-in)
   - Windows: IIS comes with Windows Pro/Enterprise editions
   - Alternative: Use any web server that serves static files

4. **Web Browser**
   - Chrome, Firefox, Edge, or Safari (latest version)

## Step-by-Step Setup

### 1. Database Setup

#### Option A: Using SQL Server Management Studio (GUI)

1. Open **SQL Server Management Studio**
2. Connect to your SQL Server instance
3. Right-click on **Databases** → Select **New Database**
4. Enter database name: `Airline Management System`
5. Click **OK**
6. In Object Explorer, expand the new database
7. Right-click on the database → **New Query**
8. Copy and paste the entire content from `backend/AMS.sql`
9. Click **Execute** (or press F5)
10. Verify all tables are created:
    - Users
    - Passengers
    - Booking
    - Class
    - Administrator
    - Flight
    - Pilot
    - PlaneType
    - Aircraft
    - City
    - Meals

#### Option B: Using Command Line

```powershell
# Open PowerShell and navigate to backend folder
cd "path\to\Airline Management System\backend"

# Connect to SQL Server and execute the script
sqlcmd -S YOUR_SERVER_NAME -U sa -P YOUR_PASSWORD -i AMS.sql
```

Replace:
- `YOUR_SERVER_NAME`: Your SQL Server instance name (e.g., `DESKTOP-ABC123` or `localhost\SQLEXPRESS`)
- `YOUR_PASSWORD`: Your SQL Server password

### 2. Frontend Setup

#### Option A: Using IIS (Windows)

1. Open **Internet Information Services (IIS) Manager**
2. In the left panel, right-click **Sites** → **Add Website**
3. Enter the following details:
   - **Site name**: `AirlineMS`
   - **Physical path**: `C:\path\to\Airline Management System\frontend`
   - **Host name**: `localhost`
   - **Port**: `80`
4. Click **OK**
5. Open browser and navigate to: `http://localhost/index.html`

#### Option B: Using Local Web Server (Python)

```powershell
cd "path\to\Airline Management System\frontend"

# Python 3.x
python -m http.server 8000

# Then open browser to: http://localhost:8000
```

#### Option C: Using Node.js (http-server)

```powershell
# Install http-server globally (one time)
npm install -g http-server

# Navigate to frontend and start server
cd "path\to\Airline Management System\frontend"
http-server

# Access at: http://localhost:8080
```

### 3. Configure Database Connection (if using backend services)

If you plan to add backend services (PHP, Node.js, ASP.NET):

1. Update connection strings in your backend service
2. Example for SQL Server connection string:
   ```
   Server=YOUR_SERVER_NAME;Database=Airline Management System;User Id=sa;Password=YOUR_PASSWORD;
   ```

### 4. Test the Application

1. **Test Home Page**:
   - Navigate to `http://localhost/index.html`
   - You should see the airline system homepage with navigation buttons

2. **Test Passenger Interface**:
   - Click "Passenger" button or navigate to `http://localhost/passenger.html`
   - Verify the form loads correctly

3. **Test Admin Interface**:
   - Click "Administrator" button or navigate to `http://localhost/admin.html`
   - Verify the admin panel loads

4. **Test Database Connection**:
   - In SSMS, run queries to verify data insertion:
   ```sql
   USE [Airline Management System]
   SELECT COUNT(*) FROM Flight
   SELECT COUNT(*) FROM Passengers
   SELECT COUNT(*) FROM Pilot
   ```

## Troubleshooting

### Database Connection Issues

**Error: "Cannot connect to SQL Server"**
- Verify SQL Server service is running
- Check server name in connection string
- Ensure SQL Server TCP/IP protocol is enabled
  - Open **SQL Server Configuration Manager**
  - Navigate to SQL Server Network Configuration
  - Enable **TCP/IP**

**Error: "Login failed for user 'sa'"**
- Verify username and password
- Check SQL Server authentication mode
  - In SSMS: Right-click Server → Properties → Security
  - Ensure "SQL Server and Windows Authentication mode" is selected

### Frontend Issues

**Error: "Cannot load CSS/JavaScript files"**
- Verify all files are in the correct folders
- Check browser console for 404 errors (F12)
- Ensure relative paths are correct

**Error: "Page not displaying correctly"**
- Clear browser cache (Ctrl+Shift+Delete)
- Disable browser extensions
- Try a different browser

**Port Already in Use**
- If port 80 or 8000 is in use, change to different port:
  ```powershell
  python -m http.server 8080
  ```

### IIS Configuration Issues

**Error: 403 Forbidden**
- Check folder permissions
- Right-click folder → Properties → Security
- Add IIS_IUSRS with Full Control

**Error: Handler not found**
- Ensure appropriate handlers are installed in IIS
- For static files (HTML, CSS, JS): Default handler is sufficient

## File Structure Verification

After setup, verify this structure exists:

```
backend/
├── AMS.sql
└── requirements.txt

frontend/
├── index.html
├── passenger.html
├── admin.html
├── AMS.html
├── css/
│   └── (CSS files)
├── js/
│   └── (JavaScript files)
├── fonts/
│   └── (Font files)
├── img/
│   └── (Image files)
└── airplane.jpg
```

## Sample Data (Optional)

To populate the database with sample data:

```sql
USE [Airline Management System]

-- Insert sample pilots
INSERT INTO Pilot VALUES ('P001', 'John Smith', 15, 45, 'PT001')
INSERT INTO Pilot VALUES ('P002', 'Jane Doe', 20, 50, 'PT001')

-- Insert sample plane types
INSERT INTO PlaneType VALUES ('PT001', 'Boeing 747')
INSERT INTO PlaneType VALUES ('PT002', 'Airbus A380')

-- Insert sample aircraft
INSERT INTO Aircraft VALUES ('A001', 400, 'PT001')
INSERT INTO Aircraft VALUES ('A002', 555, 'PT002')

-- Insert sample classes
INSERT INTO Class VALUES (1, 'Economy', 300)
INSERT INTO Class VALUES (2, 'Business', 80)
INSERT INTO Class VALUES (3, 'First', 20)

-- Insert sample meals
INSERT INTO Meals VALUES (1, 3, 5)
INSERT INTO Meals VALUES (2, 5, 8)

-- Insert sample flight
INSERT INTO Flight VALUES (100, 'P001', 'A001', 1, '10:00:00', '08:00:00')
INSERT INTO Flight VALUES (101, 'P002', 'A002', 2, '14:30:00', '12:00:00')

-- Insert sample passengers
INSERT INTO Passengers VALUES (1, 'Ali Ahmed', '123 Main St', 0, 'Yes', 0, '1A')
INSERT INTO Passengers VALUES (2, 'Sara Khan', '456 Oak Ave', 1, 'No', 1, '2B')

-- Insert sample bookings
INSERT INTO Booking VALUES (1, 1, 1, 100)
INSERT INTO Booking VALUES (2, 2, 2, 101)
```

## Next Steps

1. Add more sample data for testing
2. Implement backend APIs (PHP, Node.js, or ASP.NET)
3. Add database connectivity from frontend forms
4. Implement user authentication
5. Add data validation and error handling
6. Deploy to production server

## Support

For additional help:
- SQL Server Docs: https://docs.microsoft.com/en-us/sql/
- Bootstrap Docs: https://getbootstrap.com/docs/
- Contact: se.farooqahmad@gmail.com
