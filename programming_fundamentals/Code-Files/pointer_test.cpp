/* Test pointer declaration and initialization (TestPointerInit.cpp) */
#include <iostream>
using namespace std;
 
int main() {
   int number = 88;    // Declare an int variable and assign an initial value
   int * pNumber=NULL;      // Declare a pointer variable pointing to an int (or int pointer)
   pNumber = &number;  // assign the address of the variable number to pointer pNumber
 
   cout << pNumber << endl;  // Print content of pNumber 
   cout << &number << endl;  // Print address of number 
   cout << *pNumber << endl; // Print value pointed to by pNumber 
   cout << number << endl;   // Print value of number 
 
   *pNumber = 99;            // Re-assign value pointed to by pNumber
   cout << pNumber << endl;  // Print content of pNumber 
   cout << &number << endl;  // Print address of number 
   cout << *pNumber << endl; // Print value pointed to by pNumber 
   cout << number << endl;   // Print value of number 
                             // The value of number changes via pointer
 
   cout << &pNumber << endl; // Print the address of pointer variable pNumber 
   
   return 0;
}
