#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dominion.c"
#include "rngs.c"
#include <time.h>


void randomSetup(struct gameState *game){
    int i, j, handSize, card;
    game->numPlayers = (1 + (rand() % 3)); //random # of players between 2 and 4
    for(i=0; i < 26; i++){
        game->supplyCount[i] = (rand() % 10); //all cards have random supply between 0 - 9
    }
    //outpostPlayed not relivant
    //outpostTurn not relivant
    game->whoseTurn = (rand() % (game->numPlayers)); //random players turn
    game->phase = 0;
    game->numActions = (rand() % 5);    //random # of actions between 0 - 4
    game->coins = (rand() % 8);     //random # of coins between 0 - 7
    game->numBuys = (rand() % 4);   //random # of buys between 0 - 3
    for(i=0; i < game->numPlayers; i++){
        handSize = (rand() % 9);     //random sized hand between 0 - 8
        for(j=0; j < handSize; j++){
            card = (rand() % 27);
            game->hand[i][j] = card;    //random cards in hand
        }
        game->handCount[i] = handSize;
    }
    for(i=0; i < game->numPlayers; i++){
        handSize = (rand() % 40);     //random sized deck between 0 - 39
        for(j=0; j < handSize; j++){
            card = (rand() % 27);
            game->deck[i][j] = card;    //random cards in deck
        }
        game->deckCount[i] = handSize;
    }
    for(i=0; i < game->numPlayers; i++){
        handSize = (rand() % 40);     //random sized discard between 0 - 39
        for(j=0; j < handSize; j++){
            card = (rand() % 27);
            game->discard[i][j] = card;    //random cards in discard
        }
        game->discardCount[i] = handSize;
    }
    game->playedCardCount = (rand() % 8);    //player played between 0 - 7 cards already
    for(i=0; i < game->playedCardCount; i++){
        game->playedCards[i] = (rand() % 27);   //randomply assigned cards already played
    }
}

