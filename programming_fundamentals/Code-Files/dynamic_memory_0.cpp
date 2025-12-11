MEMORY ALLOCATION

// Static allocation
int number = 88;
int * p1 = &number;  // Assign a "valid" address into pointer
 
// Dynamic Allocation
int * p2;            // Not initialize, points to somewhere which is invalid
cout << p2 << endl; // Print address before allocation
p2 = new int;       // Dynamically allocate an int and assign its address to pointer
                    // The pointer gets a valid address with memory allocated
*p2 = 99;
cout << p2 << endl;  // Print address after allocation
cout << *p2 << endl; // Print value point-to
delete p2;           // Remove the dynamically allocated storage

// use an initializer to initialize a fundamental type (such as int, double)
int * p1 = new int(88);
double * p2 = new double(1.23);
 
// C++11 brace initialization syntax
int * p1 = new int {88};
double * p2 = new double {1.23};
