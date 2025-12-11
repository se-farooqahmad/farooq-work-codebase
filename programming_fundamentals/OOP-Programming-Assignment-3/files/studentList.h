#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "Student.h"
#include "Maths.h"
#include "English.h"
#include "History.h"
#include <iostream>
#include <iomanip>

class StudentList
{
private:
	int size;
	int tt;
	Student **list= new Student*[tt];
	int index;

public:
	StudentList(int sz){
		index = 0;
		size = 0;
		tt = sz;
	}

	
	void setStudent(Student* st) {
		list[index] = st;
		index++;
	}//End of setStudent

	void importFile() {
		
		string filename;
		
		ifstream in;
		cout << "Enter filename: ";
		cin >> filename;
		in.open(filename);
		

		if (in.fail()) {
			cout << "Invalid File No Data Imported " <<endl;
			return;
		}
		

		int loc,temp;
		string line, fname, lname, course,gb;

		in >> temp;
		size = size + temp;
		while (!in.eof())
		{
			string temp = "";
			lname = "";
			while(1){
				in >> temp;
				lname = lname.append(temp);
				lname = lname.append(" ");
				if (temp.find(',') != -1)
					break;
			}
			lname.resize(lname.length() - 2);
		
			getline(in, gb, ' ');
			getline(in, fname);

			in >> course;
		
			if (course == "Math" || course == "math") {
				Maths <double>* m = new Maths<double>;
				m->setParamters(fname, lname, course);
				m->setTranscript(in);
				setStudent(m);
			}
			else if (course == "English" || course == "english") {
				English <int>* e = new English<int>;
				e->setParamters(fname, lname, course);
				e->setTranscript(in);
				setStudent(e);
			}
			else if (course == "History" || course == "history") {
				History <int>* h = new History<int>;
				h->setParamters(fname, lname, course);
				h->setTranscript(in);
				setStudent(h);
			}
		}
	}// End of importStudent

	void showList() {
		cout<<endl << setw(20) << left<< "Last" << setw(20) << left << "First" << setw(20) << left << "Course"<<endl<<endl;
		for (int i = 0; i < size; i++) {
			cout << setw(20) << left << list[i]->getFirstName();
			cout << setw(20) << left << list[i]->getLastName();
			cout << setw(20) << left << list[i]->getCourseName();
			cout << endl;
		}
		
	}//End of showList

	void exportList() {

		string course[] = { "English", "History", "Math" };

		cout << endl << endl << "STUDENT GRADE SUMMARY" << endl << endl;
		for (int i = 0; i < 3; i++) {
			cout << endl << course[i] << " CLASS" << endl << endl;
			cout << setw(40) << left << "STUDENT" << setw(7) << left << "FINAL" << setw(7) << left << "FINAL" << setw(7) << left << "LETTER" << endl;
			cout << setw(40) << left << "NAME" << setw(7) << left << "EXAM" << setw(7) << left << "AVG" << setw(7) << left << "GRADE" << endl ;
			cout << "-----------------------------------------------------------------------------"<<endl;

			for (int j = 0; j < size; j++) {
				if (list[j]->getCourseName()==course[i]) {
					cout << setw(40) << left << list[j]->getFirstName()+" "+list[j]->getLastName()
						<< setw(7) << left << list[j]->getFinalExamMarks() << setw(7) << left <<setprecision(4)<< list[j]->calFinalAvg() 
						<< setw(7) << left << list[j]->calLetterGrade() << endl;
				}
			}
			cout << endl;
		}
		

		cout << endl << endl << "OVERALL GRADE DISTRIBUTION" << endl << endl;
		for (int i = 0; i < 6; i++) {
			cout << char(65+i)<<" : ";
			cout << gradeDistribution(65+i);
			cout << endl;
		}

	}//End of exportList

	int gradeDistribution(char grade) {

		int gc = 0;
		for (int i = 0; i < size; i++) {
			if (toupper(list[i]->calLetterGrade()) == grade)
				gc++;
		}
		return gc;
	}//End of gradeDistribution

	~StudentList() {
		delete []list;
		delete list;
		delete list;

	}

};
#endif