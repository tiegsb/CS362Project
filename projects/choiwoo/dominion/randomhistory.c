//Woo Choi
//randomhistory.c
//Write up and check in the development of provided random testers.

I wanted to test for adventurer and smithy.
First I thought this assignment would be really easy.
My thought was that I just had to loop through my unit tests from assignment 3. 
So I did that. 
Then I realized it was not random at all. All it did was to repeat the test multiple times.
So this meant I had to put in a random factor into random tests.

I struggled with this idea. How do I make this random??
I failed to make it random. But I decided to use the playdom.c to test.
It was great because playdom had 2 players who only bought smithy or adventurer.
Two cards that I planned on writing random tests for.
Then I realized playdom wasn't random either. 

So I went back to the original idea. I added a for loop that runs the code for numTestRun amount
of times, which can be modified. Then I gave it some conditions.
game will be refreshed every 3 rounds of testing: refreshGame ==3
give a random chance, rand() % 2 == 1, to gain a card
It doesn't matter what card it is. Its purpose is to increase the number of cards in hand
Then I test smithy or adventurer and compare the number of cards in hand afterwards.
At the end of the test, it will list out number of successful runs and failed runs
and also the times that the card wasn't used.

Expectations:
	Both Smithy and Adventurer will have bugs. They were the cards that I added bugs
	to for a previous assignment. So, they will always have failed tests.

Problem with Testing:
	For adventurer, I did not thoroughly test if the card is actually working correctly. 
	I only tested for the result. If working correctly, it will give 2 treasure card
	to hand. I compared the number of cards in hand after adventurer was used. 
	This doesn't test for discarded nontreasure cards, and also if the process 
	of treasure card function is actually working correctly.

