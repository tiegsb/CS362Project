CFLAGS = -Wall -fpic -coverage -lm

unittest1: unittest1.c
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS)

unittest2: unittest2.c
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS)

unittest3: unittest3.c
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS)

unittest4: unittest4.c
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS)

cardtest1: cardtest1.c
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o $(CFLAGS)

cardtest2: cardtest2.c
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o $(CFLAGS)

cardtest3: cardtest3.c
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o $(CFLAGS)

cardtest4: cardtest4.c
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o $(CFLAGS)

randomtestadventurer: randomtestadventurer.c
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS)

randomtestcard: randomtestcard.c
	gcc -o randomtestcard randomtestcard.c -g dominion.o rngs.o $(CFLAGS)

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

randomtestadventurer.out: randomtestadventurer 
	echo "Adventurer Test" &> randomtestadventurer.out

	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.c rngs.o $(CFLAGS)
	randomtestadventurer >> randomtestadventurer.out
	gcov randomtestadventurer.c >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out

randomtestcard.out: randomtestcard
	echo "Random test card" &> randomtestcard.out

	gcc -o randomtestcard randomtestcard.c -g dominion.c rngs.o $(CFLAGS)
	randomtestcard >> randomtestcard.out
	gcov randomtestcard.c >> randomtestcard.out
	gcov dominion.c >> randomtestcard.out

unittestresults.out: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
	echo "UNIT TEST 1" &> unittestresults.out

	gcc -o unittest1 unittest1.c -g dominion.c rngs.o $(CFLAGS)
	unittest1 >> unittestresults.out
	gcov unittest1.c >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	echo "UNIT TEST 2" >> unittestresults.out
	gcc -o unittest2 unittest2.c -g dominion.c rngs.o $(CFLAGS)
	./unittest2 >> unittestresults.out
	gcov unittest2.c >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	echo "UNIT TEST 3" >> unittestresults.out
	gcc -o unittest3 unittest3.c -g dominion.c rngs.o $(CFLAGS)
	./unittest3 >> unittestresults.out
	gcov unittest3.c >> unittestresults.out	
	gcov dominion.c >> unittestresults.out
	echo "UNIT TEST 4" >> unittestresults.out
	gcc -o unittest4 unittest4.c -g dominion.c rngs.o $(CFLAGS)
	./unittest4 >> unittestresults.out
	gcov unittest4.c >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	echo "CARD TEST 1" >> unittestresults.out
	gcc -o cardtest1 cardtest1.c -g dominion.c rngs.o $(CFLAGS)
	./cardtest1 >> unittestresults.out
	gcov cardtest1.c >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	echo "CARD TEST 2" >> unittestresults.out
	gcc -o cardtest2 cardtest2.c -g dominion.c rngs.o $(CFLAGS)
	./cardtest2 >> unittestresults.out
	gcov cardtest2.c >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	echo "CARD TEST 3" >> unittestresults.out
	gcc -o cardtest3 cardtest3.c -g dominion.c rngs.o $(CFLAGS)
	./cardtest3 >> unittestresults.out
	gcov cardtest3.c >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	echo "CARD TEST 4" >> unittestresults.out
	gcc -o cardtest4 cardtest4.c -g dominion.c rngs.o $(CFLAGS)
	./cardtest4 >> unittestresults.out
	gcov cardtest4.c >> unittestresults.out
	gcov dominion.c >> unittestresults.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe unittest1 unittest1.exe unittest2 unittest2.exe unittest3 unittest3.exe unittest4 unittest4.exe cardtest1 cardtest1.exe cardtest2 cardtest2.exe cardtest3 cardtest3.exe cardtest4 cardtest4.exe *.gcov *.gcda *.gcno *.so
