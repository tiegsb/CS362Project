#include "unittestHelper.h"
#include "dominion.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



//------------------------------------------------------------

//------------------------------------------------------------
struct aChangeReturnVals aChange(struct gameState *copyState, struct gameState *newState)
{
	int i,j;
	struct aChangeReturnVals r;
	r.stateChange= -1;
	r.indexI= -1;
	r.indexJ= -1;

	if(copyState->numPlayers != newState->numPlayers)
	{ 
		r.stateChange= E_numPlayers;
		return r;
	}

	for(i=0; i<treasure_map+1; i++)
	{
		if(copyState->supplyCount[i] != newState->supplyCount[i])
		{
			r.stateChange= E_supplyCount;
			r.indexI= i;
			return r;
		}
	}
	
	for(i=0; i<treasure_map+1; i++)
	{
		if(copyState->embargoTokens[i] != newState->embargoTokens[i])
		{
			r.stateChange= E_embargoTokens;
			r.indexI= i;
			return r;
		}
	}

	if(copyState->outpostPlayed != newState->outpostPlayed)
	{
		r.stateChange= E_outpostPlayed;
		return r;
	}

	if(copyState->outpostTurn != newState->outpostTurn)
	{
		r.stateChange= E_outpostTurn;
		return r;
	}

	if(copyState->whoseTurn != newState->whoseTurn)
	{
		r.stateChange= E_whoseTurn;
		return r;
	}

	if(copyState->phase != newState->phase)
	{
		r.stateChange= E_phase;
		return r;
	}

	if(copyState->numActions != newState->numActions)
	{
		r.stateChange= E_numActions;
		return r;
	}

	if(copyState->coins != newState->coins)
	{
		r.stateChange= E_coins;
		return r;
	} 

	if(copyState->numBuys != newState->numBuys)
	{
		r.stateChange= E_numBuys;
		return r;
	}

	for(i=0; i<MAX_PLAYERS; i++)
	{
		for(j=0; j<MAX_HAND; j++)
		{
			if(copyState->hand[i][j] != newState->hand[i][j])
			{
				r.stateChange= E_hand;
				r.indexI= i;
				r.indexJ= j;
				return r;
			}
		}
	}

	for(i=0; i<MAX_PLAYERS; i++)
	{
		if(copyState->handCount[i] != newState->handCount[i])
		{
			r.stateChange= E_handCount;
			r.indexI= i;
			return r;
		}
	}

	for(i=0; i<MAX_PLAYERS; i++)
	{
		for(j=0; j<MAX_DECK; j++)
		{
			if(copyState->deck[i][j] != newState->deck[i][j])
			{
				r.stateChange= E_deck;
				r.indexI= i;
				r.indexJ= j;
				return r;
			}
		}
	}

	for(i=0; i<MAX_PLAYERS; i++)
	{
		if(copyState->deckCount[i] != newState->deckCount[i])
		{
			r.stateChange= E_deckCount;
			r.indexI= i;
			return r;
		}
	}

	for(i=0; i<MAX_PLAYERS; i++)
	{
		for(j=0; j<MAX_DECK; j++)
		{
			if(copyState->discard[i][j] != newState->discard[i][j])
			{
				r.stateChange= E_discard;
				r.indexI= i;
				r.indexJ= j;
				return r;		
			}
		}
	}

	for(i=0; i<MAX_PLAYERS; i++)
	{
		if(copyState->discardCount[i] != newState->discardCount[i])
		{
				r.stateChange= E_discardCount;
				r.indexI= i;
				return r;
		}
	}

	for(i=0; i<MAX_DECK; i++)
	{
		if(copyState->playedCards[i] != newState->playedCards[i])
		{
				r.stateChange= E_playedCards;
				r.indexI= i;
				return r;
		}
	}

	if(copyState->playedCardCount != newState->playedCardCount)
	{
				r.stateChange= E_playedCardCount;
				return r;
	}

	return r;
}

