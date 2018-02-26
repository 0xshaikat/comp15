CC = clang++
CFLAGS = -Wall -Wextra -std=c++11 -c
DEPS = Planet.h LinkedList.h

%.o: %.cpp $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)


planets: planet-driver.o Planet.o LinkedList.o 
	$(CC) -o planets planet-driver.o Planet.o LinkedList.o

test: test-driver.o Planet.o LinkedList.o
	$(CC) -o test test-driver.o Planet.o LinkedList.o

clean:
	rm -f *.o core* *~ planets
	rm -f *.o core* *~ test
