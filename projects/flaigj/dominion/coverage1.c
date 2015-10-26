/*
Findings
When running gcov it shows that I undertested dominion.c functions.  The highest number of lines executed was 22%.  The lowest was 18%.  Branch coverage was a bit higher with the highest at 32% though.  Taken at least once is low followed by calls executed.  

To improve my future coverage I need to think better about when shuffling, discarding, gaining cards and functions that call one another happen in the actual game.  My problem involved trying to zero in one function and that wasn't a good idea. I need to use playCard() when playing cards, buy card instead of just putting the card into the hand.  I messed up writing my own functions for some things instead of remembering a function like fullDeckCount() that actually returns the count.

Results

cardtest1.c - SmithyCard()
Lines executed:18.79% of 580
Branches executed:24.58% of 415
Taken at least once:14.46% of 415
Calls executed:9.57% of 94

cardtest2.c - adventurerCard()
File 'dominion.c'
Lines executed:17.59% of 580
Branches executed:24.58% of 415
Taken at least once:14.46% of 415
Calls executed:8.51% of 94

cardtest3.c - council_roomCard()
File 'dominion.c'
Lines executed:19.31% of 580
Branches executed:25.54% of 415
Taken at least once:15.42% of 415
Calls executed:10.64% of 94

cardtest4.c - sea_hag()
File 'dominion.c'
Lines executed:21.72% of 580
Branches executed:31.57% of 415
Taken at least once:16.14% of 415
Calls executed:10.64% of 94


unittest1.c - isGameOver()
File 'dominion.c'
Lines executed:17.24% of 580
Branches executed:17.83% of 415
Taken at least once:14.94% of 415
Calls executed:7.45% of 94

unittest2.c - discardCard()
Lines executed:20.52% of 580
Branches executed:18.31% of 415
Taken at least once:14.70% of 415
Calls executed:10.64% of 94

unittest3.c - gainCard()
Lines executed:21.90% of 580
Branches executed:19.28% of 415
Taken at least once:15.90% of 415
Calls executed:11.70% of 94

unittest4.c - scoreFor()
File 'dominion.c'
Lines executed:21.38% of 580
Branches executed:22.17% of 415
Taken at least once:17.35% of 415
Calls executed:10.64% of 94
*/