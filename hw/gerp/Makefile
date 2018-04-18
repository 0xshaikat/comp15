CC = clang++
CFLAGS = -Wall -Wextra -std=c++11 -c  -O2
DEPS = DirNode.h FSTree.h LinkedHashNode.h HashMap.h

%.o: %.cpp $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)


gerp: DirNode.o FSTree.o gerp-driver.o LinkedHashNode.o HashMap.o
	$(CC) -o gerp DirNode.o FSTree.o gerp-driver.o LinkedHashNode.o HashMap.o

hashtest: hash-test.o LinkedHashNode.o HashMap.o
	$(CC) -o hashtest hash-test.o LinkedHashNode.o HashMap.o


clean:
	rm -f *.o core* *~ gerp
	rm -f *.o core* *~ hashtest
