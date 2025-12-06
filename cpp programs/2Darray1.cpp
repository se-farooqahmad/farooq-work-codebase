#include<iostream>
using namespace std;
int sumCalculator(int arr[][10])
{
    int max_sum = 0;
    int max_col = 0;
    for (int j = 0; j < 10; j++) {
        int col_sum = 0;
        for (int i = 0; i < 10; i++) {
            col_sum += arr[i][j];
        }
        if (col_sum > max_sum) {
            max_sum = col_sum;
            max_col = j;
        }
    }
    return max_col;
}
int main()
{
    int arr[10][10];
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            arr[i][j]=rand()%900+100;
        }
    }
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Column with the largest index is : "<<sumCalculator(arr);
}