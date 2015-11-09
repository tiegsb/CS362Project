CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: unittestresults.out

randomOuts: asrandomtestcard.c randomtestadventurer.c dominion.c unittestHelper.c rngs.c 

		gcc -o randomtestcard asrandomtestcard.c unittestHelper.c dominion.c rngs.c -lm -g $(CFLAGS)
		randomtestcard >> randomtestcard.out
		gcov randomtestcard >> randomtestcard.out
		
		gcov dominion.c >> randomtestcard.out

		gcc -o randomtestadventurer randomtestadventurer.c unittestHelper.c dominion.c rngs.c -lm -g $(CFLAGS)
		randomtestadventurer >> randomtestadventurer.out
		gcov randomtestadventurer >> randomtestadventurer.out

		gcov dominion.c >> randomtestadventurer.out
		
unittestresults.out: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c

	echo "Result for running all unit tests:" > unittestresults.out
	
	echo "unittest1.c:" >> unittestresults.out
	gcc -o unittest1 unittest1.c unittestHelper.c dominion.c rngs.c -lm -g $(CFLAGS)
	unittest1 >> unittestresults.out
	gcov dominion.c >>  unittestresults.out


	echo "unittest2.c:" >> unittestresults.out
	gcc -o unittest2 unittest2.c unittestHelper.c dominion.c rngs.c -lm -g $(CFLAGS)
	unittest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	echo "unittest3.c:" >> unittestresults.out
	gcc -o unittest3 unittest3.c unittestHelper.c dominion.c rngs.c -lm -g $(CFLAGS)
	unittest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "unittest4.c:" >> unittestresults.out
	gcc -o unittest4 unittest4.c unittestHelper.c dominion.c rngs.c -lm -g $(CFLAGS)
	unittest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "cardtest1.c:" >> unittestresults.out
	gcc -o cardtest1 cardtest1.c unittestHelper.c dominion.c rngs.c -lm -g $(CFLAGS)
	cardtest1 >> unittestresults.out
	gcov dominion.c >>  unittestresults.out


	echo "cardtest2.c:" >> unittestresults.out
	gcc -o cardtest2 cardtest2.c unittestHelper.c dominion.c rngs.c -lm -g $(CFLAGS)
	cardtest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	echo "cardtest3.c:" >> unittestresults.out
	gcc -o cardtest3 cardtest3.c unittestHelper.c dominion.c rngs.c -lm -g $(CFLAGS)
	cardtest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	
	echo "cardtest4.c:" >> unittestresults.out
	gcc -o cardtest4 cardtest4.c unittestHelper.c dominion.c rngs.c -lm -g $(CFLAGS)
	cardtest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out


clean:
	rm unittestresults.out

cleanall: 
	rm unittestresults.out unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 *.gcda *.gcno *.gcov
