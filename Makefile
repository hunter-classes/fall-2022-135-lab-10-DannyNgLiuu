main: main.o minutes.o movie.o
	g++ -o main main.o minutes.o movie.o

main.o: main.cpp minutes.h movie.h

# tests: tests.o time.o
# 	g++ -o tests tests.o time.o

# tests.o: tests.cpp doctest.h time.h
# 	g++ -c -std=c++11 tests.cpp

clean:
	rm -f main tests time main.o tests.o movie.o minutes.o

