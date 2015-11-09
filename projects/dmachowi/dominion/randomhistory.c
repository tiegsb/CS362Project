Drew Machowicz
machowid - dmachowi
November 8, 2015 

randomtestadventurer -

randomtestadventurer.c
Testing playAdventurer Card..
File 'randomtestadventurer.c'
Lines executed:94.74% of 57
Branches executed:100.00% of 30
Taken at least once:63.33% of 30
Calls executed:92.31% of 13


I started to make this test first and I followed the idea
from the lecture video. This means that I made a struct of gameState and just
filled it in with randome chars. However, this does not work by itself because
the adventurer card expects some somewhat sane gameState to work with. So after
filling the struct with random data, I  then fixed some of the 
struct properties to be within range. I made the deckCount, discardCount, and 
handCount all random number between 0 and MAX_DECK which is 500, and the 
handCount between 0 and MAX_HAND which is also 500. I also set the number of 
players. After initializing the struct for the game I then sent the struct to 
a function where I test it. First I created a copy of the same struct being 
sent and I used the copy as a base to compare with the struct that was sent to 
the playAdventurerCard function. I checked the struct that was sent against 
what the struct SHOULD be after going through that function and compared them. 
I checked the treasure count of the hand before and after being called and compared
them. There should be 2 more treasure cards in the hand if all goes well. I checked
the handCount before and after. There should be one more card in the hand becuase you
are taking 2 treasures but discarding the adventurer card. I also checked that
handCount + discardCount + deckCount is the same before and after playing this
card as no new cards are added to your deck. Finally I used memcmp to compare
the two structs, as they should be exactly the same. Of course all the tests
fail because I am running against the adventurer card that I introduced bugs to
before. I had a really hard time getting this one to work because I kept having segfaults
and I couldn't find the reason why. Finally I ended up using gdb and stepping through the
code one bit at time. Here I found that one of my variables was causing the program to access
data elements past the end of the array. This is because the loop is supposed to run until 2
treasure cards are drawn, but since the whole struct is full of gibberish it didn't come accross
any treasure cards and it just kept running until it crashed. To counter this I added a bit of 
code that says the counter can not go above MAX_HAND. I also had to move the placement of the 
counter increment to prevent another segfault. Once I changed these pieces the program compiled 
and ran as expected. After running the test I found out that about 95% of the lines were executed, 
with 100% branch execution. Also 63.3% of them were taken at lest once and 92.31% of calls were 
executed. 

randomtestcard -

randomtestcard.c
Testing Smithy Card..
File 'randomtestcard.c'
Lines executed:97.50% of 40
Branches executed:100.00% of 14
Taken at least once:85.71% of 14
Calls executed:93.33% of 15


I decided to go with the smithy card for this random test. This one went a lot more smoothly than 
the first one as there were fewer things to test. I followed the same advice from the lecture
and created the structs in the same way as I did with the other test. The only difference is
that I also had to put in a random num for the hand position as smithy requires the hand position
to work correctly. In the testing fuction I made a copy of the struct to compare it to the original
after going through the playSmithyCard call. For this one I just need to test that the hand has two
more cards than before. Smithy allows the player to draw three cards but they also need to discard
the played smithy card. So that means they will have a net gain of 2 cards. I also checked the discard
piles of the two structs. They should have the same number of cards in them. I also checked to make sure
the handCount and deckCounts were equal. After running the tests I saw that 97.5% of the lines were
executed and 100% of branches were executed with 85.7% of them being taken at least once. Also 93.3% of
calls were executed. 
