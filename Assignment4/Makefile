CFLAGS = -Wall -fpic -coverage -lm
GCOV = -ftest-coverage -fprofile-arcs

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS) $(GCOV)

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

all: playdom player testDrawCard testBuyCard badTestDrawCard cardtests unittests randomtests

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
	rm -f unittestresults.out

#######################################

unittestresults.out:
	make all
	echo > unittestresults.out
	echo "< =========================== RUNNING ALL TESTS =========================== >" >> unittestresults.out
	echo >> unittestresults.out
	make run_all_tests >> unittestresults.out
	echo >> unittestresults.out
	echo "< =========================== RUNNING COVERAGE RESULTS =========================== >" >> unittestresults.out
	echo >> unittestresults.out
	gcov -b -f dominion.o >> unittestresults.out

run_all_tests:
	./cardtest1
	./cardtest2
	./cardtest3
	./cardtest4
	./unittest1
	./unittest2
	./unittest3
	./unittest4

cardtests:
	make cardtest1
	make cardtest2
	make cardtest3
	make cardtest4

cardtest1: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)

cardtest2: cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)

cardtest3: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)

cardtest4: cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)

unittests:
	make unittest1
	make unittest2
	make unittest3
	make unittest4

unittest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)

unittest2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)

unittest3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)

unittest4: unittest4.c dominion.o rngs.o
	gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)


#######################################

randomtests:
	make randomtestcard
	make randomtestadventurer

randomtestsout:
	make clean
	make randomtestcardout
	make randomtestadventurerout

randomtestcard: randomtestcard.c dominion.o rngs.o
	gcc -o randomtestcard -g  randomtestcard.c dominion.o rngs.o $(CFLAGS)

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g  randomtestadventurer.c dominion.o rngs.o $(CFLAGS)

randomtestcardout:
	make all
	echo > randomtestcard.out
	echo "< =========================== RUNNING RANDOM TESTS =========================== >" >> randomtestcard.out
	echo >> randomtestcard.out
	./randomtestcard >> randomtestcard.out
	echo >> randomtestcard.out
	echo "< =========================== RUNNING COVERAGE RESULTS =========================== >" >> randomtestcard.out
	echo >> randomtestcard.out
	gcov -b -f dominion.o >> randomtestcard.out

randomtestadventurerout:
	make all
	echo > randomtestadventurer.out
	echo "< =========================== RUNNING RANDOM TESTS =========================== >" >> randomtestadventurer.out
	echo >> randomtestadventurer.out
	./randomtestadventurer >> randomtestadventurer.out
	echo >> randomtestadventurer.out
	echo "< =========================== RUNNING COVERAGE RESULTS =========================== >" >> randomtestadventurer.out
	echo >> randomtestadventurer.out
	gcov -b -f dominion.o >> randomtestadventurer.out

	


