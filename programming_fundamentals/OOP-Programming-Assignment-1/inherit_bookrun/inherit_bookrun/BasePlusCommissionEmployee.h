#ifndef BASEPLUS_H
#define BASEPLUS_H
#include "CommissionEmployee.h"
class BasePlusCommissionEmployee
{
private:

	double baseSalary;
	 CommissionEmployee EMPP;
	public:

		BasePlusCommissionEmployee( CommissionEmployee  ,double);
		void setBaseSalary(double);
		double getBaseSalary();
		double earnings();
		void print ();
};
#endif
