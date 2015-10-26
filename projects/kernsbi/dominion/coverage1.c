Billy Kerns
coverage1.c


File 'unittest1.c'
scoreFor() function
Lines executed:93.98% of 83
Branches executed:100.00% of 62
Taken at least once:95.16% of 62
Calls executed:85.00% of 20
Dominion code coverage: 5.72%

#####:   64:                        printf("Failed on test #%d\n", n);
#####:   65:                        printf("Memcmp failed\n");
#####:   67:                        errorFlag++;
#####:   71:                printf("All tests passed\n");
#####:  152:                return -2;


For unittest1 I wrote test cases to check the scoreFor() function inside dominion.c. 

Lines executed: 
	93.98% of my lines inside unittest1.c ran. Three of the lines that were not executed were due to the program finding an error
	and exiting the test function early since we knew it would fail anyway.  The other line that was not run was due to the 
	program finding an error so it did not print "All tests passed".  This essentially means all lines that were expected to 
	run did.  I believe this was achieved by running a for loop a 1000 times that randomized the gameState each time creating
	many different scenarios for the code to test.  

Branches executed:
	With all these random cards be being added to player's hand, deck, and discard at random I was able to achieved 100% branch
	coverage. This was mainly due to almost all of my branches checking for what card was drawn.  

Taken at least once: 
	The reason the taken at least once is not 100% is because of an if statement that checks for an error count and if that 
	error count is 0 then print "All tests passed". Since there is an error in the scoreFor() function this never happens. 

Calls executed:
	Calls executed is less than 100% thanks to calls to printf not happening because of the error in scoreFor(). 

Dominion code coverage: 
	Dominion code coverage is relativly low but this is to be expected since instead of initializing the game I just filled the
	gameState with junk and only changed the things that were needed by the scoreFor() function.  This combined with the low
	amount of lines in scoreFor lead to a low amount of code coverage in dominion.c.  

Implications:
	Even with the low code coverage the test suite still did it's job in finding an error.  After correcting the error scoreFor()
	worked exactly as it should passing the test cases.


File 'unittest2.c'
fullDeckCount() function
Lines executed:86.36% of 44
Branches executed:100.00% of 22
Taken at least once:86.36% of 22
Calls executed:77.78% of 18
Dominion code coverage: 1.56%

#####:   70:                        printf("Iteration #: %d Test 1 failed\n", n);
#####:   71:                        printf("Expected count: %d      Actual count: %d\n", count, newCount);
#####:   73:                        errorCount++;
#####:   77:                        printf("Test #: %d failed", n);
#####:   78:                        printf("Memcmp failed");
#####:   80:                        errorCount++;

For unittest2 I wrote test cases to check the fullDeckCount() function inside dominion.c.

Lines executed:
	I was able to achieve 86.36% statement coverage with the only lines not running being a couple error counters and some printfs
	with error messages.  Thanks to fullDeckCount not having any errors these were never ran.  

Branches executed:
	100% branch coverage was achieved due to all branches being either a check for a correct count of a certain card, a memcmp,
	and a check for an error count.  

Taken at least once:
	Taken at least once coverage is 86.36% because two paths are not taken.  These paths are for when fullDeckCount() returns a
	number different than what the program was expecting and when memcmp fails.  Since fullDeckCount() has no errors these two
	path were never taken.  However, Changing fullDeckCount() to be wrong does induce a trip down these paths.  

Calls executed:
	Calls executed is at 77.78%.  Four printf statements are never ran since they are on error paths.

Dominion code coverage:
	Like in unittest1 I did not initialize the gameState with the dominion code but by filling it with junk and then modifying
	the pieces that were relevant to the fullDeckCount() function.  This combined with the relativly small size of the code in 
	fullDeckCount() lead to poor dominion code coverage.

Implications:
	All types of coverage were good leading me to believe that fullDeckCount() works as it should.


