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

testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
	gcc -o testUpdateCoins -g  testUpdateCoins.c dominion.o rngs.o $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

test1: unittest1.c interface.o
	gcc -o unittest1 -g unittest1.c dominion.o rngs.o interface.o $(CFLAGS)

test2: unittest2.c interface.o
	gcc -o unittest2 -g unittest2.c dominion.o rngs.o interface.o $(CFLAGS)

test3: unittest3.c interface.o
	gcc -o unittest3 -g unittest3.c dominion.o rngs.o interface.o $(CFLAGS)

test4: unittest4.c interface.o
	gcc -o unittest4 -g unittest4.c dominion.o rngs.o interface.o $(CFLAGS)

ctest1: cardtest1.c interface.o
	gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o interface.o $(CFLAGS)

ctest2: cardtest2.c interface.o
	gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o interface.o $(CFLAGS)

ctest3: cardtest3.c interface.o
	gcc -o cardtest3 -g cardtest3.c dominion.o rngs.o interface.o $(CFLAGS)

ctest4: cardtest4.c interface.o
	gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard testUpdateCoins test1 test2 test3 test4 ctest1 ctest2 ctest3 ctest4

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
