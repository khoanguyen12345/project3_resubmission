all: test

test: test_hash_table.o
	g++ -o test test_hash_table.o

test_hash_table.o: hash_table.h hash_table.cpp  element.h element.cpp test_hash_table.cpp 
	g++ -c test_hash_table.cpp