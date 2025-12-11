
class CheckingAccount:public Account
{
private:
	double charge;
public:
	CheckingAccount(double bal, double chr);
	void setCharge(double chr);
	double getCharge();
	void credit(double amount);
	void debit(double amount);
};
CheckingAccount::CheckingAccount(double bal, double chr)
	:Account(bal)
{
	setCharge(chr);
}
void CheckingAccount::setCharge(double chr)
{
	charge = chr;
}
double CheckingAccount::getCharge()
{
	return charge;
}
void CheckingAccount::credit(double amount)
{
	balance = (balance+amount)-charge;
}
void CheckingAccount::debit(double amount)
{
	
	if ( (amount +charge )< balance)
	{
		balance = (balance - amount)-charge;
	}
	else	
		cout<<"Debit Amount Exceeded Account Balance";
}
