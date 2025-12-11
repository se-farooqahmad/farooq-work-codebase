#ifndef COMMISSION_H
#define COMMISSION_H

#include <string> // C++ standard string class
using namespace std;

class CommissionEmployee
{
	public:
		 CommissionEmployee( const string &, const string &, const string &,
		 double = 0.0, double = 0.0 );

		 void setFirstName( const string & ); // set first name
		 string getFirstName() const; // return first name

		 void setLastName( const string & ); // set last name
		 string getLastName() const; // return last name

		 void setSocialSecurityNumber( const string & ); // set SSN
		 string getSocialSecurityNumber() const; // return SSN

		 void setGrossSales( double ); // set gross sales amount
		 double getGrossSales() const; // return gross sales amount

		 void setCommissionRate( double ); // set commission rate
		 double getCommissionRate() const; // return commission rate

		 double earnings() const; // calculate earnings
		 void print() const; // print CommissionEmployee object
	protected:
		string firstName;
		string lastName;
		string socialSecurityNumber;	
		double grossSales; // gross weekly sales
		double commissionRate; // commission percentage
};
CommissionEmployee::CommissionEmployee(
const string &first, const string &last, const string &ssn,double sales, double rate )
{
	firstName = first; 
	lastName = last; 
	socialSecurityNumber = ssn; 
	setGrossSales( sales ); 
	setCommissionRate( rate ); 
} 
// set first name
void CommissionEmployee::setFirstName( const string &first )
{
	firstName = first; 
} 

 // return first name
string CommissionEmployee::getFirstName() const
{
	return firstName;
}

 // set last name
void CommissionEmployee::setLastName( const string &last )
{
	lastName = last;
}

 // return last name
string CommissionEmployee::getLastName() const
{
	return lastName;
} 

 // set social security number
void CommissionEmployee::setSocialSecurityNumber( const string &ssn )
{
	socialSecurityNumber = ssn;
} 

 // return social security number
string CommissionEmployee::getSocialSecurityNumber() const
{
	return socialSecurityNumber;
} 

 // set gross sales amount
void CommissionEmployee::setGrossSales( double sales )
{
	if ( sales >= 0.0 )
		grossSales = sales;
	else
		throw invalid_argument( "Gross sales must be >= 0.0" );
} 

 // return gross sales amount
double CommissionEmployee::getGrossSales() const
{
	return grossSales;
} 

 // set commission rate
void CommissionEmployee::setCommissionRate( double rate )
{
	if ( rate > 0.0 && rate < 1.0 )
		commissionRate = rate;
	else
		throw invalid_argument( "Commission rate must be > 0.0 and < 1.0" );
} 

 // return commission rate
double CommissionEmployee::getCommissionRate() const
{
	return commissionRate;
}

// calculate earnings
double CommissionEmployee::earnings() const
{
	return commissionRate * grossSales;
}

// print CommissionEmployee object
void CommissionEmployee::print() const
{
	cout << "commission employee: " << firstName << ' ' << lastName
	<< "\nsocial security number: " << socialSecurityNumber
	<< "\ngross sales: " << grossSales
	<< "\ncommission rate: " << commissionRate;
}

#endif