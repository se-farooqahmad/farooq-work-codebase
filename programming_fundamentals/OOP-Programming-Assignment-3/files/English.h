#ifndef ENGLISH_H
#define ENGLISH_H

#include "Student.h"

template<class T>
class English : public Student
{
private:
	T attendance;
	T project;
	T midTerm;
	T finalExamMarks;
	
public:
	English() :
		attendance(0), project(0), midTerm(0), finalExamMarks(0)
	{
		setParamters("", "", "");
	}
	
	int getFinalExamMarks() { return (int)finalExamMarks; }

	void setTranscript(ifstream& in)
	{
		in>>attendance;
		in>>project;
		in>>midTerm;
		in>>finalExamMarks;
	}
	
	double calFinalAvg()
	{
		return (attendance*.10)+(project*.30)+(midTerm*.30)+(finalExamMarks*.30);
	}
};

#endif