File 'unittest3.c'
discardCard() function
Lines executed:73.44% of 64
Branches executed:100.00% of 32
Taken at least once:71.88% of 32
Calls executed:60.71% of 28
Dominion code coverage: 2.08%

#####:   55:                printf("All tests passed\n");
#####:   71:                printf("Iteration #%d   Test 1 failed.\n", n);
#####:   72:                printf("DiscardCard function failed\n");
#####:   74:                errorCount++;
#####:   79:                printf("Iteration #%d   Test 2 failed.\n", n);
#####:   80:                printf("The player's hand does not end with -1.\n");
#####:   82:                errorCount++;
#####:   86:                printf("Iteration #%d   Test 3 failed.\n", n);
#####:   87:                printf("Expected handCount: %d  Actual handCount: %d\n", pre.handCount[p]-1, post->handCount[p]);
#####:   89:                errorCount++;
#####:   93:                printf("Iteration #%d   Test 4 failed.\n", n);
#####:   94:                printf("Expected playedCardCount: %d    Actual playedCardCount: %d\n", pre.playedCardCount + 1, post->playedCardCount);
#####:   96:                errorCount++;
#####:  116:                pre.handCount[p]--;
#####:  126:                printf("Iteration #%d   Test 6 failed.\n", n);
#####:  127:                printf("Memcmp failed\n");
#####:  129:                errorCount++;

For unittest3 I wrote test cases to check the discardCard() function inside dominion.c. 

Lines executed:
	Like the previous tests the majority of the lines that were not ran are due to error counts not being incremented because 
	certain errors did not occur.  One of the other two lines that did not run is due to a test case failing which prints out 
	an error message instead of "All tests passed".  The last line that does not run is more of a mystery.  This line comes from 
	the discardCard() function and I was using it to implement my own discardCard code.  No matter what I did I could not get 
	this code to run.  I'm relativly certain I could remove this code with no ill effects which I think shows the usefulness of
	gcov for things other than did this test case run.  

Branches executed:
	100% branch was achieved by the majority of my branches just being checks for correct output after running the discardCard()
	function.  With the rest being a check for error count and if statements for doing my own discardCard code.

Taken at least once:
	Taken at least once is low due to a lot of if statements checking for correct output.  Since the majority of the outputs from
	discardCard() are correct these paths are usually not followed with the exception on the stray line of code of mentioned earlier
	that I cannot get to run and the if statement for "All tests passed".

Calls executed:
	All calls are executed except for calls to printf to print "All test passed" and error messages for errors that never
	happened.

Dominion card coverage:
	Again I did not use the initialize game function so the only code from dominion.c that I used was the discardCard() function.
	Since this is a rather large function it pushed my dominion code coverage up from the previous tests.

Implications:
	With general code coverage high the test suite was able to detect and report an error in the discardCard() function.  If my 
	test coverage would have been lower this error might hae gone unnoticed.  If we were to fix the error in discardCard() we 
	could have a reasonable amount of confidence in discardCard() working like it should.


File 'unittest4.c'
Lines executed:75.00% of 72
Branches executed:100.00% of 34
Taken at least once:79.41% of 34
Calls executed:45.45% of 22
Dominion code coverage: 1.91%

#####:   94:                        printf("Iteration #%d   Test 1 failed.\n", n);
#####:   95:                        printf("Expected coin total: %d Actual coin total: %d\n", G.coins, post.coins);
#####:   97:                        errorCount++;
#####:  101:                        printf("Iteration #%d   Test 2 failed.\n", n);
#####:  102:                        printf("Coins after updateCoins() does not equal local coin holder variable.\n");
#####:  104:                        errorCount++;
#####:  108:                        printf("Iteration #%d   Test 3 failed.\n", n);
#####:  109:                        printf("Expected copper coins: %d       Actual copper coins: %d\n", copperCoins, postCopperCoins);
#####:  111:                        errorCount++;
#####:  115:                        printf("Iteration #%d   Test 4 failed.\n", n);
#####:  116:                        printf("Expected silver coins: %d       Actual silver coins: %d\n", silverCoins, postSilverCoins);
#####:  118:                        errorCount++;
#####:  122:                        printf("Iteration #%d   Test 5 failed.\n", n);
#####:  123:                        printf("Expected gold coins: %d Actual gold coins: %d\n", goldCoins, postGoldCoins);
#####:  125:                        errorCount++;
#####:  129:                        printf("Iteration #%d   Test 6 failed.\n", n);
#####:  130:                        printf("Memcmp failed\n");
#####:  132:                        errorCount++;


