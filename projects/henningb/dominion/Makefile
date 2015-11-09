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
	
unittest1: unittest1.c dominion.o rngs.o interface.o
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o interface.o $(CFLAGS)
	
unittest2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS)
	
unittest3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS)
	
unittest4: unittest4.c dominion.o rngs.o interface.o
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o interface.o $(CFLAGS)

cardtest1: cardtest1.c dominion.o rngs.o interface.o
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o interface.o $(CFLAGS)
	
cardtest2: cardtest2.c dominion.o rngs.o interface.o
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o interface.o $(CFLAGS)

cardtest3: cardtest3.c dominion.o rngs.o interface.o
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o interface.o $(CFLAGS)
	
cardtest4: cardtest4.c dominion.o rngs.o interface.o
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o interface.o $(CFLAGS)
	
unittestresults.out: cardtest1.c cardtest2.c cardtest3.c cardtest4.c unittest2.c unittest3.c unittest4.c dominion.c rngs.o interface.o
	echo "Unit Test Results:" > unittestresults.out
	
	echo "---------------------------------------------------" >> unittestresults.out
	echo "Unit Test 1: shuffle()" >> unittestresults.out
	echo "---------------------------------------------------" >> unittestresults.out
	gcc -o unittest1 unittest1.c -g dominion.c rngs.o interface.o $(CFLAGS)
	unittest1 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	gcov -b unittest1.c >> unittestresults.out
	
	echo "---------------------------------------------------" >> unittestresults.out
	echo "Unit Test 2: isGameOver()" >> unittestresults.out
	echo "---------------------------------------------------" >> unittestresults.out
	gcc -o unittest2 unittest2.c -g dominion.c rngs.o $(CFLAGS)
	unittest2 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	gcov -b unittest2.c >> unittestresults.out
	
	echo "---------------------------------------------------" >> unittestresults.out
	echo "Unit Test 3: updateCoins()" >> unittestresults.out
	echo "---------------------------------------------------" >> unittestresults.out
	gcc -o unittest3 unittest3.c -g dominion.c rngs.o $(CFLAGS)
	unittest3 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	gcov -b unittest3.c >> unittestresults.out
	
	echo "---------------------------------------------------" >> unittestresults.out
	echo "Unit Test 4: buyCard()" >> unittestresults.out
	echo "---------------------------------------------------" >> unittestresults.out
	gcc -o unittest4 unittest4.c -g dominion.c rngs.o interface.o $(CFLAGS)
	unittest4 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	gcov -b unittest4.c >> unittestresults.out
	
	echo "---------------------------------------------------" >> unittestresults.out
	echo "Card Test 1: smithy" >> unittestresults.out
	echo "---------------------------------------------------" >> unittestresults.out
	gcc -o cardtest1 cardtest1.c -g dominion.c rngs.o interface.o $(CFLAGS)
	cardtest1 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	gcov -b cardtest1.c >> unittestresults.out
	
	echo "---------------------------------------------------" >> unittestresults.out
	echo "Card Test 2: Adventurer" >> unittestresults.out
	echo "---------------------------------------------------" >> unittestresults.out
	gcc -o cardtest2 cardtest2.c -g dominion.c rngs.o interface.o $(CFLAGS)
	cardtest2 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	gcov -b cardtest2.c >> unittestresults.out
	
	echo "---------------------------------------------------" >> unittestresults.out
	echo "Card Test 3: sea hag" >> unittestresults.out
	echo "---------------------------------------------------" >> unittestresults.out
	gcc -o cardtest3 cardtest3.c -g dominion.c rngs.o interface.o $(CFLAGS)
	cardtest3 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	gcov -b cardtest3.c >> unittestresults.out
	
	echo "---------------------------------------------------" >> unittestresults.out
	echo "Card Test 4: village" >> unittestresults.out
	echo "---------------------------------------------------" >> unittestresults.out
	gcc -o cardtest4 cardtest4.c -g dominion.c rngs.o interface.o $(CFLAGS)
	cardtest4 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	gcov -b cardtest4.c >> unittestresults.out

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)

randomtestadventurer.out: randomtestadventurer.c dominion.o rngs.o
	echo "-------------------------------------------------------" >> randomtestadventurer.out
	echo "RESULTS FOR RANDOMTESTADVENTURER:" >> randomtestadventurer.out
	echo "-------------------------------------------------------" >> randomtestadventurer.out
	gcc -o randomtestadventurer dominion.o rngs.o randomtestadventurer.c $(CFLAGS)
	randomtestadventurer >> randomtestadventurer.out
	echo "-------------------------------------------------------" >> randomtestadventurer.out
	echo "GCOV RESULTS" >> randomtestadventurer.out
	echo "-------------------------------------------------------" >> randomtestadventurer.out
	gcov -b dominion.c >> randomtestadventurer.out
	gcov -b randomtestadventurer.c >> randomtestadventurer.out

randomtestcard: randomtestcard.c dominion.o rngs.o
	gcc -o randomtestcard -g randomtestcard.c dominion.o rngs.o $(CFLAGS)

randomtestcard.out: randomtestcard.c dominion.o rngs.o
	echo "-------------------------------------------------------" >> randomtestcard.out
	echo "RESULTS FOR RANDOMTESTCARD (SMITHY):" >> randomtestcard.out
	echo "-------------------------------------------------------" >> randomtestcard.out
	gcc -o randomtestcard dominion.o rngs.o randomtestcard.c $(CFLAGS)
	randomtestcard >> randomtestcard.out
	echo "-------------------------------------------------------" >> randomtestcard.out	
	echo "GCOV RESULTS" >> randomtestcard.out
	echo "-------------------------------------------------------" >> randomtestcard.out
	gcov -b dominion.c >> randomtestcard.out	
	gcov -b randomtestcard.c >> randomtestcard.out
	
all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
