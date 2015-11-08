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

testUpdateCoins: testUpdateCoins.c dominion.o rngs.o 
	gcc -o testUpdateCoins -g testUpdateCoins.c dominion.o rngs.o $(CFLAGS)

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

unit1: unittest1.c dominion.c rngs.c 
	gcc -fprofile-arcs -ftest-coverage dominion.c unittest1.c rngs.c -o unittest1 -lm -g $(CFLAGS) 

unit2: unittest2.c dominion.c rngs.c
	gcc -fprofile-arcs -ftest-coverage dominion.c unittest2.c rngs.c -o unittest2 -lm -g $(CFLAGS) 

unit3: unittest3.c dominion.c rngs.c
	gcc -fprofile-arcs -ftest-coverage dominion.c unittest3.c rngs.c -o unittest3 -lm -g $(CFLAGS) 

unit4: unittest4.c dominion.c rngs.c
	gcc -fprofile-arcs -ftest-coverage dominion.c unittest4.c rngs.c -o unittest4 -lm -g $(CFLAGS) 

card1: cardtest1.c dominion.c rngs.c
	gcc -fprofile-arcs -ftest-coverage dominion.c cardtest1.c rngs.c -o cardtest1 -lm -g $(CFLAGS) 

card2: cardtest2.c dominion.c rngs.c
	gcc -fprofile-arcs -ftest-coverage dominion.c cardtest2.c rngs.c -o cardtest2 -lm -g $(CFLAGS) 

card3: cardtest3.c dominion.c rngs.c
	gcc -fprofile-arcs -ftest-coverage dominion.c cardtest3.c rngs.c -o cardtest3 -lm -g $(CFLAGS) 

card4: cardtest4.c dominion.c rngs.c
	gcc -fprofile-arcs -ftest-coverage dominion.c cardtest4.c rngs.c -o cardtest4 -lm -g $(CFLAGS)

unittestresults.out: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.o rngs.o	
	echo "unittest1.c:" >> unittestresults.out
	gcc -o unittest1 dominion.o rngs.o unittest1.c $(CFLAGS)
	unittest1 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out
	
	echo "unittest2.c:" >> unittestresults.out
	gcc -o unittest2 dominion.o rngs.o unittest2.c $(CFLAGS)
	unittest2 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out
	
	echo "unittest3.c:" >> unittestresults.out
	gcc -o unittest3 dominion.o rngs.o unittest3.c $(CFLAGS)
	unittest3 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out
	
	echo "unittest4.c:" >> unittestresults.out
	gcc -o unittest4 dominion.o rngs.o unittest4.c $(CFLAGS)
	unittest4 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out
	
	echo "cardtest1.c:" >> unittestresults.out
	gcc -o cardtest1 dominion.o rngs.o cardtest1.c $(CFLAGS)
	cardtest1 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out
	
	echo "cardtest2.c:" >> unittestresults.out
	gcc -o cardtest2 dominion.o rngs.o cardtest2.c $(CFLAGS)
	cardtest2 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out
	
	echo "cardtest3.c:" >> unittestresults.out
	gcc -o cardtest3 dominion.o rngs.o cardtest3.c $(CFLAGS)
	cardtest3 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out
	
	echo "cardtest4.c:" >> unittestresults.out
	gcc -o cardtest4 dominion.o rngs.o cardtest4.c $(CFLAGS)
	cardtest4 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -fprofile-arcs -ftest-coverage -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS)

randomtestadventurer.out: randomtestadventurer.c dominion.o rngs.o
	echo "Result for running random test on CEadventurer():" > randomtestadventurer.out
	
	echo "randomtestadventurer.c" >> randomtestadventurer.out
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS)
	randomtestadventurer >> randomtestadventurer.out
	gcov dominion.c -b >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out
	
randomtestcard: randomtestcard.c dominion.o rngs.o
	gcc -fprofile-arcs -ftest-coverage -o randomtestcard randomtestcard.c -g dominion.o rngs.o $(CFLAGS)

randomtestcard.out: randomtestcard.c dominion.o rngs.o
	echo "Result for running random test on CEsteward():" > randomtestcard.out
	
	echo "randomtestcard.c" >> randomtestcard.out
	gcc -o randomtestcard randomtestcard.c -g dominion.c rngs.o $(CFLAGS)
	randomtestcard >> randomtestcard.out
	gcov dominion.c -b >> randomtestcard.out
	cat dominion.c.gcov >> randomtestcard.out

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe
	cardtest1.exe cardtest1 cardtest2.exe cardtest2 cardtest3.exe cardtest3 cardtest4.exe cardtest4
	unittest1.exe unittest1 unittest2.exe unittest2 unittest3.exe unittest3 unittest4.exe unittest4
	*.gcov *.gcda *.gcno *.so