For unittest4 I wrote test cases to check the updateCoins() function inside dominion.c. 

Lines executed:  
	I was able to get 75.00% statement coverage in unittest4.  Since my test suite could not detect any errors in updateCoins() 
	the only lines that were not run were error counters and a printf to print error message.  This means that all my test
	scenarios were ran.

Branches executed:
	I achieved 100% branch coverage thanks to all of my branches being checks for correct output and error flags.  

Taken at least once:
	Taken at least once is 79.41% with the remaining 20.59% being error paths that will not run due to updateCoins() being
	implemented correctly.

Calls executed:
	All call were executed except for the printfs that print out error messages.  Since the test suite did not find any
	errors, these was never run.

Dominion code coverage:
	Again I did not use the initialize game function so the only code from dominion.c that I used was the updateCoins() function.
	This is a pretty small function meaning dominion code coverage is also small.

Implications:
	With all coverage being high I can reasonably say all my test scenarios were ran and that updateCoins() works as intended.

File 'cardtest1.c'
Lines executed:79.17% of 96
Branches executed:91.89% of 74
Taken at least once:78.38% of 74
Calls executed:60.71% of 28
Dominion code coverage: 19.41%

#####:   73:                printf("All tests passed\n");
#####:   95:                printf("Iteration # %d Test 1 failed. Hand count was not incremented 3 times\nExpected: handCount = %d  Actual: handCount = %d\n\n", n, pre->handCount[turn]+2, post.handCount[turn]);
#####:   97:                errors++;
#####:  101:                printf("Iteration # %d Test 2 failed. Deck count was not decremented 3 times\nExpected: deckCount = %d  Actual: deckCount = %d\n\n", n, pre->deckCount[turn]-3, post.deckCount[turn]);
#####:  103:                errors++;
#####:  126:                        printf("Iteration # %d Test 3 failed. Card received was not in deck\n\n", n);
#####:  128:                        errors++;
#####:  135:                                printf("Iteration # %d Test 4 failed. Other players hand counts were changed\nExpected: Player %d handCount = %d       Actual: Player %d handCount = %d\n\n", n, i, pre->handCount[i], i, post.handCount[i]);
#####:  137:                                errors++;
#####:  143:                        if(i != turn){
#####:  145:                                printf("Iteration # %d Test 5 failed. Other players discard counts were changed\nExpected: Player %d discardCount = %d Actual: Player %d discardCount = %d\n\n", n, i, pre->discardCount[i], i, post.discardCount[i]);
#####:  147:                                errors++;
#####:  155:                                printf("Iteration # %d Test 6 failed. Other players deck counts were changed\nExpected: Player %d deckCount = %d       Acutal: Player %d deckCount = %d\n\n", n, i, pre->deckCount[i], i, post.deckCount[i]);
#####:  157:                                errors++;
#####:  165:                                printf("Iteration #: %d Test 7 failed\n", n);
#####:  166:                                printf("Expected: Hand of unused player to be the same  Actual: Hand of unused player is not the same\n");
#####:  168:                                errors++;
#####:  182:                                printf("Iteration #: %d Test 8 failed\n", n);
#####:  183:                                printf("Expected: Player %d treasure_map = 1    Actual: Player %d treasure_map = %d\n", i, i, postCount);
#####:  185:                                errors++;


