//4.2  Pointer Arithmetic
int numbers[] = {11, 22, 33};
int * iPtr = numbers;
cout << iPtr << endl;        // 0x22cd30
cout << iPtr + 1 << endl;    // 0x22cd34 (increase by 4 - sizeof int)
cout << *iPtr << endl;       // 11
cout << *(iPtr + 1) << endl; // 22 
cout << *iPtr + 1 << endl;   // 12

//sizeof operator
