#include<iostream>
#include<cstdlib>
#include"func1.h"
#include"func2.h"
#include"func3.h"
using namespace std;
int main(int argc, char *arg[]){
int size=argc-1;
int *arr=new int[size];
for(int i=0;i<size;i++){
arr[i]=atoi(arg[i+1]);
}
func1(size,arr);
func2(size,arr);
func3(size,arr);
return 0;
}
