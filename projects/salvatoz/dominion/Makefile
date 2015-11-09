CFLAGS = -Wall -fpic -coverage -lm -g -Wfatal-errors -std=c99
GCC = gcc
GCOV = gcov -b -c -f

.PHONY: all clean testAll runtests rununittest1 rununittest2

rngs.o: rngs.h rngs.c
	$(GCC) -c rngs.c  $(CFLAGS)

cards.o: cards.h cards.c
	$(GCC) -c cards.c $(CFLAGS)

dominion.o: dominion.h dominion.c
	$(GCC) -c dominion.c $(CFLAGS)	

playdom: dominion.o cards.o rngs.o playdom.c
	$(GCC) -o playdom playdom.c dominion.o cards.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	$(GCC) -c interface.c  $(CFLAGS)

player: player.c interface.o
	$(GCC) -o player player.c  dominion.o cards.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so badTestDrawCard testDrawCard unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 unittestresult.out randomtestadventurer randomtestadventurer.out randomtestcard randomtestcard.out statefile

# unit tests
testDrawCard: testDrawCard.c dominion.o cards.o rngs.o
	$(GCC) -o testDrawCard  testDrawCard.c dominion.o cards.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o cards.o rngs.o
	$(GCC) -o badTestDrawCard  badTestDrawCard.c dominion.o cards.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o cards.o rngs.o
	$(GCC) -o testDrawCard  testDrawCard.c dominion.o cards.o rngs.o $(CFLAGS)

unittest1: dominion.o cards.o rngs.o unittest1.c
	$(GCC) -o unittest1 unittest1.c dominion.o cards.o rngs.o $(CFLAGS)

unittest2: unittest2.c dominion.o cards.o rngs.o
	$(GCC) -o unittest2 unittest2.c dominion.o cards.o rngs.o $(CFLAGS)

unittest3: unittest3.c dominion.o cards.o rngs.o
	$(GCC) -o unittest3 unittest3.c dominion.o cards.o rngs.o $(CFLAGS)

unittest4: unittest4.c dominion.o cards.o rngs.o
	$(GCC) -o unittest4 unittest4.c dominion.o cards.o rngs.o $(CFLAGS)

cardtest1: dominion.o cards.o rngs.o cardtest1.c
	$(GCC) -o cardtest1 cardtest1.c dominion.o cards.o rngs.o $(CFLAGS)

cardtest2: dominion.o cards.o rngs.o cardtest2.c
	$(GCC) -o cardtest2 cardtest2.c dominion.o cards.o rngs.o $(CFLAGS)

cardtest3: dominion.o cards.o rngs.o cardtest3.c
	$(GCC) -o cardtest3 cardtest3.c dominion.o cards.o rngs.o $(CFLAGS)

cardtest4: dominion.o cards.o rngs.o cardtest4.c
	$(GCC) -o cardtest4 cardtest4.c dominion.o cards.o rngs.o $(CFLAGS)

randomtestadventurer: dominion.o cards.o rngs.o randomtestadventurer.c
	$(GCC) -o randomtestadventurer randomtestadventurer.c dominion.o cards.o rngs.o $(CFLAGS)

randomtestcard: dominion.o cards.o rngs.o randomtestcard.c
	$(GCC) -o randomtestcard randomtestcard.c dominion.o cards.o rngs.o $(CFLAGS)

testAll: dominion.o cards.o testSuite.c
	$(GCC) -o testSuite testSuite.c  dominion.o cards.o rngs.o $(CFLAGS)

# run unit tests
runtests: testDrawCard
	./testDrawCard &> unittestresult.out
	$(GCOV) dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

rununittest1: unittest1
	./unittest1 &> unittestresult.out
	$(GCOV) dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

rununittest2: unittest2
	./unittest2 &> unittestresult.out
	$(GCOV) dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

rununittest3: unittest3
	./unittest3 &> unittestresult.out
	$(GCOV) dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

rununittest4: unittest4
	./unittest4 &> unittestresult.out
	$(GCOV) dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

runcardtest1: cardtest1
	./cardtest1 &> unittestresult.out
	$(GCOV) cards.c >> unittestresult.out
	cat cards.c.gcov >> unittestresult.out

runcardtest2: cardtest2
	./cardtest2 &> unittestresult.out
	$(GCOV) cards.c >> unittestresult.out
	cat cards.c.gcov >> unittestresult.out

runcardtest3: cardtest3
	./cardtest3 &> unittestresult.out
	$(GCOV) cards.c >> unittestresult.out
	cat cards.c.gcov >> unittestresult.out

runcardtest4: cardtest4
	./cardtest4 &> unittestresult.out
	$(GCOV) cards.c >> unittestresult.out
	cat cards.c.gcov >> unittestresult.out

runrandomtestadventurer: randomtestadventurer
	./randomtestadventurer run statefile &> randomtestadventurer.out
	$(GCOV) cards.c >> unittestresult.out
	cat cards.c.gcov >> unittestresult.out

runrandomtestcard: randomtestcard
	./randomtestcard run statefile &> randomtestcard.out
	$(GCOV) cards.c >> unittestresult.out
	cat cards.c.gcov >> unittestresult.out

unittestresult.out: clean rununittest1 rununittest2 rununittest3 rununittest4 runcardtest1 runcardtest2 runcardtest3 runcardtest4
