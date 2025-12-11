#include <iostream>
#include <fstream>
#include<string>
#include "Maths.h"
#include "English.h"
#include "History.h"
#include "StudentList.h"


using namespace std;

void printMenue();
StudentList sl(10);

void main()
{
	
	char input = ' ';
	printMenue();

	while (tolower(input)!='q') {
		cout << "Enter Option From Menue :";
		cin >> input;
		switch (tolower(input)) {
			case 'i':
				sl.importFile();
				break;
			case 's':
				sl.showList();
				break;
			case 'e':
				sl.exportList();
				break;
			case 'm':
				printMenue();
				break;
			case 'q':
				break;
			default:
				cout << "Invalid Option" << endl;
		}
		
	}
}

void printMenue() {
	cout << "*** Student List menu ***"<<endl;
	cout << "I Import students from a file"<<endl;
	cout << "S Show student list(brief)"<<endl;
	cout << "E Export a grade report(to file)"<<endl;
	cout << "M Show this Menu"<<endl;
	cout << "Q Quit Program"<<endl;
}
