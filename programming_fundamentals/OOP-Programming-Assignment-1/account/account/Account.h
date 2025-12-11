

class Account
{
protected:
	double balance;
public:
	Account(double bal);
	void setBalance(double bal);
	double getBalance();
	void credit(double amount);
	void debit(double amount);
};


Account::Account(double bal)
{
	setBalance(bal);
}
void Account::setBalance(double bal)
{
	if(bal >= 0.0)
	{
		balance = bal;
	}
	else 
		cout<< " The initial balance was invalid";
}
void Account::credit(double amount)
{
	balance = balance + amount;
}
void Account::debit(double amount)
{
	if ( amount < balance)
	{
		balance = balance - amount;
	}
	else	
		cout<<"Debit Amount Exceeded Account Balance";
}
double Account::getBalance()
{
	return balance;
}