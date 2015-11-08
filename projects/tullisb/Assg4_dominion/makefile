CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: randomtestadventurer.out randomtestcard.out

randomtestadventurer.out: randomtestadventurer.c
	echo "Results of Unit Tests and Card Tests:" > randomtestadventurer.out
	echo "" >> randomtestadventurer.out
	
	echo "randomtestcard.c:" >> randomtestcard.out
	gcc -o randomtestcard -g  randomtestcard.c dominion.c rngs.c $(CFLAGS)
	./randomtestcard >> randomtestcard.out 2>&1
	gcov randomtestcard.c >> randomtestcard.out

	echo "randomtestadventurer.c:" >> randomtestadventurer.out
	gcc -o randomtestadventurer -g  randomtestadventurer.c dominion.c rngs.c $(CFLAGS)
	./randomtestadventurer >> randomtestadventurer.out 2>&1
	gcov randomtestadventurer.c >> randomtestadventurer.out

clean:
	rm -f randomtestadventurer.out randomtestcard.out

cleanall: 
	rm -f randomtestadventurer.out randomtestadventurer randomtestcard.out randomtestcard *.gcda *.gcno *.gcov