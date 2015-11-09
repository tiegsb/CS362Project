CFLAGS = -Wall -fpic -coverage -I.. -I../unittests_assign3 -std=c99 -lm

default: tests.out

rngs.o: ../rngs.c
	gcc -c ../rngs.c -g  $(CFLAGS)

dominion.o: ../dominion.c rngs.o
	gcc -c ../dominion.c -g  $(CFLAGS)

unittest_helpers.o: ../unittests_assign3/unittest_helpers.c
	gcc -c ../unittests_assign3/unittest_helpers.c -g  $(CFLAGS)

randomtest_helpers.o: randomtest_helpers.c
	gcc -c randomtest_helpers.c -g  $(CFLAGS)

randomtestadventurer: randomtestadventurer.c unittest_helpers.o dominion.o rngs.o randomtest_helpers.o
	gcc -o randomtestadventurer -g randomtestadventurer.c unittest_helpers.o dominion.o rngs.o randomtest_helpers.o $(CFLAGS)

randomtestcard: randomtestcard.c unittest_helpers.o dominion.o rngs.o randomtest_helpers.o
	gcc -o randomtestcard -g randomtestcard.c unittest_helpers.o dominion.o rngs.o randomtest_helpers.o $(CFLAGS)

tests.out: randomtestadventurer.c ../dominion.c ../rngs.c randomtest_helpers.c
	echo "RESULTS FOR RUNNING ADVENTURER CARD RANDOM TESTS:\n\n" > ../randomtestadventurer.out

	echo ">>> START OF randomtestadventurer.c:" >> ../randomtestadventurer.out
	gcc -o randomtestadventurer -g randomtestadventurer.c ../unittests_assign3/unittest_helpers.c ../dominion.c ../rngs.c randomtest_helpers.c $(CFLAGS)
	./randomtestadventurer >> ../randomtestadventurer.out
	echo "\n\n>>> COVERAGE: dominion.c after randomtestadventurer:\n" >> ../randomtestadventurer.out
	gcov -fb dominion.c >> ../randomtestadventurer.out
	echo ">>> END OF randomtestadventurer.c\n" >> ../randomtestadventurer.out
	echo "\n" >> ../randomtestadventurer.out

teststreasuremap.out: randomtestcard.c ../dominion.c ../rngs.c randomtest_helpers.c
	echo "RESULTS FOR RUNNING TREASURE MAP CARD RANDOM TESTS:\n\n" > ../randomtestcard.out

	echo ">>> START OF randomtestcard.c:" >> ../randomtestcard.out
	gcc -o randomtestcard -g randomtestcard.c ../unittests_assign3/unittest_helpers.c ../dominion.c ../rngs.c randomtest_helpers.c $(CFLAGS)
	./randomtestcard >> ../randomtestcard.out
	echo "\n\n>>> COVERAGE: dominion.c after randomtestcard:\n" >> ../randomtestcard.out
	gcov -fb dominion.c >> ../randomtestcard.out
	echo ">>> END OF randomtestcard.c\n" >> ../randomtestcard.out
	echo "\n" >> ../randomtestcard.out

clean:
	rm ../randomtestadventurer.out ../randomtestcard.out

cleanall: 
	rm ../randomtestadventurer.out ../randomtestcard.out randomtestadventurer randomtestcard *.gcda *.gcno *.gcov

