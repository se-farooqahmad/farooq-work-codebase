#include <iostream>
#include <iomanip>
//#include <stdexcept>
//#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h" // CommissionEmployee class definition
using namespace std;

BasePlusCommissionEmployee::BasePlusCommissionEmployee(CommissionEmployee emp, double salary )
	:EMPP(emp)

{
	setBaseSalary(salary);
} 
void BasePlusCommissionEmployee::setBaseSalary(double salary)
{
	if (salary>0.0)
	{
		baseSalary = salary;
	}
	else 
		throw invalid_argument("salary must be >= 0.0");

}
double BasePlusCommissionEmployee::getBaseSalary()
{
	return baseSalary;
}
double BasePlusCommissionEmployee::earnings()

{
	return EMPP.earnings();
}
void BasePlusCommissionEmployee::print()
{
	EMPP.print();
	cout<<"\nbase salary"<<baseSalary<<endl;
}

int main()
{
	CommissionEmployee bpce("James", "Sue", "19980510", 1000, 0.25);
BasePlusCommissionEmployee employee(bpce, 2500);
employee.print();
 cout << "\n\nEmployee's earnings: $" << employee.earnings() << endl;
 } // end main
