/*  fitzsimk
    refactor.c
*/
/*	PLAY CUTPURSE
    normal behavior: each other player discards a copper card, or reveals a hand without any copper
    modified behavior: each other player discards a SILVER card, or reveals a hand without any silver
*/
/*	
    PLAY TREASURE MAP
    orginal behavior: if two treasure map cards are found, both are trashed
    modified behavior: if two treasure map cards are found, only the second one is trashed
*/

/*
    PLAY SMITHY
    original behaviour:  +3 cards
    modified behavior: +2 cards (loop counter starts at 1)
*/

/*
    PLAY ADVENTURER
    orignal behavior: if a treasure card is drawn, the drawntreasure variable would +1
    modified behavior: if a treasure card is drawn, the drawntreasure variable is set to 2 
    (*cards are discarded cards until one treasure is found*)
*/
/*
    PLAY_MINE (unmodified)
    original behavior: trash treasure from your hand and upgrade it to a better one
*/
