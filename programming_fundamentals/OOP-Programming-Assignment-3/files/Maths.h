#ifndef MATHS_H
#define MATHS_H

#include "Student.h"


template< class T>
class Maths : public Student
{
private:
	T quiz1;
	T quiz2;
	T quiz3;
	T test1;
	T test2;
	T finalExamMarks;
public:
	Maths()
		:quiz1(0),quiz2(0),quiz3(0),test1(0),test2(0),finalExamMarks(0)
	{
		setParamters("","","");
	}

	void setTranscript(ifstream& in)
	{
		in>>quiz1;
		in>>quiz2;
		in>>quiz3;
		in>>test1;
		in>>test2;
		in>>finalExamMarks;
	}

	int getFinalExamMarks() { return (int)finalExamMarks; }

	void show(){
		cout << quiz1<<" "<<quiz2<<" "<<quiz3<<" "<<test1<<" "<<test2<<" "<<finalExamMarks;
	}

	double calQuizAvg()
	{
		return ((quiz1+quiz2+quiz3)/300)*100;
	}

	double calFinalAvg()
	{
		return (calQuizAvg()*.10)+(test1*.25)+(test2*.25)+(finalExamMarks*.40);
	}
};

#endif