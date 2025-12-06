#include<iostream>
using namespace std;
int main()
{
    int marks;
    cout<<"Enter Marks: ";
    cin>>marks;
    if (marks>=90 && marks<=100)
        cout<<"Grade: A*";
    else if (marks >=80 && marks<90)
        cout<<"Grade: A";
    else if (marks >=70 && marks<80)
        cout<<"Grade: B";
    else if (marks >=60 && marks<70)
        cout<<"Grade: C";
    else if (marks >=50 && marks<60)
        cout<<"Grade: D";
    else if (marks>=0 && marks<50)
        cout<<"Gradu: U";
    else cout<<"invalid Marks";
}