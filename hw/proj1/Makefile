CC = clang++
CFLAGS = -Wall -Wextra -std=c++11 -c
DEPS = Queue.h BinaryTree.h BinarySearchTree.h Survivor.h

%.o: %.cpp $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)

survivor: Queue.o BinaryTree.o BinarySearchTree.o Survivor.o survivor-driver.o
	$(CC) -o survivor Queue.o BinaryTree.o BinarySearchTree.o Survivor.o survivor-driver.o

bttest: Queue.o BinaryTree.o Survivor.o test-bt-driver.o
	$(CC) -o bttest Queue.o BinaryTree.o Survivor.o test-bt-driver.o

bsttest: Queue.o BinaryTree.o BinarySearchTree.o Survivor.o test-bst-driver.o
	$(CC) -o bsttest Queue.o BinaryTree.o BinarySearchTree.o Survivor.o test-bst-driver.o

treetest: Queue.o BinaryTree.o BinarySearchTree.o Survivor.o test-tree.o
	$(CC) -o treetest Queue.o BinaryTree.o BinarySearchTree.o Survivor.o test-tree.o

survivortest: Survivor.o survivor-test.o
	$(CC) -o survivortest Survivor.o survivor-test.o

clean:
	rm -f *.o core* *~ survivor
	rm -f *.o core* *~ bttest
	rm -f *.o core* *~ bsttest
	rm -f *.o core* *~ treetest
	rm -f *.o core* *~ survivortest
