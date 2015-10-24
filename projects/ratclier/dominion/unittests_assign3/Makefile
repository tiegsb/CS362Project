CFLAGS = -Wall -fpic -coverage -I.. -std=c99 -lm

default: tests.out

rngs.o: ../rngs.c
	gcc -c ../rngs.c -g  $(CFLAGS)

dominion.o: ../dominion.c rngs.o
	gcc -c ../dominion.c -g  $(CFLAGS)

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

tests.out: unittest1.c unittest2.c unittest3.c unittest4.c unittest_helpers.c ../dominion.c ../rngs.c
	echo "Result for running dominion.c tests:\n" > tests.out
	
	echo ">>> START OF unittest1.c:" >> tests.out
	gcc -o unittest1 -g unittest1.c unittest_helpers.c ../dominion.c ../rngs.c $(CFLAGS)
	./unittest1 >> tests.out
	echo ">>> END OF unittest1.c\n" >> tests.out
	echo "Coverage: unittest1:" >> tests.out
	gcov dominion.c >> tests.out
	echo "\n" >> tests.out

	echo ">>> START OF unittest2.c:" >> tests.out
	gcc -o unittest2 -g unittest2.c unittest_helpers.c ../dominion.c ../rngs.c $(CFLAGS)
	./unittest2 >> tests.out
	echo ">>> END OF unittest2.c\n" >> tests.out
	echo "Coverage: unittest2:" >> tests.out
	gcov dominion.c >> tests.out
	echo "\n" >> tests.out

	echo ">>> START OF unittest3.c:" >> tests.out
	gcc -o unittest3 -g unittest3.c unittest_helpers.c ../dominion.c ../rngs.c $(CFLAGS)
	./unittest3 >> tests.out
	echo ">>> END OF unittest3.c\n" >> tests.out
	echo "Coverage: unittest3:" >> tests.out
	gcov dominion.c >> tests.out
	echo "\n" >> tests.out

	echo ">>> START OF unittest4.c:" >> tests.out
	gcc -o unittest4 -g unittest4.c unittest_helpers.c ../dominion.c ../rngs.c $(CFLAGS)
	./unittest4 >> tests.out
	echo ">>> END OF unittest4.c\n" >> tests.out
	echo "Coverage: unittest4:" >> tests.out
	gcov dominion.c >> tests.out
	echo "\n" >> tests.out

clean:
	rm tests.out

cleanall: 
	rm tests.out unittest1 unittest2 unittest3 unittest4 *.gcda *.gcno *.gcov



