all: test

test: test_hash_table.o hash_table.o element.o
	g++ -o test $^

test_hash_table.o: test_hash_table.cpp hash_table.h element.h
	g++ -c $<

hash_table.o: hash_table.cpp hash_table.h
	g++ -c $<

element.o: element.cpp element.h
	g++ -c $<

clean:
	rm -f *.o test