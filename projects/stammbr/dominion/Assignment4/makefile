CFLAGS = -Wall -fpic -coverage -lm 

randomtestcard.out: randomtestcard.c dominion.c rngs.c
	echo "Result for running random tests:" > randomtestcard.out
	
	gcc -o randomtestcard randomtestcard.c dominion.c rngs.c $(CFLAGS)
	./randomtestcard >> randomtestcard.out
	gcov dominion.c -b -c >> randomtestcard.out

randomtestadventurer.out:  randomtestadventurer.c dominion.c  rngs.c
	echo "Result for running random tests: " > randomtestadventurer.out
	
	gcc -o randomtestadventurer randomtestadventurer.c dominion.c rngs.c $(CFLAGS)
	./randomtestadventurer >> randomtestadventurer.out
	gcov dominion.c -b -c >> randomtestadventurer.out
	
run_all:
	./randomtestadventurer
	./randomtestcard

clean:
	rm randomtestadventurer.out randomtestcard.out

cleanall: 
	rm randomtestadventurer.out randomtestcard.out randomtestcard randomtestadventurer *.gcda *.gcno *.gcov
