CC = clang++
CFLAGS = -Wall -Wextra -std=c++11 -c
DEPS = Stack.h RPNCalc.h

%.o: %.cpp $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)

calculator: run-calc.o Stack.o RPNCalc.o
	$(CC) -o calculator run-calc.o Stack.o RPNCalc.o

stacktest: test-stack.o Stack.o
	$(CC) -o stacktest test-stack.o Stack.o

clean:
	rm -f *.o core* *~ calculator
	rm -f *.o core* *~ stacktest
