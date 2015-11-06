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

unittest1: dominion.o rngs.o unittest1.c
	gcc unittest1.c -o unittest1 -g dominion.o rngs.o $(CFLAGS)

unittest2: dominion.o rngs.o unittest2.c
	gcc unittest2.c -o unittest2 -g dominion.o rngs.o $(CFLAGS)

unittest3: dominion.o rngs.o unittest3.c
	gcc unittest3.c -o unittest3 -g dominion.o rngs.o $(CFLAGS)

unittest4: dominion.o rngs.o unittest4.c
	gcc unittest4.c -o unittest4 -g dominion.o rngs.o $(CFLAGS)

unittests: unittest1 unittest2 unittest3 unittest4 dominion.o

cardtest1: dominion.o rngs.o cardtest1.c
	gcc cardtest1.c -o cardtest1 -g dominion.o rngs.o $(CFLAGS)

cardtest2: dominion.o rngs.o cardtest2.c
	gcc cardtest2.c -o cardtest2 -g dominion.o rngs.o $(CFLAGS)

cardtest3: dominion.o rngs.o cardtest3.c
	gcc cardtest3.c -o cardtest3 -g dominion.o rngs.o $(CFLAGS)

cardtest4: dominion.o rngs.o cardtest4.c
	gcc cardtest4.c -o cardtest4 -g dominion.o rngs.o $(CFLAGS)

cardtests: cardtest1 cardtest2 cardtest3 cardtest4 dominion.o
	
unittestresults.out: unittests cardtests
	echo "Results from testing dominion.c" &> unittestresults.out
	./unittest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./unittest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./unittest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./unittest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./cardtest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./cardtest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./cardtest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./cardtest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	gcov dominion.c -f >> unittestresults.out

randomtestcard.out: dominion.o rngs.o randomtestcard.c dominion.o
	gcc randomtestcard.c -o randomtestcard -g dominion.o rngs.o $(CFLAGS)
	echo "Results from testing randomtestcard.c" &> randomtestcard.out
	./randomtestcard >> randomtestcard.out
	gcov dominion.c >> randomtestcard.out

randomtestadventurer.out: dominion.o rngs.o randomtestadventurer.c dominion.o
	gcc randomtestadventurer.c -o randomtestadventurer -g dominion.o rngs.o $(CFLAGS)
	echo "Results from testing randomtestadventurer.c" &> randomtestadventurer.out
	./randomtestadventurer >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit \
	testInit.exe testDrawCard badTestDrawCard unittest1 unittest2 unittest3 \
	unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestcard \
	randomtestadventurer *.gcov *.gcda *.gcno *.so
