#include<iostream>
#include"func1.h"
using namespace std;
void func1(int size, int arr[]){
int count=0;
for(int i=0;i<size;i++){
if((arr[i]%2)!=0){
count++;
}
}
cout<<"Number of Odd elements are "<<count<<endl;
}
