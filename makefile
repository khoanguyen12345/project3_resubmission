all: usecase test

test: test_minqueue.o
	g++ -o test test_minqueue.o

test_minqueue.o: minqueue.h minqueue.cpp test_minqueue.cpp usecase.cpp
	g++ -c test_minqueue.cpp

usecase: main.o
	g++ -o usecase main.o

usecase.o: minqueue.h minqueue.cpp main.cpp usecase.cpp
	g++ -c main.cpp
	