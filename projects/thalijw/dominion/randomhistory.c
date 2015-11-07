CS_362_Software Engineering
Assignment #4
thalijw


Adventurer Random Test:

	I created a random test unit that starts with greating a game state, randomly generate a
a game state by filling the game with random numbers between (0-256), run the test fucntion which
does the following:

1- Copy the state of the game and save it for later comparison
2- Count the number of coins prior to playing the Adventurer card
3- Call the refactored function for playing the card effect
4- Count the number of coins after calling the card effect
5- Preform multipule steps on the saved game to try to copy the card effect
6- Compare the results of both game states on Handcount, deckCount, discardCount
and the total number of coins after playing the card

development:
	At first I initialized the Handcount, deckCount and discardCount to a fixed values, then I 
initilized the player's cards to be all "Copper" for tesing, but when I ran the test and looked 
at the coverage code, the edge case where (player.deckCount < 0) if the deck were empty never executed
and the shuffle function never executed either and I got a low coverage about 40% and all the test passed
along with failing when I tested if the two game states matched!

Then I went back and changed the input of the player's hand cards, deck cards annd discard cards to be 
totally random by selecting a random number between (0-20), Ran the test again and I got a better coverage
where the statement line coverage was 43.81 % and the branch coverage 54.92 %


The result of running the code for 1000 times are:

Number of matched game states = 70
Number of Not matched game states = 930
Number of matched Handcounts = 1000
Number of matched Deckcounts = 990
Number of matched Discardcounts = 990
Number of matched Coins = 1000

when I stepped throught the result of the coverage , and we executed the refactored function 100%
of time, and Inside the function we ran into the empty deck case 129 time out of a 1000 and also ran 
the suffle function.

Conclusion:

	I really got puzzeled at first why the two game states (pre and post) did not match for most of
tests, but then when I looked at the code, I think the reason we get matching handcounts and Deckcounts
but not matching game becasue of the shuffle function that ran in some of the code.
when we run the shuffle it randomly shuffle the postion of the card in the deck and thus we
get different game states.


Baron Random Test:

	I followed the same concept from the Adventurer card, by creating a game and randomly initializing 
the game state, I also initilized a random player, random handcout, deckCount and discardCount
then, I called a fucntion that create a new game state and copy the game state to it for later testing.

At First, I Hard coded the choice for the card to be Zero (where we take the action of discarding a estate card
and gain +4 coins to the total coins) , but when I did that I got branch coverage about %99 for branch 0 and 1% for
branch 1, then I looked at the code and half of the card code did not get covered in my test, so I decided to go 
deeper and randomize the choice of and limit it to 0 or 1.

After doing that I got a good coverage rates for the branches 0 and 1 with %52 and %48 and the final result
of my code coverage was:

Lines executed:51.70% of 646
Branches executed:63.07% of 417
Taken at least once:46.52% of 417

I ran the test 1000 times and got about 2/3 of the code with matching game states at the end of the test and 1/3 
where the game did not match.

 
