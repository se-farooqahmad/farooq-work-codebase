/* Function to compute the sum of a range of an array (SumArrayRange.cpp) */
#include <iostream>
using namespace std;
 
// Function prototype
int sum(const int *begin, const int *end);
 
// Test Driver
int main() {
   int a[] = {8, 4, 5, 3, 2, 1, 4, 8};
   cout << sum(a, a+8) << endl;        
   cout << sum(a+2, a+5) << endl;      
   cout << sum(&a[2], &a[5]) << endl;  
   return 0;
}
 
// Function definition
// Return the sum of the given array 
int sum(const int *begin, const int *end) {
   int sum = 0;
   for (const int *p = begin; p != end; ++p) {
      sum += *p;
   }
   return sum;
}
