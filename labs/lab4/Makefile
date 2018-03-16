CC = clang++
CFLAGS = -Wall -Wextra -c
DEPS = Heap.h MinHeap.h Patient.h Queue.h

%.o: %.cpp $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)

er: er.o Heap.o Patient.o MinHeap.o Queue.o
	$(CC) -o er er.o Heap.o Patient.o MinHeap.o Queue.o

clean:
	rm -f *.o core* *~ er
