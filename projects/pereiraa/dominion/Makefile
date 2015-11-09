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

cardtest1:  cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)

cardtest2: cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)

cardtest3: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)

randomtestcard: randomtestcard.c dominion.o rngs.o
	gcc -o randomtestcard -g  randomtestcard.c dominion.o rngs.o $(CFLAGS)

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g  randomtestadventurer.c dominion.o rngs.o $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

unittestresults: unittest1 unittest2 unittest3 cardtest1 cardtest2 cardtest3 dominion.o rngs.o
	./unittest1 &> unittestresults.out
	gcov -b unittest1.c>>unittestresults.out
	
	./unittest2 >> unittestresults.out
	gcov -b unittest2.c>>unittestresults.out

	./unittest3 >> unittestresults.out
	gcov -b unittest3.c>>unittestresults.out
	
	./cardtest1 >> unittestresults.out
	gcov -b cardtest1.c>>unittestresults.out
	
	./cardtest2 >> unittestresults.out
	gcov -b cardtest2.c>>unittestresults.out
	
	./cardtest3 >> unittestresults.out
	gcov -b cardtest3.c>>unittestresults.out

	gcov dominion.c >> unittestresults.out

	cat dominion.c.gcov >> unittestresults.out

randomtestcard.out:
	make all
	echo > randomtestcard.out
	echo "<=============== RUNNING ALL TEST =====================>" >> randomtestcard.out
	echo >> randomtestcard.out
	make run_randomCard_test >> randomtestcard.out
	echo "<=============== RUNNING COVERAGE TEST =====================>" >> randomtestcard.out
	echo >> randomtestcard.out
	gcov -b -f dominion.o >> randomtestcard.out

run_randomCard_test:
	./randomtestcard

randomtestadventurer.out:
	make all
	echo > randomtestadventurer.out
	echo "<=============== RUNNING ALL TEST =====================>" >> randomtestadventurer.out
	echo >> randomtestadventurer.out
	make run_randomAdven_test >> randomtestadventurer.out
	echo "<=============== RUNNING COVERAGE TEST =====================>" >> randomtestadventurer.out
	echo >> randomtestadventurer.out
	gcov -b -f dominion.o >> randomtestadventurer.out

run_randomAdven_test:
	./randomtestadventurer
		
player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard unittest1 unittest2 cardtest1 cardtest2 cardtest3 randomtestcard randomtestadventurer

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
