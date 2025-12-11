#include<iostream>
#include"func3.h"
using namespace std;
void func3(int size, int arr[]){
for(int i=0;i<size;i++){
if((arr[i]%2)!=0){
arr[i]=arr[i]+1;
}
}
cout<<"Updated Array is "<<endl;
for(int i=0;i<size;i++){
cout<<arr[i]<<" ";
}
cout<<endl;
}
