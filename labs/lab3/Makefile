CC = clang++
CFLAGS = -Wall -Wextra -c
DEPS = BinaryTree.h BinarySearchTree.h Queue.h

%.o: %.cpp $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)

likeatree: alpha.o BinaryTree.o BinarySearchTree.o Queue.o
	$(CC) -o tree alpha.o BinaryTree.o BinarySearchTree.o Queue.o

clean:
	rm -f *.o core* *~ tree
