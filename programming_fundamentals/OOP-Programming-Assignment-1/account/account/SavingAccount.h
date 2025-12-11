
class SavingAccount:public Account
{
protected:
	double interestRate;
public:
	SavingAccount(double bal, double rate);
	double calculateInterest();


};
SavingAccount::SavingAccount(double bal, double rate)
	:Account(bal)
{
	interestRate=rate;
}
double SavingAccount::calculateInterest()
{
	return balance*interestRate;
}
