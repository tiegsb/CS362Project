CFLAGS = -Wall -fpic -coverage -lm
GCC = gcc

rngs.o: rngs.h rngs.c
	$(GCC) -c rngs.c -g  $(CFLAGS)

cards.o: cards.h cards.c
	$(GCC) -c cards.c -g $(CFLAGS)

dominion.o: dominion.h dominion.c cards.o rngs.o
	$(GCC) -c dominion.c cards.o rngs.o -g $(CFLAGS)

playdom: dominion.o playdom.c
	$(GCC) -o playdom playdom.c -g dominion.o cards.o rngs.o $(CFLAGS)

testDrawCard: testDrawCard.c dominion.o cards.o rngs.o
	$(GCC) -o testDrawCard -g  testDrawCard.c dominion.o cards.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o cards.o rngs.o
	$(GCC) -o badTestDrawCard -g  badTestDrawCard.c dominion.o cards.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o cards.o rngs.o
	$(GCC) -o testDrawCard -g  testDrawCard.c dominion.o cards.o rngs.o $(CFLAGS)

testAll: dominion.o cards.o testSuite.c
	$(GCC) -o testSuite testSuite.c -g  dominion.o cards.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	$(GCC) -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	$(GCC) -o player player.c -g  dominion.o cards.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
