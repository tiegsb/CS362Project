CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

unittestresult.out: unittest1.c unittest2.c dominion.c
	make clean
	make all	
	echo "Result for running dominion tests:" > unittestresult.out
	
	echo "-----------------------------------" >> unittestresult.out
	echo "unittest1.c:" >> unittestresult.out
	gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
	./unittest1 >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	# cat dominion.c.gcov >> unittestresult.out

	echo "-----------------------------------" >> unittestresult.out
	echo "unittest2.c:" >> unittestresult.out
	gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
	./unittest2 >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	# cat dominion.c.gcov >> unittestresult.out

	echo "-----------------------------------" >> unittestresult.out
	echo "unittest3.c:" >> unittestresult.out
	gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
	./unittest3 >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	# cat dominion.c.gcov >> unittestresult.out

	echo "-----------------------------------" >> unittestresult.out
	echo "unittest4.c:" >> unittestresult.out
	gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)
	./unittest4 >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	# cat dominion.c.gcov >> unittestresult.out

	echo "-----------------------------------" >> unittestresult.out
	echo "cardtest1.c:" >> unittestresult.out
	gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)
	./cardtest1 >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	# cat dominion.c.gcov >> unittestresult.out

	echo "-----------------------------------" >> unittestresult.out
	echo "cardtest2.c:" >> unittestresult.out
	gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)
	./cardtest2 >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	# cat dominion.c.gcov >> unittestresult.out

	echo "-----------------------------------" >> unittestresult.out
	echo "cardtest3.c:" >> unittestresult.out
	gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)
	./cardtest3 >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	# cat dominion.c.gcov >> unittestresult.out

	echo "-----------------------------------" >> unittestresult.out
	echo "cardtest4.c:" >> unittestresult.out
	gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
	./cardtest4 >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	# cat dominion.c.gcov >> unittestresult.out

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

randomtestadventurer.out: clean randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
	./randomtestadventurer >> randomtestadventurer.out

randomtestcard.out: clean randomtestcard.c dominion.o rngs.o
	gcc -o randomtestcard -g randomtestcard.c dominion.o rngs.o $(CFLAGS)
	./randomtestcard >> randomtestcard.out

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
	rm -rf *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.dSYM badTestDrawCard testDrawCard unittestresult.out unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestadventurer randomtestadventurer.out randomtestcard randomtestcard.out
