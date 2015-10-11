//Documentation 

/*
Smithy card cost 4 coins. It is an action card that allow you to draw 3 more cards from your deck. 
So the basic code algorithm for this card is:
if you choose to play smithy card, you will then execute the drawcard() function 3 times to draw 3 more cards
and then execute discardCard() function to discard the smithy card from your hand
*/ 

/*
adventurer card cost 6 coins. It is an action card that allow you to draw until you get 2 treasure cards and put them into your hand.
So the basic code algorithm for this card is:
the variable drawntreasure initially start at 0, while the drawntreasure token is less than 2, you will execute drawCard() function, 
since the drawCard() function already take care of the case where deck is empty, i don't know why the case adventurer do it again?
If you draw into treasure cards (such as copper, silver or gold), you put that treasure card into your hand and the drawntreasure token 
will increase by 1. Otherwise it will put the drawn card into temporary hand. Once the drawntreasure token = 2, the loop exit and discard 
all the cards in the temporary hand
*/

/*
I don't quiet understand the description of the discardCard() function in both dominion.c and dominion-base architecture
I mean The effect of the card is already execute in playcard() function
The function discardCard have 4 parameters: int handPos, int currentPlayer, struct gameState *state, int trashFlag
IT will check the validation of the card base on the value of the trashFlag input. If the trashFlag < 1, which means the card is not trashed, 
it could be action or treasure cards, so we add it to the played card pile (add it to playedCards array and increment its size). Set the 
I think something wrong with the discardCard() function in dominion.c. I also think the description of the discardCard() function
in dominion-base architecture also weird
First I wonder if discardCard() function discard one card at a time or discard all the cards in hand
So I get the reference from the smithy card, I assume that discardCard() function would discard all the cards in hand
If that the case then, discardCard() function should check each card, whether or not they are trash cards which mean they have no use/value,
you just remove it from hand and put it in the discard pile and decrease the handCount by 1. However if the discard is treasure card, 
you have to update the current coins base on the value of that treasure card. You keep loop through all the cards on your hand
*/

/*
int updateCoins(int player, struct gameState *state, int bonus)
Ok this function is pretty clear and make a lot of sense. So the input are player, gameState and bonus.
we have a loop that go through all the cards in hand. If the card is treasure cards you add its value (copper = 1, silver = 2, gold = 3) 
to coins variable. Once you are done, you add the input bonus to get the total current coins you have, so you can buy province or action card 
or treasure cards
After I write the description for this function I realize that, discardCard() function should just put all the cards from hand into the discard pile
after call updateCoins() function because the treasure cards have no value now.
*/

