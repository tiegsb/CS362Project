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

randomizer.o: randomizer.h randomizer.c
	gcc -c randomizer.c -g $(CFLAGS)

randomtestadventurer: dominion.o interface.o randomizer.o 
	gcc  -o randomtestadventurer randomtestadventurer.c randomizer.o dominion.o interface.o rngs.o $(CFLAGS)

randomtestcard: dominion.o interface.o randomizer.o 
	gcc  -o randomtestcard randomtestcard.c randomizer.o dominion.o interface.o rngs.o $(CFLAGS)
    
randomtestadventurer.out: dominion.o interface.o randomizer.o
	gcc  -o randomtestadventurer randomtestadventurer.c randomizer.o dominion.o interface.o rngs.o $(CFLAGS)
	./randomtestadventurer
	gcov -b dominion.c >> randomtestadventurer.out

randomtestcard.out: dominion.o interface.o randomizer.o
	gcc -o randomtestcard randomtestcard.c randomizer.o dominion.o interface.o rngs.o $(CFLAGS)
	./randomtestcard
	gcov -b dominion.c >> randomtestcard.out
    
testSuite: dominion.o testSuite.c interface.o
	gcc -o testSuite testSuite.c -g interface.o dominion.o rngs.o $(CFLAGS)
    
unittestresult.out: dominion.o testSuite.c interface.o
	gcc -o testSuite testSuite.c -g interface.o dominion.o rngs.o $(CFLAGS)
	./testSuite &> unittestresult.out
	gcov -b dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
    
runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: randomtestadventurer randomtestcard randomizer.o playdom interface.o cardtest1 cardtest2 cardtest3 cardtest4 unittest1 unittest2 unittest3 unittest4 allUnitTests player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o randomtestcard.out randomtestcard randomtestadventurer randomtestadventurer.out rand_adv unittestresult.out testSuite testSuite.exe cardtest1.exe cardtest1 cardtest2.exe cardtest2 cardtest3.exe cardtest3 cardtest4.exe cardtest4 unittest1.exe unittest1 unittest2.exe unittest2 unittest3.exe unittest3 unittest4.exe unittest4 playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
