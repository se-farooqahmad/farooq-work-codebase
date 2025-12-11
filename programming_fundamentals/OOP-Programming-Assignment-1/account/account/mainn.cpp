#include <iostream>

using namespace std;

#include "Account.h"
#include "SavingAccount.h"
#include "CheckingAccount.h"
void main()
{
	
	SavingAccount acc(1100,0.2);
	cout<<"Saving Account . . ."<<endl;
	cout<<"Your Curent Balance is : "<<acc.getBalance()<<endl;
	acc.credit(100);
	cout<<"After the addition of credit, the New Balance is : "<< acc.getBalance()<<endl;
	acc.debit(300);
	cout<<"After the withdrawal of debit,, the New Balance is : "<< acc.getBalance()<<endl;
	cout<<"Interest is : "<<acc.calculateInterest()<<endl;

	cout<<"Adding intrest to my account"<<endl;
	acc.credit(acc.calculateInterest());
	cout<<"Your Updated Balance is : "<<acc.getBalance()<<endl;



	CheckingAccount ac(1000,150);
	cout<<"Checking Account . . ."<<endl;
	cout<<"Your Curent Balance is : "<<ac.getBalance()<<endl;
	ac.credit(500);
	cout<<"After the addition of credit, the New Balance is : "<< ac.getBalance()<<endl;
	ac.debit(250);
	cout<<"After the withdrawal of debit,, the New Balance is : "<< ac.getBalance()<<endl;
	

}