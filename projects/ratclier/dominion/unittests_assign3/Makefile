CFLAGS = -Wall -fpic -coverage -I.. -std=c99 -lm

default: tests.out

rngs.o: ../rngs.c
	gcc -c ../rngs.c -g  $(CFLAGS)

dominion.o: ../dominion.c rngs.o
	gcc -c ../dominion.c -g  $(CFLAGS)

cardtest1: cardtest1.c unittest_helpers.o dominion.o rngs.o
	gcc -o cardtest1 -g cardtest1.c unittest_helpers.o dominion.o rngs.o $(CFLAGS)

cardtest2: cardtest2.c unittest_helpers.o dominion.o rngs.o
	gcc -o cardtest2 -g cardtest2.c unittest_helpers.o dominion.o rngs.o $(CFLAGS)

cardtest3: cardtest3.c unittest_helpers.o dominion.o rngs.o
	gcc -o cardtest3 -g cardtest3.c unittest_helpers.o dominion.o rngs.o $(CFLAGS)

cardtest4: cardtest4.c unittest_helpers.o dominion.o rngs.o
	gcc -o cardtest4 -g cardtest4.c unittest_helpers.o dominion.o rngs.o $(CFLAGS)

unittest_helpers.o: unittest_helpers.c
	gcc -c unittest_helpers.c -g  $(CFLAGS)

unittest1: unittest1.c unittest_helpers.o dominion.o rngs.o
	gcc -o unittest1 -g unittest1.c unittest_helpers.o dominion.o rngs.o $(CFLAGS)

unittest2: unittest2.c unittest_helpers.o dominion.o rngs.o
	gcc -o unittest2 -g unittest2.c unittest_helpers.o dominion.o rngs.o $(CFLAGS)

unittest3: unittest3.c unittest_helpers.o dominion.o rngs.o
	gcc -o unittest3 -g unittest3.c unittest_helpers.o dominion.o rngs.o $(CFLAGS)

unittest4: unittest4.c unittest_helpers.o dominion.o rngs.o
	gcc -o unittest4 -g unittest4.c unittest_helpers.o dominion.o rngs.o $(CFLAGS)

tests.out: cardtest1.c cardtest2.c cardtest3.c cardtest4.c unittest1.c unittest2.c unittest3.c unittest4.c unittest_helpers.c ../dominion.c ../rngs.c
	echo "Result for running dominion.c tests:\n" > ../unittestresults.out
	
	echo ">>> START OF unittest1.c:" >> ../unittestresults.out
	gcc -o unittest1 -g unittest1.c unittest_helpers.c ../dominion.c ../rngs.c $(CFLAGS)
	./unittest1 >> ../unittestresults.out
	echo ">>> COVERAGE: dominion.c after unittest1:" >> ../unittestresults.out
	gcov -fb dominion.c >> ../unittestresults.out
	echo ">>> END OF unittest1.c\n" >> ../unittestresults.out
	echo "\n" >> ../unittestresults.out

	echo ">>> START OF unittest2.c:" >> ../unittestresults.out
	gcc -o unittest2 -g unittest2.c unittest_helpers.c ../dominion.c ../rngs.c $(CFLAGS)
	./unittest2 >> ../unittestresults.out
	echo ">>> COVERAGE: dominion.c after unittest2:" >> ../unittestresults.out
	gcov -fb dominion.c >> ../unittestresults.out
	echo ">>> END OF unittest2.c\n" >> ../unittestresults.out
	echo "\n" >> ../unittestresults.out

	echo ">>> START OF unittest3.c:" >> ../unittestresults.out
	gcc -o unittest3 -g unittest3.c unittest_helpers.c ../dominion.c ../rngs.c $(CFLAGS)
	./unittest3 >> ../unittestresults.out
	echo ">>> COVERAGE: dominion.c after unittest3:" >> ../unittestresults.out
	gcov -fb dominion.c >> ../unittestresults.out
	echo ">>> END OF unittest3.c\n" >> ../unittestresults.out
	echo "\n" >> ../unittestresults.out

	echo ">>> START OF unittest4.c:" >> ../unittestresults.out
	gcc -o unittest4 -g unittest4.c unittest_helpers.c ../dominion.c ../rngs.c $(CFLAGS)
	./unittest4 >> ../unittestresults.out
	echo ">>> COVERAGE: dominion.c after unittest4:" >> ../unittestresults.out
	gcov -fb dominion.c >> ../unittestresults.out
	echo ">>> END OF unittest4.c\n" >> ../unittestresults.out
	echo "\n" >> ../unittestresults.out

	echo ">>> START OF cardtest1.c:" >> ../unittestresults.out
	gcc -o cardtest1 -g cardtest1.c unittest_helpers.c ../dominion.c ../rngs.c $(CFLAGS)
	./cardtest1 >> ../unittestresults.out
	echo ">>> COVERAGE: dominion.c after cardtest1:" >> ../unittestresults.out
	gcov -fb dominion.c >> ../unittestresults.out
	echo ">>> END OF cardtest1.c\n" >> ../unittestresults.out
	echo "\n" >> ../unittestresults.out

	echo ">>> START OF cardtest2.c:" >> ../unittestresults.out
	gcc -o cardtest2 -g cardtest2.c unittest_helpers.c ../dominion.c ../rngs.c $(CFLAGS)
	./cardtest2 >> ../unittestresults.out
	echo ">>> COVERAGE: dominion.c after cardtest2:" >> ../unittestresults.out
	gcov -fb dominion.c >> ../unittestresults.out
	echo ">>> END OF cardtest2.c\n" >> ../unittestresults.out
	echo "\n" >> ../unittestresults.out

	echo ">>> START OF cardtest3.c:" >> ../unittestresults.out
	gcc -o cardtest3 -g cardtest3.c unittest_helpers.c ../dominion.c ../rngs.c $(CFLAGS)
	./cardtest3 >> ../unittestresults.out
	echo ">>> COVERAGE: dominion.c after cardtest3:" >> ../unittestresults.out
	gcov -fb dominion.c >> ../unittestresults.out
	echo ">>> END OF cardtest3.c\n" >> ../unittestresults.out
	echo "\n" >> ../unittestresults.out

	echo ">>> START OF cardtest4.c:" >> ../unittestresults.out
	gcc -o cardtest4 -g cardtest4.c unittest_helpers.c ../dominion.c ../rngs.c $(CFLAGS)
	./cardtest4 >> ../unittestresults.out
	echo ">>> COVERAGE: dominion.c after cardtest4:" >> ../unittestresults.out
	gcov -fb dominion.c >> ../unittestresults.out
	echo ">>> END OF cardtest4.c\n" >> ../unittestresults.out

clean:
	rm ../unittestresults.out

cleanall: 
	rm ../unittestresults.out cardtest1 cardtest2 cardtest3 cardtest4 unittest1 unittest2 unittest3 unittest4 *.gcda *.gcno *.gcov



