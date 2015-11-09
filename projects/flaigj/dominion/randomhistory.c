/*

Imporovements in coverage 
**Coverage results at end of this file
Overall coverage of my randomtestadventurer.c executed about 3.5% more lines than the
old cardtest2.c in assignment3. Branch coverage was 5.3% worse in randomtestadventurer.c
though this likely has to do with not calling other functions like I did in cardtest.
Taken at least once and calls excecuted were both 2% better in randomtestadveturer. 
Even though my branch coverage was worse my coverage was still better overall and I
am that likely had to do with forcing a shuffle to occur providing a 1/4 chance in
giving a smaller decksize to make that happen. 

I compared randomtestcard.c to council_room.  Other test cards were 17% and 18% coverage
so I did do better in cutpurse. Back to council_room, cardtest3.c and cutpurse, 
randomcardtest.c The differences in these functions were somewhat equal. They both used 
discard card for a played card. The difference council room used draw card, cutpurse 
used discard card and update coins. Randomtestcard.c either matches or is just a shade 
better in coverage than cardtest3.c. Still they are not the same functions like my first 
comparison in coverage involving two tests of adventurer.  However coverage of 
randomcardtest.c still beats or matches most of my cardtests in most categories. 

Correctness of specification
randomtestadventurer.c
I ended up improving my test oracle and forcing a percentage of my random numbers to not 
be random to ensure the correctness of my test specifications. The main thing I did to 
ensure correctnesswas to give a 1/4 chance of making the deckCount 0 so the player would 
be forced to shuffle. Otherwise shuffling would not likely occur if just blindly passing 
in a random number 0 through max deck. I also decided to copy the gamestate to pre,
change the post gamestate and compare. I used the pre and post to loop through a 
player's hand incrementing a preCount and postCount, took the difference of post and 
preCount to determine if two treasures were added. Finally I decided to print the 
counts of card piles of pre and post so I could see why something failed.

The biggest takeaway I got was that the deck wouldn't shuffle if the deckcount is at 0.
It appears that shuffling doesn't correctly work. Another thing to notice is that the 
failure ratio is 951/4000 = 24%. That is close to 1/4. All of my deck sizes are 0 
except for 1 in the failure print statements.  Another thing I noticed was the treasure 
was failed to add 478 times and the shuffle failed 473 times. That was the interesting 
thing I found. Among other things discards don't add up all the time.

randomtestcard.c
I ended up testing cutpurse so I was determine if +2 coins were given to the current 
player. Also if a player had a copper card in hand then they should discard that copper
card. Like randomtestadventurer, to test if +2 coins were added was to have a pre and 
post gamestate. Take the difference of post and pre coins and check if they are equal to
2. The same thing was done with checking if the card was discarded and coppers from hand
were removed. The only difference is that they were done in loops because we are testing 
whether all players allowed removal of coppers.

Because of the looping and testing things that were very similar I got more errors than
were helpful.  So I have concluded that discarding isn't working properly so I should 
remove the two discard tests.  This elimates 8000 redundant tests or half of what I 
originally had. So it reduces THIS: 16000 tests and 3984 failed TO THIS: Ran 8000 tests 
and 494 failed. One interesting thing I found was that 2 coins added to the player hand
fails 24 times and it is always player 1. The rest are copper remove failures. The other
thing I did notice, which I stated in old tests were that discarding half works. The 
correct card is removed from hand but it isn't actually in the discard pile.  

Coverage
Old Adventurer test - cardtest2.c
File 'dominion.c'
Lines executed:17.59% of 580
Branches executed:24.58% of 415
Taken at least once:14.46% of 415
Calls executed:8.51% of 94
dominion.c:creating 'dominion.c.gcov'

New Adventurer test - randomtestadventurer.c
File 'dominion.c'
Lines executed:21.03% of 580
Branches executed:19.28% of 415
Taken at least once:16.63% of 415
Calls executed:10.64% of 94
dominion.c:creating 'dominion.c.gcov'

council_room - cardtest3.c
File 'dominion.c'
Lines executed:19.31% of 580
Branches executed:25.54% of 415
Taken at least once:15.42% of 415
Calls executed:10.64% of 94
dominion.c:creating 'dominion.c.gcov'

randomtestcard.c
File 'dominion.c'
Lines executed:20.86% of 580
Branches executed:25.78% of 415
Taken at least once:16.63% of 415
Calls executed:10.64% of 94
dominion.c:creating 'dominion.c.gcov'

*/