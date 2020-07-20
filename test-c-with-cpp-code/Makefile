Example.o:
	gcc -lstdc++ -std=c++11 -o Example.o -c Example.cpp 

test_example.o: 
	gcc -o test_example.o -c test_example.c

test-example: Example.o test_example.o
	g++ -o test-example Example.o test_example.o -I./