int randTestAdventurer(){
    //create game state, and local variables of game state to compare after running adventurer()
    struct gameState* game = malloc(sizeof(struct gameState));
    int numPlayers,
        supplyCount[27],
        //outpostPlayed,
        //outpostTurn,
        whoseTurn,
        phase,
        numActions,
        coins,
        numBuys,
        hand[4][40],
        handCount[4],
        deck[4][40],
        deckCount[40],
        discard[4][40],
        discardCount[4],
        playedCards[40],
        playedCardCount,
        i,
        j,
        offset,
        error = 0;
    
    randomSetup(game);
    //make local variables = game variables
    numPlayers = game->numPlayers;
    for(i=0; i<27; i++){
        supplyCount[i] = game->supplyCount[i];
    }
    whoseTurn = game->whoseTurn;
    phase = game->phase;
    numActions = game->numActions;
    coins = game->coins;
    numBuys = game->numBuys;
    for(i=0; i<numPlayers; i++){
        for(j=0; j<game->handCount[i]; j++){
            hand[i][j] = game->hand[i][j];
        }
        handCount[i] = game->handCount[i];
    }
    for(i=0; i<numPlayers; i++){
        for(j=0; j<game->deckCount[i]; j++){
            deck[i][j] = game->deck[i][j];
        }
        deckCount[i] = game->deckCount[i];
    }
    for(i=0; i<numPlayers; i++){
        for(j=0; j<game->discardCount[i]; j++){
            discard[i][j] = game->discard[i][j];
        }
        discardCount[i] = game->discardCount[i];
    }
    for(i=0; i<game->playedCardCount; i++){
        playedCards[i] = game->playedCards[i];
    }
    playedCardCount = game->playedCardCount;

    //add council room card at the end of each hand and increment handCount for each player.
    game->hand[whoseTurn][game->handCount[game->whoseTurn]] = 8;
    hand[whoseTurn][handCount[whoseTurn]] = 8;
    game->handCount[game->whoseTurn] += 1;
    handCount[whoseTurn] += 1;
    
    council_roomF(game, handCount[whoseTurn]);

    //check numPlayers
    if(numPlayers != game->numPlayers){
        printf("Number of players was %d, and now it is %d\n", numPlayers, game->numPlayers);
        error = 1;
    }
    //check all supply counts
    for(i=0; i<27; i++){
        if(supplyCount[i] != game->supplyCount[i]){
            printf("Supply of card %d was %d, and is now %d\n", i, supplyCount[i], game->supplyCount[i]);
            error = 1;
        }
    }
    //check WhoseTurn
    if(whoseTurn != game->whoseTurn){
        printf("It was player %d's turn, and now it is %d's turn\n", whoseTurn, game->whoseTurn);
        error = 1;
    }
    //check for numActions
    if(numActions != game->numActions){
        printf("The player had %d actions, but now has %d actions\n", numActions, game->numActions);
        error = 1;
    }
    //check coins
    if(coins != game->coins){
        printf("The player had %d coins, but now has %d coins\n", coins, game->coins);
        error = 1;
    }
    //check if numBuy was incremented.
    if(numBuys+1 != game->numBuys){
        printf("The player had %d buys, but now has %d buys\n", numBuys, game->numBuys);
        error = 1;
    }
    //check for hand counts +4 for whoseturn, and +1 for others
    for(i=0; i<numPlayers; i++){
        if(i == whoseTurn){
            if(handCount[i] != (game->handCount[i] - 4)){ //THE PLAYER SHOULD NOW HAVE 2 EXTRA CARDS
                printf("Player %d's hand size was %d, and is now %d. There should be a +4 increase in hand size.\n", i, handCount[i], game->handCount[i]);
                error = 1;
            }
        } else {
            if(handCount[i] != (game->handCount[i] - 1)){
                printf("Player %d's hand size was %d, and is now %d. There should be a +1 increase in hand size.\n", i, handCount[i], game->handCount[i]);
            }
        }
    }
    for(i=0; i<numPlayers; i++){
        if(i == whoseTurn){
            offset = 4;
        } else {
            offset = 1;
        }
        if((deckCount[i]+discardCount[i])-offset != (game->deckCount[i]+game->discardCount[i])){
            printf("On player %d's turn, player %d had %d cards not in hand, now there are %d\n", whoseTurn, i, deckCount[i]+discardCount[i], game->deckCount[i]+game->discardCount[i]);
            error = 1;
        }
    }
    if(playedCardCount != game->playedCardCount){
        printf("Played card count was %d, and is now %d\n", playedCardCount, game->playedCardCount);
        error = 1;
    }
    if(error == 1){
        printf("\n\nGAME SETUP\n\nPlayers:%d\nCurrent turn:%d\n", numPlayers, whoseTurn);
        for(i=0; i<numPlayers; i++){
            printf("Player %d's hand before was ", i);
            for(j=0; j<handCount[i]; j++){
                printf("%d,",hand[i][j]);
            }
            printf("\n");
        }
        for(i=0; i<game->numPlayers; i++){
            printf("After adventure, player %d's hand was ", i);
            for(j=0; j<game->handCount[i]; j++){
                printf("%d,",game->hand[i][j]);
            }
            printf("\n");
        }
        for(i=0; i<numPlayers; i++){
            printf("Player %d had %d cards in discard pile, and %d cards in deck\n", i, discardCount[i], deckCount[i]);
        }
        for(i=0; i<numPlayers; i++){
            offset = 0;
            printf("Dump of deck and discard of player %d before Council Room:", i);
            for(j=0; j<discardCount[i]; j++){
                if(discard[i][j] == 4 || discard[i][j] == 5 || discard[i][j] == 6){
                    offset += 1;
                }
                printf("%d,", discard[i][j]);
            }
            for(j=0; j<deckCount[i]; j++){
                if(deck[i][j] == 4 || deck[i][j] == 5 || deck[i][j] == 6){
                    offset += 1;
                }
                printf("%d,", deck[i][j]);
            }
            printf("\nPlayer %d had %d treasure cards to draw 2 from\n", i, offset);
        }

        for(i=0; i<game->numPlayers; i++){
            printf("Dump of deck and discard of player %d after Council Room:", i);
            for(j=0; j<game->discardCount[i]; j++){
                printf("%d,", game->discard[i][j]);
            }
            for(j=0; j<game->deckCount[i]; j++){
                printf("%d,", game->deck[i][j]);
            }
            
        }
    }
    return error;
}


int main(){
    int i, fails, total;
    fails = 0;
    total = 100;
    srand(time(NULL));
    for(i=1; i < total; i++){
        fails += randTestAdventurer();
    }
    printf("Council Room failed %d times out of %d\n", fails, total);
    return 0;
}