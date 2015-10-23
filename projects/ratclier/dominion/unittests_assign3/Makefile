CFLAGS = -Wall -fpic -coverage -I.. -std=c99 -lm

default: tests.out

rngs.o: ../rngs.c
	gcc -c ../rngs.c -g  $(CFLAGS)

dominion.o: ../dominion.c rngs.o
	gcc -c ../dominion.c -g  $(CFLAGS)

unittest_helpers.o: unittest_helpers.c
	gcc -c unittest_helpers.c -g  $(CFLAGS)

unittest1: unittest1.c unittest_helpers.o dominion.o rngs.o
	gcc -o unittest1 -g unittest1.c unittest_helpers.o dominion.o rngs.o $(CFLAGS)

tests.out: unittest1.c
	echo "Result for running BST tests:" > tests.out
	
	echo "unittest1.c:" >> tests.out
	gcc -o unittest1 unittest1.c $(CFLAGS)
	./unittest1 >> tests.out

clean:
	rm tests.out

cleanall: 
	rm tests.out unittest1 


