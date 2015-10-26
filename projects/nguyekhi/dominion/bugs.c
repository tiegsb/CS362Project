/*
unittest1.c: No bug
- I write the test for initializedGame() function. First I test the function with the invalid and valid inputs and check the return values of the function
to see if they produced the expected output result. If I pass in an invalid input and the function return 0, this indicate that there are something wrong with
the function, and further examination need to take place. This is black box testing technique. However I also incorporate white testings, as I check through
the process of each line execution. For example, I check whether the function handle the duplicate kingdom cards properly, I check if the function initialize
the corrected number of cards for certain specific cards like curse, gardens, great_hall, etc. I cover a lot of tests for initializedGame() function.
In the end, the function passes all the tests and I can confirm it is working properly

unittest2.c: No bug
- The test for getCost() function is quiet simple. I just run getCost() function with all the possible inputs and make sure it return the corrected value of
the input. I also research and make sure the cost of the input are corrected in the header file. I also test the invalid input and make sure the function
return -1.

unittest3.c: No bug
- I write the test for shuffle() function. I test the valid and invalid input of player, and check the return value of the function. I also check the
unshuffle rate of the function to see if the position of the card in the deck change or not. If the unshuffle rate is 100% that means the shuffle() function
doesn't work properly

unittest4.c: No bug
- I test 3 functions at the same time, numHandCards(), handCard(), and supplyCount() functions. I feel like these are small functions so I test them all
- For function numHandCards(), I initialize the game, then check the return value of numHandCards() function. Since I just initialize the game, the
numHandCards() should return 5 to pass, otherwise the function fail. And then I execute drawcard() function, and execute numHandCards() function again,
as the result numHandCards(0) function return properly, at the same time I kind of passively test the drawCard() function. They seem to be working properly
- For function handCard(), after I initialize the game, I check all the cards in the hand. Since they only contain estate and copper, if any card in hand are
something else beside copper and estate, the function handCard() fail
- For function supplyCount(), some cards have some specific supply, so I check them to see if the supplyCount() function return the corrected value for the
supply of the input cards. I also check the supply of the card that are not in the game to make sure the function return -1.

**** Now is the interesting part, I found more bug in cardTest *****
cardtest1.c: 2 bugs
1. The smithy() function give the player 4 cards instead of 3
2. in the smithy function, it does discard the smithy card, but the discard pile do not have any card, this also indicate that there is bug in the
discardCard() function

cardtest2.c: 4 bugs
1. while (drawntreasure <= 2), it will draw 3 treasure cards instead of 2. So it should be drawntreasure < 2
2. cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]]; It should be state->handCount[currentPlayer] - 1. this execution is trying to
access the last card in hand by using the handCount. However the array start at 0, so the last card is hand[handSize - 1], not the handSize.
3. while(z >=0), and tempHand[z], it should be z - 1 >= 0, and tempHand[z-1]. the first tempHand[z] is null. This is the bugs that I introduce
4. The major bug in this function is it does not discard the adventurer card.

cardtest3.c: 2 bugs
1. I switch the number of card draw (4) of the current player with the number of player. If the game has 4 players, it might pass the test
2. I switch the number of player that draw 1 card to 4 instead of the number of player in the game. Again if the number of player in the game is 4, the bug
will not trigger
I kind of like this bug

cardtest4.c: 1 bug
1. The current player increase it's numBuys by 1, where it should be increase numActions by 1

*/
