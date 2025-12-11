#include <iostream>
#include <iomanip>
#include "CommissionEmployee.h" // CommissionEmployee class definition

using namespace std;

int main() {
    // Set floating-point output formatting
    cout << fixed << setprecision(2);

    // Instantiate a CommissionEmployee object
    CommissionEmployee employee(
        "Sue", "Jones", "222-22-2222", 10000, 0.06
    );

    // Get commission employee data
    cout << "Employee information obtained by get functions:\n"
         << "\nFirst name is " << employee.getFirstName()
         << "\nLast name is " << employee.getLastName()
         << "\nSocial security number is " << employee.getSocialSecurityNumber()
         << "\nGross sales is " << employee.getGrossSales()
         << "\nCommission rate is " << employee.getCommissionRate() << endl;

    // Update employee data
    employee.setGrossSales(8000);     // Set gross sales
    employee.setCommissionRate(0.1);  // Set commission rate

    // Display updated employee information
    cout << "\nUpdated employee information output by print function:\n" << endl;
    employee.print(); // Display the new employee information

    // Display the employee's earnings
    cout << "\nEmployee's earnings: $" << employee.earnings() << endl;

    return 0;
}
