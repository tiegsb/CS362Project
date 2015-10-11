Bugs Introduced




Adventurer:
Removed line that removes top card from hand.

	else{
            temphand[z]=cardDrawn;
            state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
            z++;
        }

    					vvvvvvvvvvvvv

	else{
            temphand[z]=cardDrawn;					//this should just remove the top card (the most recently drawn one).
            z++;
        }





Great Hall:
Removed line that discards the card from hand.


	//discard card from hand
    discardCard(handPos, currentPlayer, state, 0); // REMOVED




Salvager:
Changed if statement from choice1 to choice2.

	if (choice1)
    {
        //gain coins equal to trashed card
        state->coins = state->coins + getCost( handCard(choice1, state) );
        //trash card
        discardCard(choice1, currentPlayer, state, 1);
    }

    			vvvvvvvvvvvv

    if (choice2)
    {
        //gain coins equal to trashed card
        state->coins = state->coins + getCost( handCard(choice1, state) );
        //trash card
        discardCard(choice1, currentPlayer, state, 1);
    }




Smithy:
Changed for loop to have user draw four cards instead of three.
	for (i = 0; i = 3; i++)

     		vvvvvvvvv

	for (i = 0; i <= 3; i++)



Village:
Changed added actions from 1 to 2

	//+2 Actions
    state->numActions = state->numActions + 2;

    		vvvvvvvvvvv

    //+2 Actions
    state->numActions = state->numActions + 1;