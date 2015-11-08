CFLAGS = -Wall -fpic -coverage -lm -g
CC=gcc


rngs.o: rngs.h rngs.c
	$(CC) -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	$(CC) -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	$(CC) -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

testDrawCard: testDrawCard.c dominion.o rngs.o
	$(CC) -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	$(CC) -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	$(CC) -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	$(CC) -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	$(CC) -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov-5 dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

unittests: unittest1 unittest2 unittest3 unittest4
rununittests: rununittest1 rununittest2 rununittest3 rununittest4

unittest1: unittest1.c dominion.o rngs.o
	$(CC) -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)

rununittest1:
	./unittest1 &> unittest1result.out
	gcov dominion.c >> unittest1result.out
	cat dominion.c.gcov >> unittest1result.out

unittest2: unittest2.c dominion.o rngs.o
	$(CC) -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)

rununittest2:
	gcov dominion.c >> unittest2result.out
	./unittest2 &> unittest2result.out
	cat dominion.c.gcov >> unittest2result.out

unittest3: unittest3.c dominion.o rngs.o
	$(CC) -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)

rununittest3:
	./unittest3 &> unittest3result.out
	gcov dominion.c >> unittest3result.out
	cat dominion.c.gcov >> unittest3result.out

unittest4: unittest4.c dominion.o rngs.o
	$(CC) -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)

rununittest4:
	./unittest4 &> unittest4result.out
	gcov dominion.c >> unittest4result.out
	cat dominion.c.gcov >> unittest4result.out

testRunner: dominion.o rngs.o
	$(CC) rngs.o dominion.o testRunner.c -o tests $(CFLAGS)

runTests: testRunner
	./tests &> testresult.out
	gcov -b dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

unittestresults.out: runTests dominion.o

player: player.c interface.o
	$(CC) -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

randomtestcard: dominion.o randomtestcard.c
	$(CC) -o randomtestcard dominion.o rngs.o randomtestcard.c ${CFLAGS}

randomtestadventurer: dominion.o randomtestadventurer.c
	$(CC) -o randomtestadventurer dominion.o rngs.o randomtestadventurer.c ${CFLAGS}

randomtestcard.out: randomtestcard
	./randomtestcard &> randomtestcard.out
	gcov dominion.c >> randomtestcard.out
	cat dominion.c.gcov >> randomtestcard.out

randomtestadventurer.out: randomtestadventurer
	./randomtestadventurer &> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out




all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so unittests unittest1 unittest2 unittest3 unittest4 testDrawCard *.out
	rm -rf *.dSYM