int printBadDiffs(struct gameState *copyState, struct gameState *afterCopy, int test[], int hand[], int hLen, int handCount[], int hcLen, int discard[], int diLen, int discardCount[], int dicLen, int deck[], int deLen, int deckCount[], int decLen)
{
	int i, flag;

	struct aChangeReturnVals aDiff= {-1,-1,-1};	

	do
	{
		//compare game state before endTurn is called, to after the call
		aDiff= aChange(copyState, afterCopy);
		flag= 0;

		switch(aDiff.stateChange)
		{
			case E_numPlayers:
				if(test[E_numPlayers]==0)  
				{
					printf("Error: numPlayers changed.\n"); 
					printf("numPlayers Before: %d\n", copyState->numPlayers);
					printf("numPlayers After: %d\n\n", afterCopy->numPlayers);				
				}
				afterCopy->numPlayers= copyState->numPlayers;
				break;

			case E_supplyCount: 
				if(test[E_supplyCount]==0)  
				{
					printf("Error: supplyCount changed.\n"); 
					printf("supplyCount of card#%d Before: %d\n", aDiff.indexI, copyState->supplyCount[aDiff.indexI]);
					printf("supplyCount of card#%d After: %d\n\n", aDiff.indexI, afterCopy->supplyCount[aDiff.indexI]);
				}
				afterCopy->supplyCount[aDiff.indexI]= copyState->supplyCount[aDiff.indexI];
				break;

			case E_embargoTokens: 
				if(test[E_embargoTokens]==0)  
				{
					printf("Error: embargoTokens changed.\n"); 
					printf("embargoTokens of card#%d Before: %d\n", aDiff.indexI, copyState->embargoTokens[aDiff.indexI]);
					printf("embargoTokens of card#%d After: %d\n\n", aDiff.indexI, afterCopy->embargoTokens[aDiff.indexI]);
				}
				afterCopy->embargoTokens[aDiff.indexI]= copyState->embargoTokens[aDiff.indexI];
				break;

			case E_outpostPlayed: 				
				if(test[E_outpostPlayed]==0)  
				{
					printf("Error: outpostPlayed changed.\n"); 
					printf("outpostPlayed Before: %d\n", copyState->outpostPlayed);
					printf("outpostPlayed After: %d\n\n", afterCopy->outpostPlayed);
				}
				afterCopy->outpostPlayed= copyState->outpostPlayed;
				break;

			case E_outpostTurn: 
				if(test[E_outpostTurn]==0)  
				{
					printf("Error: outpostTurn changed.\n"); 
					printf("outpostTurn Before: %d\n", copyState->outpostTurn);
					printf("outpostTurn After: %d\n\n", afterCopy->outpostTurn);
				}
				afterCopy->outpostTurn= copyState->outpostTurn;
				break;

			case E_whoseTurn: 
				if(test[E_whoseTurn]==0)  
				{
					printf("Error: whoseTurn changed.\n"); 
					printf("whoseTurn Before: %d\n", copyState->whoseTurn);
					printf("whoseTurn After: %d\n\n", afterCopy->whoseTurn);
				}
				afterCopy->whoseTurn= copyState->whoseTurn;
				break;

			case E_phase:
				if(test[E_phase]==0)  
				{
					printf("Error: phase changed.\n"); 
					printf("phase Before: %d\n", copyState->phase);
					printf("phase After: %d\n\n", afterCopy->phase);
				}
				afterCopy->phase= copyState->phase;
				break;

			case E_numActions: 
				if(test[E_numActions]==0)  
				{
					printf("Error: numActions changed.\n"); 
					printf("numActions Before: %d\n", copyState->numActions);
					printf("numActions After: %d\n\n", afterCopy->numActions);
				}
				afterCopy->numActions= copyState->numActions;
				break;

			case E_coins: 
				if(test[E_coins]==0)  
				{
					printf("Error: coins changed.\n"); 
					printf("coins Before: %d\n", copyState->coins);
					printf("coins After: %d\n\n", afterCopy->coins);
				}
				afterCopy->coins= copyState->coins;
				break;

			case E_numBuys: 
				if(test[E_numBuys]==0)  
				{
					printf("Error: numBuys changed.\n"); 
					printf("numBuys Before: %d\n", copyState->numBuys);
					printf("numBuys After: %d\n\n", afterCopy->numBuys);
				}
				afterCopy->numBuys= copyState->numBuys;
				break;

			case E_hand: 
				if(test[E_hand]== 0)  
				{
					for(i=0; i<hLen; i++)
					{
						//if player i was passed, ignore changes in that player's hand
						if(aDiff.indexI== hand[i])
						{
							flag= 1;
						}
					}
					if(!flag)
					{
						printf("Error: hand changed.\n"); 
						printf("Player#%d hand position#%d Before: %d\n", aDiff.indexI, aDiff.indexJ, copyState->hand[aDiff.indexI][aDiff.indexJ]);
						printf("Player#%d hand position#%d After: %d\n\n", aDiff.indexI, aDiff.indexJ, afterCopy->hand[aDiff.indexI][aDiff.indexJ]);
					}
				}
				afterCopy->hand[aDiff.indexI][aDiff.indexJ]= copyState->hand[aDiff.indexI][aDiff.indexJ];
				break;

			case E_handCount: 
				if(test[E_handCount]==0)  
				{
					for(i=0; i<hcLen; i++)
					{
						//if player i was passed, ignore changes in that player's hand
						if(aDiff.indexI== handCount[i])
						{
							flag= 1;
						}
					}
					if(!flag)
					{
						printf("Error: handCount changed.\n"); 
						printf("Player#%d handCount Before: %d\n", aDiff.indexI, copyState->handCount[aDiff.indexI]);
						printf("Player#%d handCount After: %d\n\n", aDiff.indexI, afterCopy->handCount[aDiff.indexI]);
					}
				}
				afterCopy->handCount[aDiff.indexI]= copyState->handCount[aDiff.indexI];
				break;

			case E_deck: 
				if(test[E_deck]==0)  
				{
					for(i=0; i<deLen; i++)
					{
						//if player i was passed, ignore changes in that player's hand
						if(aDiff.indexI== deck[i])
						{
							flag= 1;
						}
					}
					if(!flag)
					{
						printf("Error: deck changed.\n"); 
						printf("Player#%d deck position#%d Before: %d\n", aDiff.indexI, aDiff.indexJ, copyState->deck[aDiff.indexI][aDiff.indexJ]);
						printf("Player#%d deck position#%d After: %d\n\n", aDiff.indexI, aDiff.indexJ, afterCopy->deck[aDiff.indexI][aDiff.indexJ]);
					}
				}
				afterCopy->deck[aDiff.indexI][aDiff.indexJ]= copyState->deck[aDiff.indexI][aDiff.indexJ];
				break;

			case E_deckCount:
				if(test[E_deckCount]==0)  
				{
					for(i=0; i<decLen; i++)
					{
						//if player i was passed, ignore changes in that player's hand
						if(aDiff.indexI== deckCount[i])
						{
							flag= 1;
						}
					}
					if(!flag)
					{
						printf("Error: deckCount changed.\n"); 
						printf("Player#%d deckCount Before: %d\n", aDiff.indexI, copyState->deckCount[aDiff.indexI]);
						printf("Player#%d deckCount After: %d\n\n", aDiff.indexI, afterCopy->deckCount[aDiff.indexI]);
					}
				}
				afterCopy->deckCount[aDiff.indexI]= copyState->deckCount[aDiff.indexI];
				break;

			case E_discard: 
				if(test[E_discard]==0)  
				{
					for(i=0; i<diLen; i++)
					{
						//if player i was passed, ignore changes in that player's hand
						if(aDiff.indexI== discard[i])
						{
							flag= 1;
						}
					}
					if(!flag)
					{
						printf("Error: discard changed.\n"); 
						printf("Player#%d discard position#%d Before: %d\n", aDiff.indexI, aDiff.indexJ, copyState->deck[aDiff.indexI][aDiff.indexJ]);
						printf("Player#%d discard position#%d After: %d\n\n", aDiff.indexI, aDiff.indexJ, afterCopy->deck[aDiff.indexI][aDiff.indexJ]);
					}
				}
				afterCopy->discard[aDiff.indexI][aDiff.indexJ]= copyState->discard[aDiff.indexI][aDiff.indexJ];
				break;

			case E_discardCount: 
				if(test[E_discardCount]==0)  
				{
					for(i=0; i<dicLen; i++)
					{
						//if player i was passed, ignore changes in that player's hand
						if(aDiff.indexI== discardCount[i])
						{
							flag= 1;
						}
					}
					if(!flag)
					{
						printf("Error: discardCount changed.\n"); 
						printf("Player#%d discardCount Before: %d\n", aDiff.indexI, copyState->discardCount[aDiff.indexI]);
						printf("Player#%d discardCount After: %d\n\n", aDiff.indexI, afterCopy->discardCount[aDiff.indexI]);
					}
				}
				afterCopy->discardCount[aDiff.indexI]= copyState->discardCount[aDiff.indexI];
				break;

			case E_playedCards: 
				if(test[E_playedCards]==0)  
				{
					printf("Error: playedCards changed.\n"); 
					printf("playedCard#%d Before: %d\n", aDiff.indexI, copyState->playedCards[aDiff.indexI]);
					printf("playedCard#%d After: %d\n\n", aDiff.indexI, afterCopy->playedCards[aDiff.indexI]);
				}
				afterCopy->playedCards[aDiff.indexI]= copyState->playedCards[aDiff.indexI];
				break;

			case E_playedCardCount: 
				if(test[E_playedCardCount]==0)  
				{
					printf("Error: playedCardCount changed.\n"); 
					printf("playedCardCount Before: %d\n", copyState->playedCardCount);
					printf("playedCardCount After: %d\n\n", afterCopy->playedCardCount);
				}
				afterCopy->playedCardCount= copyState->playedCardCount;
				break;
		}		
	}
	while(aDiff.stateChange >= 0);
	return 0;
}

