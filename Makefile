main.out:main.o
	g++ main.o -o main.out -Wall
main.o:Test.hpp

.PHONY:clean
clean:
	rm *.o