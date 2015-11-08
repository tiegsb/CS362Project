CFLAGS = -Wall -fpic -coverage -I.. -I../unittests_assign3 -std=c99 -lm

default: tests.out

rngs.o: ../rngs.c
	gcc -c ../rngs.c -g  $(CFLAGS)

dominion.o: ../dominion.c rngs.o
	gcc -c ../dominion.c -g  $(CFLAGS)

unittest_helpers.o: ../unittests_assign3/unittest_helpers.c
	gcc -c ../unittests_assign3/unittest_helpers.c -g  $(CFLAGS)

randomtestadventurer: randomtestadventurer.c unittest_helpers.o dominion.o rngs.o
	gcc -o randomtestadventurer -g randomtestadventurer.c unittest_helpers.o dominion.o rngs.o $(CFLAGS)

tests.out: randomtestadventurer.c ../dominion.c ../rngs.c
	echo "RESULTS FOR RUNNING ADVENTURER CARD RANDOM TESTS:\n\n" > ../randomtestadventurer.out

	echo ">>> START OF randomtestadventurer.c:" >> ../randomtestadventurer.out
	gcc -o randomtestadventurer -g randomtestadventurer.c ../unittests_assign3/unittest_helpers.c ../dominion.c ../rngs.c $(CFLAGS)
	./randomtestadventurer >> ../randomtestadventurer.out
	echo "\n\n>>> COVERAGE: dominion.c after randomtestadventurer:\n" >> ../randomtestadventurer.out
	gcov -fb dominion.c >> ../randomtestadventurer.out
	echo ">>> END OF randomtestadventurer.c\n" >> ../randomtestadventurer.out
	echo "\n" >> ../randomtestadventurer.out

clean:
	rm ../randomtestadventurer.out

cleanall: 
	rm ../randomtestadventurer.out randomtestadventurer *.gcda *.gcno *.gcov

