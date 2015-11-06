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

unittest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)

unittest2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)

unittest3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)

unittest4: unittest4.c dominion.o rngs.o
	gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)

cardtest1: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)

cardtest2: cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)

cardtest3: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)

cardtest4: cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)

randomtestcard: randomtestcard.c dominion.o rngs.o
	gcc -o randomtestcard -g  randomtestcard.c dominion.o rngs.o $(CFLAGS)

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g  randomtestadventurer.c dominion.o rngs.o $(CFLAGS)

randomtestcard.out: randomtestcard.c dominion.c dominion.h dominion.o rngs.o
	rm -f dominion.o
	echo “Random Test - Smithy Card: Results” > randomtestcard.out
	echo >> randomtestcard.out
	make randomtestcard
	randomtestcard >> randomtestcard.out
	echo >> randomtestcard.out
	echo “Random Test - Smithy Card: randomtestcard.c gcov:” >> randomtestcard.out
	gcov -b randomtestcard.c >> randomtestcard.out
	echo >> randomtestcard.out
	echo “Random Test - Smithy Card: dominion.c gcov:” >> randomtestcard.out
	gcov -b dominion.c >> randomtestcard.out

randomtestadventurer.out: randomtestadventurer.c dominion.c dominion.h dominion.o rngs.o
	rm -f dominion.o
	echo “Random Test - Adventurer Card: Results” > randomtestadventurer.out
	echo >> randomtestadventurer.out
	make randomtestadventurer
	randomtestadventurer >> randomtestadventurer.out
	echo >> randomtestadventurer.out
	echo “Random Test - Adventurer Card: randomtestadventurer.c gcov:” >> randomtestadventurer.out
	gcov -b randomtestadventurer.c >> randomtestadventurer.out
	echo >> randomtestadventurer.out
	echo “Random Test - Adventurer Card: dominion.c gcov:” >> randomtestadventurer.out
	gcov -b dominion.c >> randomtestadventurer.out

unittestresults.out: cardtest1.c cardtest2.c cardtest3.c cardtest4.c unittest1.c unittest2.c unittest3.c unittest4.c dominion.c dominion.h dominion.o rngs.o
	echo “Unit Test Results:” > unittestresults.out
	echo >> unittestresults.out

	rm -f dominion.o
	echo >> unittestresults.out
	echo “Unit Test 1: updateCoins:” >> unittestresults.out
	make unittest1
	unittest1 >> unittestresults.out
	echo >> unittestresults.out
	echo “Unit Test 1: unittest1.c gcov:” >> unittestresults.out
	gcov -b unittest1.c >> unittestresults.out
	echo >> unittestresults.out
	echo “Unit Test 1: dominion.c gcov:” >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out

	rm -f dominion.o
	echo >> unittestresults.out
	echo “Unit Test 2: fullDeckCount:” >> unittestresults.out
	make unittest2
	unittest2 >> unittestresults.out
	echo >> unittestresults.out
	echo “Unit Test 2: unittest2.c gcov:” >> unittestresults.out
	gcov -b unittest2.c >> unittestresults.out
	echo >> unittestresults.out
	echo “Unit Test 2: dominion.c gcov:” >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out

	rm -f dominion.o
	echo >> unittestresults.out
	echo “Unit Test 3: discardCard:” >> unittestresults.out
	make unittest3
	unittest3 >> unittestresults.out
	echo >> unittestresults.out
	echo “Unit Test 3: unittest3.c gcov:” >> unittestresults.out
	gcov -b unittest3.c >> unittestresults.out
	echo >> unittestresults.out
	echo “Unit Test 3: dominion.c gcov:” >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out

	rm -f dominion.o
	echo >> unittestresults.out
	echo “Unit Test 4: gainCard:” >> unittestresults.out
	make unittest4
	unittest4 >> unittestresults.out
	echo >> unittestresults.out
	echo “Unit Test 4: unittest4.c gcov:” >> unittestresults.out
	gcov -b unittest4.c >> unittestresults.out
	echo >> unittestresults.out
	echo “Unit Test 4: dominion.c gcov:” >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out

	rm -f dominion.o
	echo >> unittestresults.out
	echo “Card Test 1: Adventurer:” >> unittestresults.out
	make cardtest1
	cardtest1 >> unittestresults.out
	echo >> unittestresults.out
	echo “Card Test 1: cardtest1.c gcov:” >> unittestresults.out
	gcov -b cardtest1.c >> unittestresults.out
	echo >> unittestresults.out
	echo “Card Test 1: dominion.c gcov:” >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out

	rm -f dominion.o
	echo >> unittestresults.out
	echo “Card Test 2: Smithy:” >> unittestresults.out
	make cardtest2
	cardtest2 >> unittestresults.out
	echo >> unittestresults.out
	echo “Card Test 2: cardtest2.c gcov:” >> unittestresults.out
	gcov -b cardtest2.c >> unittestresults.out
	echo >> unittestresults.out
	echo “Card Test 2: dominion.c gcov:” >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out

	rm -f dominion.o
	echo >> unittestresults.out
	echo “Card Test 3: Great Hall:” >> unittestresults.out
	make cardtest3
	cardtest3 >> unittestresults.out
	echo >> unittestresults.out
	echo “Card Test 3: cardtest3.c gcov:” >> unittestresults.out
	gcov -b cardtest3.c >> unittestresults.out
	echo >> unittestresults.out
	echo “Card Test 3: dominion.c gcov:” >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out

	rm -f dominion.o
	echo >> unittestresults.out
	echo “Card Test 4: Village:” >> unittestresults.out
	make cardtest4
	cardtest4 >> unittestresults.out
	echo >> unittestresults.out
	echo “Card Test 4: cardtest2.c gcov:” >> unittestresults.out
	gcov -b cardtest4.c >> unittestresults.out
	echo >> unittestresults.out
	echo “Card Test 4: dominion.c gcov:” >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out


runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