For cardtest1 I wrote test cases to check the smithy card inside dominion.c.

Lines executed:
	For cardtest1 I had statement coverage of 79.17% with the majority of the code that is not covered coming from error 
	counters that were never tripped and a printfs that lets us know if tests failed.  Thanks to a user implemented error this
	is exactly what we are expecting.  Line 143 is never run due to the previously mentioned error in the discardCard() function.

Branches executed:
	Branches executed is lower here than for all of my unittests due to some more complicated error paths that have if statements
	and for loops buried within some other if statements and for loops.  If the first error condition is not met then it will never
	get to the secondary ones with these statements...I think.

Taken at least once:
	Taken at least once is also low due to the same reasons as branches executed being low.  Some branches will never be traveled
	unless a certain error show up.  If that error does not show up then these branches are not traveled which brings down the 
	taken at least once percentage.

Calls executed:
	The only calls that are not executed are the calls to printf() to tell the user a test failed and the call to tell the user
	all tests passed.  All tests did not pass so this is expected.

Dominion code coverage:
	Dominion code coverage is higher for this test since I used the initialize game function from dominion.c which uses a lot of 
	code.  This combined with the code in smithyCard() makes up a fair chunk of code in dominion.c.

Implications:
	Looking at the low percent of branches executed and taken at least once lets me know that I probably should have seperated some
	of my error checking statements better to ensure that they run.  On the other side of this it also lets me know that the error
	condition required to create the secondary error never happens.


File 'cardtest2.c'
Lines executed:65.96% of 94
Branches executed:67.50% of 80
Taken at least once:60.00% of 80
Calls executed:53.33% of 30
Dominion code coverage: 22.53%

#####:  108:                                printf("Iteration #: %d Test 1 failed\n", n);
#####:  109:                                printf("Expected: Player %d handCount = %d      Actual: Player %d handCount = %d\n", t, pre->handCount[t], t, post.handCount[t]);
#####:  111:                                funErrors++;
#####:  117:                                printf("Iteration #: %d Test 3 failed\n", n);
#####:  118:                                printf("Expected: Player %d discardCount = %d   Actual: Player %d discardCount = %d\n", t, pre->discardCount[t], t, post.discardCount[t]);
#####:  120:                                funErrors++;
#####:  126:                                printf("Iteration #: %d Test 4 failed\n", n);
#####:  127:                                printf("Expected: Player %d deckCount = %d      Actual: Player %d deckCount = %d\n", t, pre->deckCount[t], t, post.deckCount[t]);
#####:  129:                                funErrors++;
#####:  141:                                printf("Iteration #: %d Test 5 failed\n", n);
#####:  142:                                printf("Expected: Player %d treasure_map = 1    Actual: Player %d treasure_map = %d\n", t, t, postCount);
#####:  144:                                funErrors++;
#####:  149:                for(i=0; i < pre->deckCount[currentPlayer]; i++){
#####:  150:                        if(pre->deck[currentPlayer][i]==copper || pre->deck[currentPlayer][i]==silver || pre->deck[currentPlayer][i]==gold){
#####:  151:                                deckPreTreasure++;//check to see how many treasure cards are in deck
#####:  154:                for(i=0; i < pre->discardCount[currentPlayer]; i++){
#####:  155:                        if(pre->discard[currentPlayer][i]==copper || pre->discard[currentPlayer][i]==silver || pre->discard[currentPlayer][i]==gold){
#####:  156:                                deckPreTreasure++;//check to see how many treasure cards are in discard
#####:  159:                if(deckPreTreasure >= 2){//if we found more than two treasure then we have an error
#####:  160:                        if(post.handCount[currentPlayer] != pre->handCount[currentPlayer]+2){
#####:  162:                                printf("Iteration #: %d Test 6 failed\n", n);
#####:  163:                                printf("Expected: handCount = %d        Actual: handCount = %d\n", pre->handCount[currentPlayer]+2, post.handCount[currentPlayer]);
#####:  165:                                funErrors++;
#####:  168:                else if(deckPreTreasure == 1){//if only one treasure is found then player hand count should go up by one
#####:  169:                        if(post.handCount[currentPlayer] != pre->handCount[currentPlayer]+1){
#####:  171:                                printf("Iteration #: %d Test 7 failed\n", n);
#####:  172:                                printf("Expected: handCount = %d        Actual: handCount = %d\n", pre->handCount[currentPlayer]+1, post.handCount[currentPlayer]);
#####:  174:                                funErrors++;
#####:  177:                else if(deckPreTreasure !=0){//else something went wrong
#####:  179:                        printf("Iteration #: %d Test 8 failed\n", n);
#####:  180:                        printf("Expected: Post treasure = %d    Actual: Post treasure = %d\n", treasure+2, postTreasure);
#####:  182:                        funErrors++;

