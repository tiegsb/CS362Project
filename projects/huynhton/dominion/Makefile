CFLAGS = -Wall -fpic -coverage -lm
#CFLAGS = -Wall -fpic -coverage -lm -std=c99
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

# Example test
testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
	gcc -o testUpdateCoins -g  testUpdateCoins.c dominion.o rngs.o $(CFLAGS)
	
	
	
# Making my own tests
#testGainCard: unittest1.c dominion.o rngs.o 
#	gcc -o testGainCard -g unittest1.c dominion.o rngs.o $(CFLAGS)

#testGainCard: unittest1.c dominion.c rngs.c 
#	gcc -fprofile-arcs -ftest-coverage dominion.c unittest1.c rngs.c -o testGainCard -lm -g $(CFLAGS) 

testGainCard: unittest1.c dominion.c rngs.c 
	gcc -fprofile-arcs -ftest-coverage dominion.c unittest1.c rngs.c -o testGainCard -lm -g $(CFLAGS)
	
testDiscardCard: unittest2.c dominion.o rngs.o 
	gcc -o testDiscardCard -g unittest2.c dominion.o rngs.o $(CFLAGS)
	
testScoreFor: unittest3.c dominion.o rngs.o 
	gcc -o testScoreFor -g unittest3.c dominion.o rngs.o $(CFLAGS)
	
testGetCost: unittest4.c dominion.o rngs.o
	gcc -o testGetCost -g unittest4.c dominion.o rngs.o $(CFLAGS)
	
testSmithy: cardtest1.c dominion.o rngs.o 
	gcc -o testSmithy -g cardtest1.c dominion.o rngs.o $(CFLAGS)

testAdventurer: cardtest2.c dominion.o rngs.o
	gcc -o testAdventurer -g  cardtest2.c dominion.o rngs.o $(CFLAGS)
	
testVillage: cardtest3.c dominion.o rngs.o
	gcc -o testVillage -g  cardtest3.c dominion.o rngs.o $(CFLAGS)
	
testCouncilRoom: cardtest4.c dominion.o rngs.o
	gcc -o testCouncilRoom -g  cardtest4.c dominion.o rngs.o $(CFLAGS)

# HW 4 - random tests
randomVillage: randomtestcard.c dominion.o rngs.o
	gcc -o randomVillage -g  randomtestcard.c dominion.o rngs.o $(CFLAGS)
	
randomAdventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomAdventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)

	
# Make gcov tests

unittestresults.out: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.o rngs.o
	echo "Result for running Dominion unit/card tests:" > unittestresults.out
	
	echo "unittest1.c:" >> unittestresults.out
	#gcc -o testGainCard dominion.o rngs.o unittest1.c $(CFLAGS)
	gcc -fprofile-arcs -ftest-coverage dominion.c unittest1.c rngs.c -o testGainCard -lm -g $(CFLAGS)
	testGainCard >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out
	
	echo "unittest2.c:" >> unittestresults.out
	#gcc -o testDiscardCard dominion.c unittest2.c $(CFLAGS)
	gcc -fprofile-arcs -ftest-coverage dominion.c unittest2.c rngs.c -o testDiscardCard -lm -g $(CFLAGS)
	testDiscardCard >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out
	
	echo "unittest3.c:" >> unittestresults.out
	#gcc -o testScoreFor dominion.c unittest3.c $(CFLAGS)
	gcc -fprofile-arcs -ftest-coverage dominion.c unittest3.c rngs.c -o testScoreFor -lm -g $(CFLAGS)
	testScoreFor >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out
	
	echo "unittest4.c:" >> unittestresults.out
	#gcc -o testGetCost dominion.c unittest4.c $(CFLAGS)
	gcc -fprofile-arcs -ftest-coverage dominion.c unittest4.c rngs.c -o testGetCost -lm -g $(CFLAGS)
	testGetCost >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out
	
	echo "cardtest1.c:" >> unittestresults.out
	#gcc -o testSmithy dominion.c cardtest1.c $(CFLAGS)
	gcc -fprofile-arcs -ftest-coverage dominion.c cardtest1.c rngs.c -o testSmithy -lm -g $(CFLAGS)
	testSmithy >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out
	
	echo "cardtest2.c:" >> unittestresults.out
	#gcc -o testAdventurer dominion.c cardtest2.c $(CFLAGS)
	gcc -fprofile-arcs -ftest-coverage dominion.c cardtest2.c rngs.c -o testAdventurer -lm -g $(CFLAGS)
	testAdventurer >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out
	
	echo "cardtest3.c:" >> unittestresults.out
	#gcc -o testVillage dominion.c cardtest3.c $(CFLAGS)
	gcc -fprofile-arcs -ftest-coverage dominion.c cardtest3.c rngs.c -o testVillage -lm -g $(CFLAGS)
	testVillage >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out
	
	echo "cardtest4.c:" >> unittestresults.out
	#gcc -o testCouncilRoom dominion.c cardtest4.c $(CFLAGS)
	gcc -fprofile-arcs -ftest-coverage dominion.c cardtest4.c rngs.c -o testCouncilRoom -lm -g $(CFLAGS)
	testCouncilRoom >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out

	
# Assignment 4- make randomtestcard.out and randomtestadventurer.out
#
randomtestcard.out: randomtestcard.c dominion.o rngs.o
	echo "Results from random testing Village card:" > randomtestcard.out
	
	echo "randomtestcard.c:" >> randomtestcard.out
	gcc -fprofile-arcs -ftest-coverage dominion.c randomtestcard.c rngs.c -o randomVillage -lm -g $(CFLAGS)
	randomVillage >> randomtestcard.out
	gcov dominion.c -b >> randomtestcard.out
	
randomtestadventurer.out: randomtestadventurer.c dominion.o rngs.o
	echo "Results from random testing Adventurer card:" > randomtestadventurer.out
	
	echo "randomtestadventurer.c:" >> randomtestadventurer.out
	gcc -fprofile-arcs -ftest-coverage dominion.c randomtestadventurer.c rngs.c -o randomAdventurer -lm -g $(CFLAGS)
	randomAdventurer >> randomtestadventurer.out
	gcov dominion.c -b >> randomtestadventurer.out


	
	
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

all: playdom player testDrawCard testBuyCard badTestDrawCard testUpdateCoins testGainCard testDiscardCard testScoreFor testGetCost testSmithy testAdventurer testVillage testCouncilRoom randomVillage randomAdventurer unittestresults.out

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe unittestresults.out randomtestcard.out randomtestadventurer.out *.gcov *.gcda *.gcno *.so
