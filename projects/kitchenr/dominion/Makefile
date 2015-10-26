CFLAGS = -Wall -fpic -coverage -lm -std=c99

unittest1: rngs.o
	gcc -o unittest1 -DUNIT_TEST_1 dominion.c rngs.o $(CFLAGS)

unittest2: rngs.o
	gcc -o unittest2 -DUNIT_TEST_2 dominion.c rngs.o $(CFLAGS)

unittest3: rngs.o
	gcc -o unittest3 -DUNIT_TEST_3 dominion.c rngs.o $(CFLAGS)

unittest4: rngs.o
	gcc -o unittest4 -DUNIT_TEST_4 dominion.c rngs.o $(CFLAGS)

cardtest1: rngs.o
	gcc -o cardtest1 -DCARD_TEST_1 dominion.c rngs.o $(CFLAGS)

cardtest2: rngs.o cardtest2.c
	gcc -o cardtest2 -DCARD_TEST_2 dominion.c rngs.o $(CFLAGS)

cardtest3: rngs.o cardtest3.c
	gcc -o cardtest3 -DCARD_TEST_3 dominion.c rngs.o $(CFLAGS)

cardtest4: rngs.o cardtest4.c
	gcc -o cardtest4 -DCARD_TEST_4 dominion.c rngs.o $(CFLAGS)

unittestresults.out: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
	rm -rf unittestresults.out
	echo "Unit test 1:\n" >> unittestresults.out
	make unittest1
	./unittest1
	gcov -b -c dominion >> unittestresults.out
	echo "Unit test 2:\n" >> unittestresults.out
	make unittest2
	./unittest2
	gcov -b -c dominion >> unittestresults.out
	echo "Unit test 3:\n" >> unittestresults.out
	make unittest3
	./unittest3
	gcov -b -c dominion >> unittestresults.out
	echo "Unit test 4:\n" >> unittestresults.out
	make unittest4
	./unittest4
	gcov -b -c dominion >> unittestresults.out
	echo "Card test 1:\n" >> unittestresults.out
	make cardtest1
	./cardtest1
	gcov -b -c dominion >> unittestresults.out
	echo "Card test 2:\n" >> unittestresults.out
	make cardtest2
	./cardtest2
	gcov -b -c dominion >> unittestresults.out
	echo "Card test 3:\n" >> unittestresults.out
	make cardtest3
	./cardtest3
	gcov -b -c dominion >> unittestresults.out
	echo "Card test 4:\n" >> unittestresults.out
	make cardtest4
	./cardtest4
	gcov -b -c dominion >> unittestresults.out
	

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

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