For cardtest2 I wrote test cases to check the adventurer card inside dominion.c.

Lines executed:
	65.96% of cardtest2 was executed while the code that was not executed is mainly printfs for errors that never occured and 
	some if statements that would only be triggered by a very rare circumstance that was not caught in the 10 iterations of my
	tests.

Branches executed:
	Branches executed is low due to a test case that does not come up very often which holds a lot of if statements.  Since this
	scenario does not come up in only 10 iterations these if statements are never run leading to poor branch coverage.

Taken at left once:
	The 40.00% that is not executed at least once is due to the reasons listed in branches executed.

Calls executed:
	Like before the only calls not executed are for printfs to let the user know about an error.

Dominion code coverage:
	Dominion code coverage is higher for this test since I used the initialize game function from dominion.c which uses a lot of 
	code.  This combined with the code in adventureCard() makes up a fair chunk of code in dominion.c.

Implications:
	This was an interesting test suite.  My orriginal test cause a seg fault and after digging around I discovered a couple bugs
	in the adventurer card that had to be fixed before my code would even run.  I also discovered a bug that I was not even testing
	for which let me know even though my coverage was pretty good it does not mean there are no bugs.


File 'cardtest3.c'
Lines executed:73.42% of 79
Branches executed:90.48% of 42
Taken at least once:71.43% of 42
Calls executed:58.06% of 31
Dominion code coverage: 21.32%

#####:   75:                printf("All tests passed\n");
#####:   91:                printf("Iteration #:%d  Test 1 failed\n", n);
#####:   92:                printf("Expected: cardCount = %d        Actual: cardCount = %d\n", pre->handCount[currentPlayer], post.handCount[currentPlayer]);
#####:   94:                funErrors++;
#####:   98:                printf("Iteration #:%d  Test 2 failed\n", n);
#####:   99:                printf("Expected: numActions = %d       Actual: numActionst = %d\n", pre->numActions + 2, post.numActions);
#####:  101:                funErrors++;
#####:  112:                        if(t != currentPlayer){//if current player then it's probably different
#####:  114:                                printf("Iteration #: %d Test 4 failed\n", n);
#####:  115:                                printf("Expected: Player %d handCount = %d      Actual: Player %d handCount = %d\n", t, pre->handCount[t], t, post.handCount[t]);
#####:  117:                                funErrors++;
#####:  121:                        if(t != currentPlayer){
#####:  123:                                printf("Iteration #: %d Test 5 failed\n", n);
#####:  124:                                printf("Expected: Player %d discardCount = %d   Actual: Player %d discardCount = %d\n", t, pre->discardCount[t], t, post.discardCount[t]);
#####:  126:                                funErrors++;
#####:  132:                                printf("Iteration #: %d Test 6 failed\n", n);
#####:  133:                                printf("Expected: Player %d deckCount = %d      Actual: Player %d deckCount = %d\n", t, pre->deckCount[t], t, post.deckCount[t]);
#####:  135:                                funErrors++;
#####:  147:                                printf("Iteration #: %d Test 7 failed\n", n);
#####:  148:                                printf("Expected: Player %d treasure_map = 1    Actual: Player %d treasure_map = %d\n", t, t, postCount);
#####:  150:                                funErrors++;


