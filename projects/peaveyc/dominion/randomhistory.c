MAKE USAGE:
type make to produce the randomtestcard.out and randomtestadventurer.out files.


I knew since I'd have to write two random card testers, it would make sense to write one large general gameState
randomizer, that I could then alter for specific cards. The council room, or example, requires the position
of the council room in the player's hand. Because of this I simply added a council room at the end of the current players hand,
and incremented the hand count one. After creating this randomized gamestate, it was just a matter of copying the 
gameState variables to local variables, running the gamestate through a card function, and comparing results
between the newly altered gamestate, and the local variables. If certain conditions arent met, perhaps
not enough cards were drawn, an error message is printed to the screen, and an error flag is set.
at the end of the variable checking, a gameState dump is performed, showing the before and after of the 
pertinant variables. This will make bugs easier to locate and fix. In the previous assignment, I had also created
testers for adventurer, and council room. When comparing coverage statistics, I was pleased to find that the new
testers gained more coverage than the old ones in every area. Line coverage bumped up from 4.95% in the old test
to 11.06% in the new random test. Branch coverage also jumped from 3.36% to 7.14%. The adventurer tester however
didnt see as large of an increase, only moving from 11.09% to 11.43%. Branch coverage stayed exactly the same.
I think the intersting thing to note is that even though the adventurer tester didnt make much more coverage than
the last test, it ended up catching more bugs. I suppose this shows that coverage isn't everything, and when you
test and check everything, it is much more likely to catch bugs you dont expect. I think one way my random tester
could be improved upon would be to lay out error dumps in a more organized fashion. Also, setting different aspects of 
the state dump depending on the error thrown would be a great way to ease up on some of the clutter.