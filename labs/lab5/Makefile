CC = clang++
CFLAGS = -Wall -Wextra -c
DEPS = LinkedList.h

%.o: %.cpp $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)

major: tufts-major-core.o LinkedList.o
	$(CC) -o major tufts-major-core.o LinkedList.o

clean:
	rm -f *.o core* *~ major
