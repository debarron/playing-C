all: test-example clean
.PHONY: all

Example.o:
	g++ -c Example.cpp -I./

Example_Wrapper.o:
	g++ -c Example_Wrapper.cpp -I./

test-example: Example.o Example_Wrapper.o
	gcc -o test-example main.c Example_Wrapper.o Example.o -I./ -lstdc++

clean:
	rm *.o
