#ifndef STUDENT_H
#define STUDENT_H


#include <string>
#include <fstream>

using namespace std;

class Student
{
protected:
	string firstName, lastName, courseName;

public:
	Student()
		:firstName(""), lastName(""), courseName("")
	{
	}

	void setParamters(string fn, string ln, string cn)
	{
		firstName = fn;
		lastName = ln;
		courseName = cn;
	}


	string getFirstName() { return firstName; }
	string getLastName() { return lastName; }
	string getCourseName() { return courseName; }
	void setFirstName(string fn) { firstName = fn; }
	void setLastName(string ln) { lastName = ln; }
	void setCourseName(string cn) { courseName = cn; }


	virtual void setTranscript(ifstream& in) {}
	virtual double calFinalAvg() { return 0; }
	virtual int getFinalExamMarks(){ return 0; }

	char calLetterGrade()
	{
		if (calFinalAvg() < 100 && calFinalAvg() >=90)
		{
			return 'A';
		}
		if (calFinalAvg() < 90 && calFinalAvg() >=80)
		{
			return 'B';
		}
		if (calFinalAvg() < 80 && calFinalAvg() >=70)
		{
			return 'C';
		}
		if (calFinalAvg() < 70 && calFinalAvg() >=60)
		{
			return 'D';
		}
		if (calFinalAvg() < 60 && calFinalAvg() >=50)
		{
			return 'E';
		}
		if (calFinalAvg() < 50 && calFinalAvg() >=0)
		{
			return 'F';
		}
		else
		{
			return 'z';
		}
	}

};

#endif