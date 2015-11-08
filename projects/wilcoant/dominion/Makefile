CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: tests

tests: randomtestadventurer.c randomtestcard.c rngs.c dominion.c
	gcc -c rngs.c -g  $(CFLAGS)
	gcc -c dominion.c -g  $(CFLAGS)
	
	echo "Results for running dominion.c tests:" > randomtestadventurer.out
	echo "randomtestadventurer.c:" >> randomtestadventurer.out
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
	randomtestadventurer >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	
	echo "randomtestcard.c:" >> randomtestcard.out
	gcc -o randomtestcard -g randomtestcard.c dominion.o rngs.o $(CFLAGS)
	randomtestcard >> randomtestcard.out
	gcov dominion.c >> randomtestcard.out
	
clean:
	rm randomtestadventurer.out randomtestcard.out

cleanall: 
	rm randomtestcard randomtestadventurer randomtestadventurer.out randomtestcard.out *.gcda *.gcno *.gcov
