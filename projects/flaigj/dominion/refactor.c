/*
Author: Jason Flaig

smithyCard: 
Changed line 319 
from -  for (i = 0; i < 3; i++)
to -	for (i = 0; i <= 3; i++)


adventurerCard: 
Removed '|| cardDrawn == gold' from line 335's if statement so it's changed
to - 	if (cardDrawn == copper || cardDrawn == silver)


minionCard: 
No error here: just throws off person to look at this first while the second 
change in minionCard is an error
Removed line 372 // draw 4
Changed line 373 from - (i = 0; i < 4; i++)
to - for (i = 0; i <= 3; i++)

Condensed line 390 and 391 to just line 390  
from - 390 //draw 4
 	   391 for (j = 0; j < 4; j++)
to -   390 for (j = 0; j <= 4; j++)


tributeCard: 
Removed line 428 which was - shuffle(nextPlayer,state);//Shuffle the deck


council_roomCard: 
Changed line 463
from - for (i = 0; i < 4; i++)
to - for (i = 0; i <= 4; i++)

Removed lines 468 and 469
//+1 Buy
state->numBuys++;
*/