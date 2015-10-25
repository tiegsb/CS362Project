Brian Lamere
CS362_400
FA_15
24 OCT 2015

CODE COVERAGE - FUNCTIONS
1. updateCoins():
This function updates the gameState's coins variable based on the number of coin cards in the player's hand. It runs a for loop over the player's cards to determine which are coin cards (copper, silver, or gold) and updates the variable accordingly. Inside of the loop, there are 3 blocks of code, considering each of the 3 cards in turn. According to the coverage, it looks like a silver card has never been covered. But otherwise, every other statement has been covered. The function was called 38 times, updated the variable and returned successfully all 38 times (there are no error states (return -1) to consider.

2. buyCard():
Looks like this function has been called 24 times. Regarding statement coverage, each line (aside from the "if (DEBUG)" lines) is touched at least 6 times, with the exception of "return -1" on the first conditional, where state->numBuys < 1. So, of the 4 conditional blocks, that is the only which is never covered. The other 3 (when the card's supply is empty, when the player does not have enough coins, and the successful case) are all covered.

3. shuffle():
So this function creates a temporary deck for shuffling the player's deck. Looking at the code, this function was covered 126 times, and it returned successfully all 126 times. There is only one conditional branch, that returns with an error of -1, and that is if something tries to shuffle a deck of size 0 or less. Looks like this particular block never gets covered.

4. gainCard():
This function is called 54 times, and all lines and branches are covered. There is the situation where something tries to gain a card from an empty supply, and this is covered in 12 of the calls. Then for the rest of the cases, 3 blocks considering the 3 states of a tertiary flag that determines to which "pile" the gained card goes, are each covered a more-or-less equal amount of times.

CODE COVERAGE - CARDS
1. smithy: 
Simple function. Uses a for loop to draw 3 cards for the current player, then discards the smithy card from the hand. As far as coverage of statements/blocks, everything is touched in the use of this function.

2. village: 
Another simple function. It draws a card, adds 2 actions to the gameState's numActions variable, and discards the played card. There is no branching, and all lines of the function are covered when it's called.

3. council room: 
Every statement in the function for playing this card is covered. As things stand now, it is only called twice in my driver code. There are 2 for loops, one that draws 4 cards (this is covered 8 times, 4 times per call) and one that loops through the players in the game, drawing a card for each one of them. It has an if block for ignoring the current player (who drew cards earlier), and it is covered every time.


4. adventurer: 
Looks a few scenarios were not covered in the testing of this function. One involves setting a variable for marking the next player, which never even gets used in the function anyway, so useless to test. After the block that sets that variable, there is a while loop that continues until 2 "treasure" cards are drawn from the player's deck. Two if blocks inside that loop are considered: 1) if the deck becomes empty (at which point it gets shuffled (this never gets covered, per gcov)), and an if-else block that tests whether or not the drawn card is a "treasure" card. Because I have mostly been testing off of the initial state, players usually only have "treasure" cards, so it looks like the situations where a non-"treasure" card is drawn are not covered. (There is also a loop that throws those drawn non-"treasure" cards on the discard pile, but because they weren't drawn, this doesn't get covered.)




