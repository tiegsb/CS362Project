CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: unittestresults.out

unittestresults.out: unittest1.c rngs.c dominion.c
	gcc -c rngs.c -g  $(CFLAGS)
	gcc -c dominion.c -g  $(CFLAGS)
	echo "Result for running BST tests:" > unittestresults.out
	echo "unittest1.c:" >> unittestresults.out
	gcc -o unittest1 -g unittest1.c dominion.o rngs.o $(CFLAGS)
	unittest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	

clean:
	rm unittestresults.out

cleanall: 
	rm unittestresults.out unittest1 *.gcda *.gcno *.gcov
