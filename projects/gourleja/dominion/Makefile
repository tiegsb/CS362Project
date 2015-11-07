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

unitTest1: dominion.o unittest1.c
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS)

unitTest2: dominion.o unittest2.c
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS)

unitTest3: dominion.o unittest3.c
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS)

unitTest4: dominion.o unittest4.c
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS)

cardTest1: dominion.o cardtest1.c
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o $(CFLAGS)

cardTest2: dominion.o cardtest2.c
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o $(CFLAGS)

cardTest3: dominion.o cardtest3.c
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o $(CFLAGS)

cardTest4: dominion.o cardtest4.c
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

randomtestcard: dominion.o randomtestcard.c
	gcc -o randomtestcard randomtestcard.c -g dominion.o rngs.o $(CFLAGS)

randomtestadventurer: dominion.o randomtestadventurer.c
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

allUnitTests: unitTest1 unitTest2 unitTest3 unitTest4 cardTest1 cardTest2 cardTest3 cardTest4

unittestresults.out: clean all allUnitTests
	# Run Programs and save results
	./unittest1 2>&1 |cat > unittestresults.out
	gcov unittest1.c >> unittestresults.out
	./unittest2 >> unittestresults.out
	gcov unittest2.c >> unittestresults.out
	./unittest3 >> unittestresults.out
	gcov unittest3.c >> unittestresults.out
	./unittest4 >> unittestresults.out
	gcov unittest4.c >> unittestresults.out
	./cardtest1 >> unittestresults.out
	gcov cardtest1.c >> unittestresults.out
	./cardtest2 >> unittestresults.out
	gcov cardtest2.c >> unittestresults.out
	./cardtest3 >> unittestresults.out
	gcov cardtest3.c >> unittestresults.out
	./cardtest4 >> unittestresults.out
	gcov cardtest4.c >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	# Append full coverage results
	cat unittest1.c.gcov >> unittestresults.out
	cat unittest2.c.gcov >> unittestresults.out
	cat unittest3.c.gcov >> unittestresults.out
	cat unittest4.c.gcov >> unittestresults.out
	cat cardtest1.c.gcov >> unittestresults.out
	cat cardtest2.c.gcov >> unittestresults.out
	cat cardtest3.c.gcov >> unittestresults.out
	cat cardtest4.c.gcov >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

randomtestcard.out: clean all randomtestcard
	# Run Programs and save results
	./randomtestcard 2>&1 |cat > randomtestcard.out
	gcov randomtestcard.c >> randomtestcard.out
	gcov dominion.c >> randomtestcard.out
	cat randomtestcard.c.gcov >> randomtestcard.out
	cat dominion.c.gcov >> randomtestcard.out

randomtestadventurer.out: clean all randomtestadventurer
	# Run Programs and save results
	./randomtestadventurer 2>&1 |cat > randomtestadventurer.out
	gcov randomtestadventurer.c >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	cat randomtestadventurer.c.gcov >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe badTestDrawCard badTestDrawCard.exe testDrawCard testDrawCard.exe testInit testInit.exe unittest1 unittest1.exe unittest2 unittest2.exe unittest3 unittest3.exe unittest4 unittest4.exe cardtest1 cardtest1.exe cardtest2 cardtest2.exe cardtest3 cardtest3.exe cardtest4 cardtest4.exe *.gcov *.gcda *.gcno *.so
