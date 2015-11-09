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

unittestresults.out: testHandCard testGainCard testIsGameOver testGetCost cardTestSmithy cardTestAdventurer cardTestGreatHall cardTestRemodel
	./testHandCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	./testGainCard >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	./testIsGameOver >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	./testGetCost >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	./cardTestSmithy >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	./cardTestAdventurer >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	./cardTestGreatHall >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	./cardTestRemodel >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

testHandCard: unittesthandcard.c dominion.o rngs.o	
	gcc -o testHandCard -g unittesthandcard.c dominion.o rngs.o $(CFLAGS)

testGainCard: unittestgaincard.c dominion.o rngs.o
	gcc -o testGainCard -g unittestgaincard.c dominion.o rngs.o $(CFLAGS)

testIsGameOver: unittestisgameover.c dominion.o rngs.o
	gcc -o testIsGameOver -g unittestisgameover.c dominion.o rngs.o $(CFLAGS)

testGetCost: unittestgetcost.c dominion.o rngs.o
	gcc -o testGetCost -g unittestgetcost.c dominion.o rngs.o $(CFLAGS)

cardTestSmithy: cardtestSmithy.c dominion.o rngs.o
	gcc -o cardTestSmithy -g cardtestSmithy.c dominion.o rngs.o $(CFLAGS)

cardTestAdventurer: cardtestadventurer.c dominion.o rngs.o
	gcc -o cardTestAdventurer -g cardtestadventurer.c dominion.o rngs.o $(CFLAGS)

cardTestGreatHall: cardtestgreathall.c dominion.o rngs.o
	gcc -o cardTestGreatHall -g cardtestgreathall.c dominion.o rngs.o $(CFLAGS)

cardTestRemodel: cardtestremodel.c dominion.o rngs.o
	gcc -o cardTestRemodel -g cardtestremodel.c dominion.o rngs.o $(CFLAGS)

RandomCardTestAdventur: randomcardtestadventur.c dominion.o rngs.o
	gcc -o randomtestAdventurer -g randomcardtestadventur.c dominion.o rngs.o $(CFLAGS)

RandomCardTestSmithy: randomcardtestsmithy.c dominion.o rngs.o
	gcc -o randomTestSmithy -g randomcardtestsmithy.c dominion.o rngs.o $(CFLAGS)

randomtestadventurer.out: RandomCardTestAdventur
	./randomtestAdventurer &> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

randomtestcard.out: RandomCardTestSmithy
	./randomTestSmithy &> randomtestcard.out
	gcov dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out


all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so unittestresult.out
