CFLAGS = -Wall -fpic -coverage -lm -g -Wfatal-errors
GCC = gcc

.PHONY: all clean testAll runtests

rngs.o: rngs.h rngs.c
	$(GCC) -c rngs.c  $(CFLAGS)

cards.o: cards.h cards.c
	$(GCC) -c cards.c $(CFLAGS)

dominion.o: dominion.h dominion.c cards.o rngs.o
	$(GCC) -c dominion.c cards.o rngs.o $(CFLAGS)

playdom: dominion.o playdom.c
	$(GCC) -o playdom playdom.c dominion.o cards.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	$(GCC) -c interface.c  $(CFLAGS)

player: player.c interface.o
	$(GCC) -o player player.c  dominion.o cards.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so badTestDrawCard testDrawCard

# unit tests
testDrawCard: testDrawCard.c dominion.o cards.o rngs.o
	$(GCC) -o testDrawCard  testDrawCard.c dominion.o cards.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o cards.o rngs.o
	$(GCC) -o badTestDrawCard  badTestDrawCard.c dominion.o cards.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o cards.o rngs.o
	$(GCC) -o testDrawCard  testDrawCard.c dominion.o cards.o rngs.o $(CFLAGS)

unittest1: unittest1.c dominion.o cards.o rngs.o
	$(GCC) -o unittest1 unittest1.c dominion.o cards.o rngs.o $(CFLAGS)

testAll: dominion.o cards.o testSuite.c
	$(GCC) -o testSuite testSuite.c  dominion.o cards.o rngs.o $(CFLAGS)

# run unit tests
runtests: testDrawCard unittest1
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
