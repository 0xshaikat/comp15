CC = clang++
CFLAGS = -Wall -Wextra -c
DEPS = LinkedList.h Planet.h

%.o: %.cpp $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)

planets: Planet.o LinkedList.o planet-driver.o
	$(CC) -o planets Planet.o LinkedList.o planet-driver.o

clean:
	rm -f *.o core* *~ planets
