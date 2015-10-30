CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: randomtestcard.out

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

randomtestcard.out: randomtestcard.c dominion.o rngs.o
	echo "Result for running random tests:" > randomtestcard.out
	
	gcc -o randomtestcard -g randomtestcard.c dominion.o rngs.o $(CFLAGS)
	./randomtestcard >> randomtestcard.out
	gcov randomtestcard.c -b >> randomtestcard.out
	cat randomtestcard.c.gcov >> randomtestcard.out

randomtestadventurer.out:  randomtestadventurer.c dominion.o  rngs.o
	echo "Result for running random tests: " > randomtestadventurer.out

	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
	./randomtestadventurer >> randomtestadventurer.out
	gcov randomtestadventurer.c -b >> randomtestadventurer.out
	cat randomtestadventurer.c.gcov >> randomtestadventurer.out
	

clean:
	rm randomtestadventurer.out randomtestcard.out

cleanall: 
	rm randomtestadventurer.out randomtestcard.out randomtestcard randomtestadventurer *.gcda *.gcno *.gcov
