#include <iostream>
using namespace std;
class employee
{
private:
	int id;
	float salary;
public:
	employee(int i, float s)
	{ id=i, salary = s; }
	virtual float calculateSalary()
	{
		return salary;
	}
	int getID()
	{
		return id;
	}
	float getSalary()
	{ 
		return salary;
	}
	
};
class commissionedEmployee : public employee
{
private:
	float sa;
	float rate;
public:
	commissionedEmployee(int i, float s, float a, float r):employee (i,s)
		{ 
			sa =a, rate = r;
		}
	float calculateSalary()
	{
		return sa*(rate/100)+getSalary();
	}
};
class hourlyEmployee : public employee
{
private:
	int ehour;
	float pphour;
public:
	hourlyEmployee(int i, float s, float eh, float pph):employee (i,s)
	{
		ehour = eh, pphour = pph;
	}
	float calculateSalary()
	{
		return getSalary()+pphour*ehour;
	}
};
class regularEmployee : public employee
{
private:
	int bonus;
public:
	regularEmployee(int i, float s, float b):employee (i,s)
	{
		bonus = b;
	}
	float calculateSalary()
	{
		return getSalary()+bonus;
	}
};

int main()
{
commissionedEmployee E1(25, 5000, 1000, 10);
// CASE 1 - derived Class Pointer pointing to Derived class object
commissionedEmployee * ptr;
ptr = &E1;
cout<<" Commissioned Employee salary:"<<ptr->calculateSalary();
cout<<endl;
// CASE 2 - Base Class Pointer pointing to Derived class object
employee * eptr;
eptr = &E1;
cout<<" Commissioned Employee salary:"<<eptr->calculateSalary();
cout<<endl;
commissionedEmployee E2 (25, 5000, 1000, 10);
commissionedEmployee E3 (26, 5000, 2000, 10);
hourlyEmployee H1(27, 5000, 10, 100 );
hourlyEmployee H2(28, 5000, 5, 100 );
regularEmployee R1(29, 5000, 1000 );
regularEmployee R2(29, 5000, 2000 );
employee * list [6];
list[0] = & E2;
list[1] = & E3;
list[2] = & H1;
list[3] = & H2;
list[4] = & R1;
list[5] = & R2;
for(int i = 0 ; i < 6; i++)
{
cout<<"Employee "<<i<<" salary is : "<<list[i]->calculateSalary();
cout<<endl;
}
return 0;
}