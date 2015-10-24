/*
Rachael McConnell
CS362 Fall 2015
Assignment 3

All of my branches had 100% coverage. This is probably because most of my if statements have an else statement, so one of those conditions is met no matter what. My line execution is lower, ranging from 85.29% to 95.74%. Most of the lines that weren’t executed were ones that printed out pass or fail statements.

My code did not test the majority of dominion.c. Overall, only 20.00% of the lines were executed. There are many card functions that my testing did not cover at all, since I only tested 4 of the cards. Testing more of the card functions would have helped to increase coverage. In order to get more coverage, it also would have been helpful to test more of the frequently used functions, such as drawCard, scoreFor, and buyCard.

****Dominion.c
	Lines executed: 20.00% of 575
	Branches executed: 22.78% of 417
	Taken at least once: 14.15% of 417
	Calls executed: 10.53% of 95 


****Unittest1.c	
	Lines executed 87.72% of 57
	Branches executed 100.00% of 18
	Taken at least once: 72.22% of 18
	Calls executed: 76.47% of 17
	
	Lines not executed:
    	#####:   70:      printf("Shuffle function did not run.\n");
    	#####:   80:      otherPlayersDeck++;
    	#####:   88:      printf("Fail: Player 0's deck has not been shuffled.\n");
    	#####:   89:      count++;
    	#####:   95:      printf("Fail: Player 1's deck has been shuffled.\n");
    	#####:   96:      count++;
    	#####:  106:      printf("%d tests failed\n", count);
	In this test, lines having to do with failed tests did not get executed since all tests passed.

	Lines executed in dominion.c: 15.83% of 575

****Unittest2.c	
       Lines executed: 95.74% of 47
       Branches executed: 100.00% of 12
	Taken at least once: 83.33% of 12
	Calls executed: 88.24% of 17
	
	Lines not executed:
    	#####:   50:    printf("Fail: Wrong number of coins.\n");
    	#####:   84:    printf("%d updateCoins tests failed\n", returned);
	This test is similar to the first unit test. Only lines corresponding to a failed test did not get executed.

	Lines executed in dominion.c: 16.00% of 575
	
****Unittest3.c	
       Lines executed 95.08% of 61
       Branches executed: 100.00% of 16
	Taken at least once: 81.25% of 16
	Calls executed: 95.45% of 22
	
	Lines not executed:
	#####:  100:    num1++;
    	#####:  102:    num2++;
    	#####:  111:    printf("All isGameOver tests passed!\n");
	In unittest3.c, some errors were found so the line stating that all tests passed did not execute. Lines 100 and 102 only run when province card is randomly selected from the list of cards. Since it was not selected this time, these lines did not run.

	Lines executed in dominion.c: 17.39% of 575

****Unittest4.c	
       Lines executed 85.29% of 68
       Branches executed: 100.00% of 16
	Taken at least once: 56.25% of 16
	Calls executed: 81.25% of 32

	
	Lines not executed:
	#####:   37:    errors++;
    	#####:   38:    printf("Fail: wrong handCount.\n");
    	#####:   46:    errors++;
    	#####:   47:    printf("Fail: wrong playedCardCount\n");
    	#####:   51:    printf("Pass: correct discardCount\n");
    	#####:   62:    printf("Fail: wrong playedCardCount\n");
    	#####:   63:    errors++;
    	#####:   68:    printf("Pass: correct discardCount\n");
    	#####:   77:    return 0;
    	#####:  110:    printf("\nAll discardCard tests passed!\n");
	Only some tests passed in this unit test, so there are a variety of pass and fail print statements that did not execute. When a test was passed and the ‘Pass’ statement printed out, the line to print out the ‘Fail statement’ and the line incrementing errors both would not execute. We see this with lines 37/38, 46/47, and 62/63.

	Lines executed in dominion.c: 17.57% of 575

****Cardtest1.c	
       Lines executed 91.37% of 139
       Branches executed: 100.00% of 58
	Taken at least once: 75.86% of 58
	Calls executed: 88.89% of 54

	Lines not executed:
	#####:   41:    smithyCards++;
    	#####:  112:    printf("Fail: ");
    	#####:  113:    errors++;
    	#####:  120:    printf("Fail: ");
    	#####:  121:    errors++;
    	#####:  136:    printf("Fail: ");
    	#####:  137:    errors++;
    	#####:  144:    printf("Fail: ");
    	#####:  145:    errors++;
    	#####:  154:    printf("Fail: Supply count changed.\n");
    	#####:  160:    return 1;
    	#####:  217:    printf("%d smithyCard tests failed.\n", returned);
	All tests passed in this card test, so the only lines that were not executed were ones corresponding to a failed test.

	Lines executed in dominion.c: 18.43% of 575

****Cardtest2.c	
       Lines executed 88.62% of 123
       Branches executed: 100.00% of 72
	Taken at least once: 81.94% of 72
	Calls executed: 85.29% of 34

	Lines not executed:
	#####:   76:    duchyCards++;
    	#####:   91:    adventurerCards++;
    	#####:   97:    duchyCards++;
    	#####:  122:    duchyCards++;
    	#####:  130:    printf(" Fail: ");
    	#####:  131:    errors++;
    	#####:  137:    printf(" Fail: ");
    	#####:  138:    errors++;
    	#####:  150:    printf(" Pass: Adventurer card was discarded.\n");
    	#####:  161:    printf(" Fail: ");
    	#####:  162:    errors++;
    	#####:  170:    adventurerCards++;
    	#####:  176:    duchyCards++;
    	#####:  183:    printf("All adventurerCard tests passed!\n");
	The pattern continues with cardtest2.c. The lines that were not executed are ones corresponding to passing or failing a test. Lines 76, 91, 97, 122, and 176 show that there were no duchy or adventurer cards found in the player’s deck or hand at this point in the test. 

	Lines executed in dominion.c: 17.22% of 575

****Cardtest3.c	
       Lines executed 90.21% of 143
       Branches executed: 100.00% of 62
	Taken at least once: 74.19% of 62
	Calls executed: 89.09% of 55

	Lines not executed:
	#####:   29:    smithyCards++;
    	#####:   45:    smithyCards++;
    	#####:   55:    council_roomCards++;
    	#####:  156:    printf("Fail: ");
    	#####:  157:    errors++;
    	#####:  164:    printf("Fail: ");
    	#####:  165:    errors++;
    	#####:  181:    errors++;
    	#####:  185:    printf("Fail: ");
    	#####:  186:    errors++;
    	#####:  193:    printf("Fail: ");
    	#####:  194:    errors++;
    	#####:  204:    printf("Fail: Supply count was changed.\n");
    	#####:  214:    printf("%d council_roomCard tests failed\n", errors);
	All tests passed in cardtest3.c so the majority of lines that weren’t executed are ones that print out ‘Fail’ statements.

	Lines executed in dominion.c:19.13% of 575

****Cardtest4.c	
       Lines executed 91.49% of 141
       Branches executed: 100.00% of 58
	Taken at least once: 75.86% of 58
	Calls executed: 88.33% of 60
	
	Lines not executed:
	#####:   42:    villageCards++;
    	#####:  156:    printf("Fail: ");
    	#####:  157:    errors++;
    	#####:  164:    printf("Fail: ");
    	#####:  165:    errors++;
    	#####:  188:    printf("Pass: ");
    	#####:  193:    printf("Fail: ");
    	#####:  194:    errors++;
    	#####:  201:    printf("Fail: ");
    	#####:  202:    errors++;
    	#####:  212:    printf("Fail: Supply count was changed.\n");
    	#####:  221:    printf("All villageCard tests passed\n");
	Some tests failed in this test. Most lines not executed either print out ‘Pass’ or ‘Fail’, or increment the number of errors found.

	Lines executed in dominion.c: 20.00% of 575

*/

