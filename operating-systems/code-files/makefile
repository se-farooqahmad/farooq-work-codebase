all: main.o func1.o func2.o func3.o
	g++ -o all main.o func1.o func2.o func3.o

main.o: main.cpp func1.h func2.h func3.h
	g++ -c main.cpp

func3.o: func3.cpp func3.h
	g++ -c func3.cpp

func2.o: func2.cpp func2.h
	g++ -c func2.cpp

func1.o: func1.cpp func1.h
	g++ -c func1.cpp
