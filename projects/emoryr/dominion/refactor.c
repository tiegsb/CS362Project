//
//  refactor.c
//  
//
//  Created by Rebecca Emory on 10/11/15.
//
//

#include <stdio.h>

/*
 The five cards I made into separate functions were smithy, village, great_hall, council_room, and adventurer
 
 I introduced a bug in adventurer that only counts copper and silver cards Drawn towards the drawn treasure requirement. (ln 657)
 
 In council room I introduced a bug where the players cards are not counted correctly. The player will get 5 cards drawn from this code. (ln 674)
 
 In smithy I changed the conditional statement of the for loop. (ln 701)
 
 In village, I changed the numActions variable to a temporary function variable. The state->numActions variable is unchanged by the numActions = state->numActions + 2. (ln 715)
   
