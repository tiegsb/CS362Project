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
	
card1:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest1.c rngs.c -o cardtest1 -lm -g
	
card2:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest2.c rngs.c -o cardtest2 -lm -g
	
card3:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest3.c rngs.c -o cardtest3 -lm -g
	
card4:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest4.c rngs.c -o cardtest4 -lm -g

unit1:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest1.c rngs.c -o unittest1 -lm -g

unit2:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest2.c rngs.c -o unittest2 -lm -g	
	
unit3:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest3.c rngs.c -o unittest3 -lm -g	
	
unit4:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest4.c rngs.c -o unittest4 -lm -g	
	
player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

unittestresult.out: cardtest1.c cardtest2.c cardtest3.c cardtest4.c unittest2.c unittest3.c unittest4.c dominion.c rngs.o interface.o
	echo "Results from unit tests:" > unittestresult.out
	
	echo "======================== unittest1.c" >> unittestresult.out
	make unit1
	unittest1 >> unittestresult.out
	gcov dominion.c -b >> unittestresult.out
	
	echo "======================== unittest2.c" >> unittestresult.out
	make unit2
	unittest2 >> unittestresult.out
	gcov dominion.c -b >> unittestresult.out
	
	echo "======================== unittest3.c" >> unittestresult.out
	make unit3
	unittest3 >> unittestresult.out
	gcov dominion.c -b >> unittestresult.out
	
	echo "======================== unittest4.c" >> unittestresult.out
	make unit4
	unittest4 >> unittestresult.out
	gcov dominion.c -b >> unittestresult.out
	
	echo "======================== cardtest1.c" >> unittestresult.out
	make card1
	cardtest1 >> unittestresult.out
	gcov dominion.c -b >> unittestresult.out
	
	echo "======================== cardtest2.c" >> unittestresult.out
	make card2
	cardtest2 >> unittestresult.out
	gcov dominion.c -b >> unittestresult.out
	
	echo "======================== cardtest3.c" >> unittestresult.out
	make card3
	cardtest3 >> unittestresult.out
	gcov dominion.c -b >> unittestresult.out
	
	echo "======================== cardtest4.c" >> unittestresult.out
	make card4
	cardtest4 >> unittestresult.out
	gcov dominion.c -b >> unittestresult.out
	
all: playdom player testDrawCard testBuyCard badTestDrawCard unit1 unit2 unit3 unit4 card1 card2 card3 card4

clean:
	rm -f *.o unittestresult.out unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
