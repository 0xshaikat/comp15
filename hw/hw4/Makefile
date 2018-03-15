CC = clang++
CFLAGS = -Wall -Wextra -std=c++11
DEPS = Patient.h Heap.h MinHeap.h MaxHeap.h

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

heaps: intake.o Patient.o Heap.o MinHeap.o MaxHeap.o
	$(CC) -o heapify intake.o Patient.o Heap.o MinHeap.o MaxHeap.o

mintest: test-min-heap.o Patient.o Heap.o MinHeap.o
	$(CC) -o mintest test-min-heap.o Patient.o Heap.o MinHeap.o

clean:
	rm -f *.o core* *~ heapify
	rm -f *.o core* *~ mintest
