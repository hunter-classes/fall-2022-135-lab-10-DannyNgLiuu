main: main.o minutes.o movie.o
	g++ -o main main.o minutes.o movie.o

main.o: main.cpp minutes.h movie.h

tests: tests.o minutes.o movie.o
	g++ -o tests tests.o minutes.o movie.o

tests.o: tests.cpp doctest.h minutes.h movie.h
	g++ -c -std=c++11 tests.cpp

clean:
	rm -f main tests main.o tests.o movie.o minutes.o

