#include<iostream>
#include"func2.h"
using namespace std;
void func2(int size, int arr[]){
int count=0;
for(int i=0;i<size;i++){
if((arr[i]%2)==0){
count++;
}
}
cout<<"Number of Even elements are "<<count<<endl;
}
