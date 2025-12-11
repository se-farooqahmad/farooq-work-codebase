//ITERATIVE
#include <iostream>
using namespace std;
int main()
{
	int fact = 1;
	int n;
	cin >> n;
	for(int i = n ; i > 0 ; i--)
	{
		fact = fact * i;
	}
	cout << fact;
	system ("pause");
	return 0;
}