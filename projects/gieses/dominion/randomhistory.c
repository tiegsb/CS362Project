For testing the adventurer card, I focused on randomizing the count of cards in the players hands, the count of cards in the discard pile, and randomly selecting what cards go in both the players hands and the discard piles. Then, I checked to see what the last two cards were. In my previous version, I had specified it so that silver and gold were the last two inserted. However, since this is a random test, I didn't know what the last two cards would be. So after I ran the card, I checked the last two cards and added a counter (countTreasure). CountTreasure allowed me to check to make sure nothing was going wrong (negative numbers, more than the expected, etc.). I also checked more items such has the played card count, since I wanted to make sure it was equal to one, and I checked the count of the hand and the discard pile to make sure they were accurate. 

The results are below. As we can see, not much has changed. The only major change is is that branches now execute 18.23% instead of 17.75% of the dominion.c file. 

Old Adventurer:
Lines executed:100.00% of 25
No branches
Calls executed:100.00% of 4
cardtest1.c:creating 'cardtest1.c.gcov'

File 'dominion.c'
Lines executed:18.44% of 591
Branches executed:17.75% of 417
Taken at least once:14.39% of 417
Calls executed:8.91% of 101
dominion.c:creating 'dominion.c.gcov'
 
New Adventurer:
Lines executed:97.06% of 34
Branches executed:100.00% of 20
Taken at least once:75.00% of 20
Calls executed:100.00% of 8
randomtestadventurer.c:creating 'randomtestadventurer.c.gcov'

File 'dominion.c'
Lines executed:18.44% of 591
Branches executed:18.23% of 417
Taken at least once:14.39% of 417
Calls executed:8.91% of 101
dominion.c:creating 'dominion.c.gcov' 
 
 
 
For testing the smithy card, I focused on the same things as the adventurer card by randomizing the count of cards in the players hands, the count of cards in the discard pile, and randomly selecting what cards go in both the players hands and the discard piles. I then would run the smithy card and check the players hand count, the players discard count, and the played card count. In both the adventurer test and this test, the discard function was not working properly. This was noted in the bugs file previously, and made even more obvious after these tests.

The results below don't show any change in the dominion file. I believe this is because I am still testing the exact same things as I did in the first implementation of this tester function, whereas with the adventurer function, I was a little more robust. 
 
Old Smithy:
Lines executed:93.10% of 29
Branches executed:100.00% of 4
Taken at least once:50.00% of 4
Calls executed:81.82% of 11
cardtest2.c:creating 'cardtest2.c.gcov'

File 'dominion.c'
Lines executed:18.44% of 591
Branches executed:17.75% of 417
Taken at least once:14.15% of 417
Calls executed:9.90% of 101
dominion.c:creating 'dominion.c.gcov'
 
New Smithy:
Lines executed:96.77% of 31
Branches executed:100.00% of 12
Taken at least once:75.00% of 12
Calls executed:100.00% of 8
randomtestcard.c:creating 'randomtestcard.c.gcov'

File 'dominion.c'
Lines executed:18.44% of 591
Branches executed:17.75% of 417
Taken at least once:14.15% of 417
Calls executed:9.90% of 101
dominion.c:creating 'dominion.c.gcov'