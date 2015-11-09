First, I wanted to make sure there were random game states with each iteration of the
random test, and did so by writing the randomGameState() function. The function begins
by randomizing the supply counts for each of the victory and treasure card piles.
This function assumes two players, and begins with a for loop which runs once for each
player. 

Each player has a random deck count which can range from 0 to the Maximum Deck count
constant. The deck is filled with random action cards until the deck count is reached.
After the deck is filled, a random amount of treasure cards is added to complete the
deck.

Finally, 5 cards are drawn, so the player has 5 cards in their current hand.

The random tests center around an infinite while loop, a counter, the
initializeGame() function, and the aformentioned randomGameState() function.

During each iteration, the game is first initialized and then set into a random
state. For the Adventurer card, a player is randomly chosen, and the random game
state is passed into the adventurerFunct() refactored function to peform the
adventurer action. For the Smithy card, a player and a hand position are randomly 
chosen, and these random variables are passed into the smithyFunct() function in
addition to the random game state.

The tests run continouously until the loop breaks due to an error or the user manually
breaks the program using a command.

Initially, I was only receiving iterations up to around 200 on my tests. After
debugging the test file, I noticed that there were instances of where one of my
variables was dividing by 0 due to the random number generator creating instances
of a number where zero was the lower bound. To fix (and further refine the test) I
made sure to add 1 to the random number to ensure that dividing by zero cannot
occur and break the test unintentionally.
