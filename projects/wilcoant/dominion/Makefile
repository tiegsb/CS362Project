CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: unittestresults.out

unittestresults.out: unittest1.c unittest2.c unittest3.c rngs.c dominion.c
	gcc -c rngs.c -g  $(CFLAGS)
	gcc -c dominion.c -g  $(CFLAGS)
	
	echo "Results for running dominion.c tests:" > unittestresults.out
	echo "unittest1.c:" >> unittestresults.out
	gcc -o unittest1 -g unittest1.c dominion.o rngs.o $(CFLAGS)
	unittest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	echo "unittest2.c:" >> unittestresults.out
	gcc -o unittest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)
	unittest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	echo "unittest3.c:" >> unittestresults.out
	gcc -o unittest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)
	unittest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out


clean:
	rm unittestresults.out

cleanall: 
	rm unittestresults.out unittest1 unittest2 unittest3 *.gcda *.gcno *.gcov
