CFLAGS = -Wall -fpic -coverage -lm -fprofile-arcs -std=c99 -ftest-coverage

all: playdom player testDrawCard testBuyCard badTestDrawCard randomtestcard randomtestadventurer unittest1 unittest2 unittest3 unittest4 cardtest2 cardtest1 cardtest3 cardtest4 randomtestcard.out unittestresults.out randomtestadventurer.out

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)
	
unittest1: unittest1.c dominion.o rngs.o interface.o
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o interface.o $(CFLAGS)
	
unittest2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS)
	
unittest3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS)
	
unittest4: unittest4.c dominion.o rngs.o interface.o
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o interface.o $(CFLAGS)

cardtest4: cardtest4.c dominion.o rngs.o interface.o
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o interface.o $(CFLAGS)

cardtest2: cardtest2.c dominion.o rngs.o interface.o
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o interface.o $(CFLAGS)

cardtest3: cardtest3.c dominion.o rngs.o interface.o
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o interface.o $(CFLAGS)

cardtest1: cardtest1.c dominion.o rngs.o interface.o
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o interface.o $(CFLAGS)

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o interface.o
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o interface.o $(CFLAGS)

randomtestadventurer.out: randomtestadventurer.c dominion.c rngs.o interface.o
	echo "Results for running unit test:" > randomtestadventurer.out

	echo "randomtestadventurer.c" > randomtestadventurer.out
	gcc -o randomtestadventurer randomtestadventurer.c dominion.c rngs.o interface.o -g $(CFLAGS)
	randomtestadventurer >> randomtestadventurer.out
	gcov -b randomtestadventurer >> randomtestadventurer.out
	
randomtestcard: randomtestcard.c dominion.o rngs.o interface.o
	gcc -o randomtestcard randomtestcard.c -g dominion.o rngs.o interface.o $(CFLAGS)

randomtestcard.out: randomtestcard.c dominion.c rngs.o interface.o
	echo "Results for running unit test:" > randomtestcard.out

	echo "randomtestcard.c" > randomtestcard.out
	gcc -o randomtestcard randomtestcard.c -g dominion.c rngs.o interface.o $(CFLAGS)
	randomtestcard >> randomtestcard.out
	gcov -b randomtestcard >> randomtestcard.out

unittestresults.out: unittest1.c unittest2.c unittest3.c unittest4.c cardtest4.c cardtest3.c cardtest2.c dominion.c rngs.o interface.o
	echo "Result for running unit tests:" > unittestresults.out
	
	echo "unittest1.c" >> unittestresults.out
	gcc -o unittest1 unittest1.c -g dominion.c rngs.o interface.o $(CFLAGS)
	unittest1 >> unittestresults.out
	gcov -b unittest1 >> unittestresults.out
	
	echo "unittest2.c" >> unittestresults.out
	gcc -o unittest2 unittest2.c -g dominion.c rngs.o $(CFLAGS)
	unittest2 >> unittestresults.out
	gcov -b unittest2 >> unittestresults.out
	
	echo "unittest3.c" >> unittestresults.out
	gcc -o unittest3 unittest3.c -g dominion.c rngs.o $(CFLAGS)
	unittest3 >> unittestresults.out
	gcov -b unittest3 >> unittestresults.out
	
	echo "unittest4.c" >> unittestresults.out
	gcc -o unittest4 unittest4.c -g dominion.c rngs.o interface.o $(CFLAGS)
	unittest4 >> unittestresults.out
	gcov -b unittest4 >> unittestresults.out

	echo "cardtest1.c" >> unittestresults.out
	gcc -o cardtest1 cardtest1.c -g dominion.c rngs.o interface.o $(CFLAGS)
	cardtest1 >> unittestresults.out
	gcov -b cardtest1 >> unittestresults.out

	echo "cardtest2.c" >> unittestresults.out
	gcc -o cardtest2 cardtest2.c -g dominion.c rngs.o interface.o $(CFLAGS)
	cardtest2 >> unittestresults.out
	gcov -b cardtest2 >> unittestresults.out

	echo "cardtest3.c" >> unittestresults.out
	gcc -o cardtest3 cardtest3.c -g dominion.c rngs.o interface.o $(CFLAGS)
	cardtest3 >> unittestresults.out
	gcov -b cardtest3 >> unittestresults.out

	echo "cardtest4.c" >> unittestresults.out
	gcc -o cardtest4 cardtest4.c -g dominion.c rngs.o interface.o $(CFLAGS)
	cardtest4 >> unittestresults.out
	gcov -b cardtest4 >> unittestresults.out

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe
	unittest1.exe cardtest1.exe cardtest1 cardtest2.exe cardtest2 cardtest3.exe cardtest3 unittest1 unittest2.exe unittest2 unittest3.exe unittest3 unittest4.exe unittest4 cardtest4.exe cardtest4
	randomtestcard randomtestcard.exe randomtestadventurer randomtestadventurer.exe *.gcov *.gcda *.gcno *.so