For cardtest3 I wrote test cases to check the village card inside dominion.c.

Lines executed:
	The lines that are not executed are mainly printfs and error counters that only run when certain errors are found.  Since 
	these errors were not found the lines were never ran.

Branches executed:
	The branches executed percentage is low due to some branches being within error branches that are not being traveled.  These are
	mainly for testing that other players hands and etc... have not been changed.  It does not meet the first condition so the program
	does not bother checking for the rest.

Taken at least once:
	The low percentage of taken an least once is due to the reasons in branches executed.

Calls executed:
	The only calls not executed are printfs to let the user know if a test failed certain tests and when all test passed.  

Dominion code coverage:
	Dominion code coverage is relativly high for because the initialize game function is used.  This accounts for most of the dominion
	code coverage as the village card does not have a lot of code.

Implications:
	With good test coverage I think that this test suite can be counted on to give us accurate results when testing the village card.
	After fixing the discardCard() function the village card passes all my tests so we can reasonably say that this card does what
	it is supposed to do.

File 'cardtest4.c'
Lines executed:68.18% of 88
Branches executed:87.50% of 48
Taken at least once:66.67% of 48
Calls executed:51.43% of 35
Dominion code coverage: 19.58%

#####:   76:                printf("All tests passed\n");
#####:   91:                printf("Iteration #:%d  Test 1 failed\n", n);
#####:   92:                printf("Expected: cardCount = %d        Actual: cardCount = %d\n", pre->handCount[currentPlayer], post.handCount[currentPlayer]);
#####:   94:                funErrors++;
#####:   98:                printf("Iteration #:%d  Test 2 failed\n", n);
#####:   99:                printf("Expected: numActions = %d       Actual: numActionst = %d\n", pre->numActions + 1, post.numActions);
#####:  101:                funErrors++;
#####:  105:                printf("Iteration #:%d  Test 3 failed\n", n);
#####:  106:                printf("Expected: Played great_hall card to be removed  Actual: Played great_hall card was not removed\n");
#####:  108:                funErrors++;
#####:  120:                        if(t != currentPlayer){//if current player it probably will be different
#####:  122:                                printf("Iteration #: %d Test 5 failed\n", n);
#####:  123:                                printf("Expected: Player %d handCount = %d      Actual: Player %d handCount = %d\n", t, pre->handCount[t], t, post.handCount[t]);
#####:  125:                                funErrors++;
#####:  129:                        if(t != currentPlayer){
#####:  131:                                printf("Iteration #: %d Test 6 failed\n", n);
#####:  132:                                printf("Expected: Player %d discardCount = %d   Actual: Player %d discardCount = %d\n", t, pre->discardCount[t], t, post.discardCount[t]);
#####:  134:                                funErrors++;
#####:  140:                                printf("Iteration #: %d Test 7 failed\n", n);
#####:  141:                                printf("Expected: Player %d deckCount = %d      Actual: Player %d deckCount = %d\n", t, pre->deckCount[t], t, post.deckCount[t]);
#####:  143:                                funErrors++;
#####:  147:                        if(t != currentPlayer){
#####:  149:                                printf("Iteration #: %d Test 8 failed\n", n);
#####:  150:                                printf("Expected: Hand of unused player to be the same  Actual: Hand of unused player is not the same\n");
#####:  152:                                funErrors++;
#####:  164:                                printf("Iteration #: %d Test 9 failed\n", n);
#####:  165:                                printf("Expected: Player %d treasure_map = 1    Actual: Player %d treasure_map = %d\n", t, t, postCount);
#####:  167:                                funErrors++;



For cardtest4 I wrote test cases to check the great hall card inside dominion.c.

The same as cardtest3.c as the only difference is great hall gives a player +1 actions instead of +2 actions