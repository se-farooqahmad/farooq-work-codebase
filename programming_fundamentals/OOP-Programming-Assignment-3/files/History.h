#ifndef HISTORY_H
#define HISTORY_H

#include "Student.h"


template<class T>


class History : public Student
{
private:
	T termPaper;
	T midTerm;
	T finalExamMarks;
public:

	void setTermPaper(T tp) { termPaper = tp; }
	void setMidTerm(T mt) { midTerm = mt; }
	void setFinalTerm(T ft) { finalTerm = ft; }
	
	T getTermPaper() { return termPaper; }
	T getMidTerm() { return midTerm; }
	int getFinalExamMarks() { return (int)finalExamMarks; }

	History()
		:termPaper(0),midTerm(0),finalExamMarks(0)
	{
		setParamters("", "", "");
	}

	void setTranscript(ifstream& in)
	{
		in>>termPaper;
		in>>midTerm;
		in>>finalExamMarks;
	}
	
	double calFinalAvg()
	{
		return (termPaper*.25)+(midTerm*.35)+(finalExamMarks*.40);
	}	

};

#endif
