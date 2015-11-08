CFLAGS = -Wall -fpic -coverage -lm

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

all: playdom player testDrawCard testBuyCard badTestDrawCard

unittest1: unittest1.c interface.o dominion.o rngs.o
	gcc -o unittest1 unittest1.c -g interface.o dominion.o rngs.o $(CFLAGS)

unittest2: unittest2.c interface.o dominion.o rngs.o
	gcc -o unittest2 unittest2.c -g interface.o dominion.o rngs.o $(CFLAGS)

unittest3: unittest3.c interface.o dominion.o rngs.o
	gcc -o unittest3 unittest3.c -g interface.o dominion.o rngs.o $(CFLAGS)

unittest4: unittest4.c interface.o dominion.o rngs.o
	gcc -o unittest4 unittest4.c -g interface.o dominion.o rngs.o $(CFLAGS)

cardtest1: cardtest1.c interface.o dominion.o rngs.o
	gcc -o cardtest1 cardtest1.c -g interface.o dominion.o rngs.o $(CFLAGS)

cardtest2: cardtest2.c interface.o dominion.o rngs.o
	gcc -o cardtest2 cardtest2.c -g interface.o dominion.o rngs.o $(CFLAGS)

cardtest3: cardtest3.c interface.o dominion.o rngs.o
	gcc -o cardtest3 cardtest3.c -g interface.o dominion.o rngs.o $(CFLAGS)

cardtest4: cardtest4.c interface.o dominion.o rngs.o
	gcc -o cardtest4 cardtest4.c -g interface.o dominion.o rngs.o $(CFLAGS)

unittestresults.out: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c interface.o dominion.o rngs.o
	echo "Results for tests:\n" > unittestresults.out

	gcc -o unittest1 unittest1.c -g interface.o dominion.o rngs.o $(CFLAGS)
	unittest1 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out

	gcc -o unittest2 unittest2.c -g interface.o dominion.o rngs.o $(CFLAGS)
	unittest2 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out

	gcc -o unittest3 unittest3.c -g interface.o dominion.o rngs.o $(CFLAGS)
	unittest3 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out

	gcc -o unittest4 unittest4.c -g interface.o dominion.o rngs.o $(CFLAGS)
	unittest4 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out

	gcc -o cardtest1 cardtest1.c -g interface.o dominion.o rngs.o $(CFLAGS)
	cardtest1 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out

	gcc -o cardtest2 cardtest2.c -g interface.o dominion.o rngs.o $(CFLAGS)
	cardtest2 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out

	gcc -o cardtest3 cardtest3.c -g interface.o dominion.o rngs.o $(CFLAGS)
	cardtest3 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out

	gcc -o cardtest4 cardtest4.c -g interface.o dominion.o rngs.o $(CFLAGS)
	cardtest4 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out

randomtestadventurer.out: randomtestadventurer.c interface.o dominion.o rngs.o
	echo "Results for randomtestadventurer:\n" > randomtestadventurer.out

	gcc -o randomtestadventurer randomtestadventurer.c -g interface.o dominion.o rngs.o $(CFLAGS)
	randomtestadventurer >> randomtestadventurer.out
	gcov -b dominion.c >> randomtestadventurer.out

randomtestcard.out: randomtestcard.c interface.o dominion.o rngs.o
	echo "Results for randomtestcard:\n" > randomtestcard.out

	gcc -o randomtestcard randomtestcard.c -g interface.o dominion.o rngs.o $(CFLAGS)
	randomtestcard >> randomtestcard.out
	gcov -b dominion.c >> randomtestcard.out

clean:
	rm -f *.o playdom.exe playdom unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestadventurer randomtestcard test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
