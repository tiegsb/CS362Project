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

unittest1: dominion.o unittest1.c interface.o
	gcc -o unittest1 unittest1.c -g interface.o dominion.o rngs.o $(CFLAGS)
	unittest1 >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
    
unittest2: dominion.o unittest2.c interface.o
	gcc -o unittest2 unittest2.c -g interface.o dominion.o rngs.o $(CFLAGS)

unittest3: dominion.o unittest3.c interface.o
	gcc -o unittest3 unittest3.c -g interface.o dominion.o rngs.o $(CFLAGS)
    
unittest4: dominion.o unittest4.c interface.o
	gcc -o unittest4 unittest4.c -g interface.o dominion.o rngs.o $(CFLAGS)
    
cardtest1: dominion.o cardtest1.c interface.o
	gcc -o cardtest1 cardtest1.c -g interface.o dominion.o rngs.o $(CFLAGS)

cardtest2: dominion.o cardtest2.c interface.o
	gcc -o cardtest2 cardtest2.c -g interface.o dominion.o rngs.o $(CFLAGS)

cardtest3: dominion.o cardtest3.c interface.o
	gcc -o cardtest3 cardtest3.c -g interface.o dominion.o rngs.o $(CFLAGS)

cardtest4: dominion.o cardtest4.c interface.o
	gcc -o cardtest4 cardtest4.c -g interface.o dominion.o rngs.o $(CFLAGS)

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

all: playdom interface.o cardtest1 cardtest2 cardtest3 cardtest4 unittest1 unittest2 unittest3 unittest4 allUnitTests player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o unittestresult.out testSuite testSuite.exe cardtest1.exe cardtest1 cardtest2.exe cardtest2 cardtest3.exe cardtest3 cardtest4.exe cardtest4 unittest1.exe unittest1 unittest2.exe unittest2 unittest3.exe unittest3 unittest4.exe unittest4 playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
