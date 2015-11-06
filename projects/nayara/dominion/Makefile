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

all: playdom player testDrawCard testBuyCard badTestDrawCard

unittestresults.out: 
	echo "cardtest1.c:" >> unittestresults.out
	gcc  dominion.c  rngs.c cardtest1.c -o cardtest1 $(CFLAGS)
	./cardtest1 >> unittestresults.out
	echo "coverage for cardtest1.c:" >> unittestresults.out

	echo "cardtest2.c:" >> unittestresults.out
	gcc  dominion.c  rngs.c cardtest2.c -o cardtest2 $(CFLAGS)
	./cardtest2 >> unittestresults.out
	echo "coverage for cardtest2.c:" >> unittestresults.out

	echo "cardtest3.c:" >> unittestresults.out
	gcc  dominion.c  rngs.c cardtest3.c -o cardtest3 $(CFLAGS)
	./cardtest3 >> unittestresults.out
	echo "coverage for cardtest3.c:" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "cardtest4.c:" >> unittestresults.out
	gcc  dominion.c  rngs.c cardtest4.c -o cardtest4 $(CFLAGS)
	./cardtest4 >> unittestresults.out
	echo "coverage for cardtest4.c:" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	echo "unittest1.c:" >> unittestresults.out
	gcc  dominion.c  rngs.c unittest1.c -o unittest1 $(CFLAGS)
	./unittest1 >> unittestresults.out
	echo "coverage for unittest1.c:" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	

	echo "unittest2.c:" >> unittestresults.out
	gcc  dominion.c  rngs.c unittest2.c -o unittest2 $(CFLAGS)
	./unittest2 >> unittestresults.out
	echo "coverage for unittest2.c:" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	

	echo "unittest3.c:" >> unittestresults.out
	gcc  dominion.c  rngs.c unittest3.c -o unittest3 $(CFLAGS)
	./unittest3 >> unittestresults.out
	echo "coverage for unittest3.c:" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	

	echo "unittest4.c:" >> unittestresults.out
	gcc  dominion.c  rngs.c unittest4.c -o unittest4 $(CFLAGS)
	./unittest4 >> unittestresults.out
	echo "coverage for unittest4.c:" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	

randomtestcard.out:
	echo "randomtestcard.c:" >> randomtestcard.out
	gcc  dominion.c  rngs.c randomtestcard.c -o randomtestcard.out $(CFLAGS)
	./randomtestcard.out >> randomtestresults.out
	echo "coverage for randomtestcard.c:" >> randomtestresults.out
	gcov dominion.c >> randomtestresults.out

randomtestadventurer.out:
	echo "randomtestadventurer.c:" >> randomtestadventurer.out
	gcc  dominion.c  rngs.c randomtestadventurer.c -o randomtestadventurer.out $(CFLAGS)
	./randomtestadventurer.out >> randomtestresults.out
	echo "coverage for randomtestadventurer.c:" >> randomtestresults.out
	gcov dominion.c >> randomtestresults.out

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.out