int createRandState(struct gameState *tempState) {
	int i,j, totalDeck=0, 
			 handCards=0,
			 deckCards=0, 
			 playedCards=0, 
			 discardCards=0, 
			 portion=0;

	//total Deck= all hands + discard + all decks + playedCards
	totalDeck= rand() % MAX_DECK;
	
	if(totalDeck > 0)
	{
		portion= rand() % totalDeck;
		deckCards= portion;
		totalDeck-= portion;
	}
	if(totalDeck > 0)
	{
		portion= rand() % totalDeck;
		discardCards= portion;
		totalDeck-= portion;
	}
	if(totalDeck > 0)
	{
		portion= rand() % totalDeck;
		handCards= portion;
		totalDeck-= portion;
	}
	if(totalDeck > 0)
	{
		portion= rand() % totalDeck;
		playedCards= portion;
		totalDeck-= portion;
	}

	
	tempState->numPlayers= (rand() % (MAX_PLAYERS-1)) + 2; //number of players	

	for(i=0; i<treasure_map+1; i++)
	{
		tempState->supplyCount[i]= rand() % 500 -10; 
	}

	for(i=0; i<treasure_map+1; i++)
	{	
		tempState->embargoTokens[i]= rand() % 500 -100;
	}

	tempState->outpostPlayed= rand() % 500 -100;
	tempState->outpostTurn= rand() % 500 -100;
	tempState->whoseTurn= rand() % (tempState->numPlayers);
	tempState->phase= rand() % 3 + 1;
	tempState->numActions= rand() % 50 ;
	tempState->coins= rand() % 500 -100;
	tempState->numBuys= rand() % 50;
	
	for(i=0; i<MAX_PLAYERS; i++)
	{
		for(j=0; j<MAX_HAND; j++)
		{
			tempState->hand[i][j]= rand() % (treasure_map+1);		
		}
	}

	for(i=0; i<MAX_PLAYERS; i++)
	{
		tempState->handCount[MAX_PLAYERS]= (handCards==0) ? 0:rand() % handCards;
	}
	
	for(i=0; i<MAX_PLAYERS; i++)
	{
		for(j=0; j<MAX_DECK; j++)
		{
			tempState->deck[i][j]= rand() % (treasure_map+1);
		}
	}
	
	for(i=0; i<MAX_PLAYERS; i++)
	{
		tempState->deckCount[i]= (deckCards==0) ? 0:rand() % deckCards;
	}
	
	for(i=0; i<MAX_PLAYERS; i++)
	{
		for(j=0; j<MAX_DECK; j++)
		{
			tempState->discard[i][j]= rand() % (treasure_map+1);
		}
	}

	for(i=0; i<MAX_PLAYERS; i++)
	{
		tempState->discardCount[i]= (discardCards==0) ? 0:rand() % discardCards;
	}
	
	for(i=0; i<playedCards; i++)
	{
		tempState->playedCards[i]= rand() % (treasure_map+1);
	}
	
	tempState->playedCardCount= (playedCards==0) ? 0:rand() % playedCards;

	return 0;
}