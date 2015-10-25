CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: unittestresults.out

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

unittestresults.out: unitTest1.c unitTest2.c unitTest3.c unitTest4.c cardTest1.c cardTest2.c cardTest3.c cardTest4.c dominion.o rngs.o
	echo "Result for running tests:" > unittestresults.out
	
	echo "unitTest1.c:" >> unittestresults.out
	gcc -o unitTest1 -g unitTest1.c dominion.o rngs.o $(CFLAGS)
	./unitTest1 >> unittestresults.out
	gcov unitTest1.c >> unittestresults.out
	cat unitTest1.c.gcov >> unittestresults.out
	
	echo "unitTest2.c:" >> unittestresults.out
	gcc -o unitTest2 -g unitTest2.c dominion.o rngs.o $(CFLAGS)
	./unitTest2 >> unittestresults.out
	gcov unitTest2.c >> unittestresults.out
	cat unitTest2.c.gcov >> unittestresults.out

	echo "unitTest3.c:" >> unittestresults.out
	gcc -o unitTest3 -g unitTest3.c dominion.o rngs.o $(CFLAGS)
	./unitTest3 >> unittestresults.out
	gcov unitTest3.c >> unittestresults.out
	cat unitTest3.c.gcov >> unittestresults.out

	echo "unitTest4.c:" >> unittestresults.out
	gcc -o unitTest4 -g unitTest4.c dominion.o rngs.o $(CFLAGS)
	./unitTest4 >> unittestresults.out
	gcov unitTest4.c >> unittestresults.out
	cat unitTest4.c.gcov >> unittestresults.out

	echo "cardTest1.c:" >> unittestresults.out
	gcc -o cardTest1 -g cardTest1.c dominion.o rngs.o $(CFLAGS)
	./cardTest1 >> unittestresults.out
	gcov cardTest1.c >> unittestresults.out
	cat cardTest1.c.gcov >> unittestresults.out

	echo "cardTest2.c:" >> unittestresults.out
	gcc -o cardTest2 -g cardTest2.c dominion.o rngs.o $(CFLAGS)
	./cardTest2 >> unittestresults.out
	gcov cardTest2.c >> unittestresults.out
	cat cardTest2.c.gcov >> unittestresults.out

	echo "cardTest3.c:" >> unittestresults.out
	gcc -o cardTest3 -g cardTest3.c dominion.o rngs.o $(CFLAGS)
	./cardTest3 >> unittestresults.out
	gcov cardTest3.c >> unittestresults.out
	cat cardTest3.c.gcov >> unittestresults.out

	echo "cardTest4.c:" >> unittestresults.out
	gcc -o cardTest4 -g cardTest4.c dominion.o rngs.o $(CFLAGS)
	./cardTest4 >> unittestresults.out
	gcov cardTest4.c >> unittestresults.out
	cat cardTest4.c.gcov >> unittestresults.out

clean:
	rm unittestresults.out

cleanall: 
	rm unittestresults.out unitTest1 unitTest2 unitTest3 unitTest4 cardTest1 cardTest2 cardTest3 cardTest4 *.gcda *.gcno *.gcov
