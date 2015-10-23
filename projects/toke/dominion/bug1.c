-----------------------Dominion Bug1 Documentation-----------------------

#######################
unittest1.c: Tests whoseTurn()
#######################
- Bugs Found: None yet.

#######################
unittest2.c: Tests fullDeckCount()
#######################
- Bugs Found: None yet.

#######################
unittest3.c: Tests isGameOver()
#######################
- Bugs Found: 1
- Bug Description: isGameOver() cannot correctly tell if the game is over
                   for all scenarios. Currently isGameOver() checks the 
                   supply array from positions 0 to 24, inclusive. However
                   the supply array goes from 0 to 26, inclusive. The cards types for 
                   the 25th and 26 positions are sea_hag and treasure_map.

#######################
unittest4.c: Tests getCost()
#######################
- Bugs Found: None yet.

#######################
cardtest1.c: Tests executeSmithyCard()
#######################
- Bugs Found: 1
- Bug Description: This method draws an incorrect number of cards in the 
                   players hand. It draws 5 cards instead of 3.

#######################
cardtest2.c: Tests executeAdventurerCard()
#######################
- Bugs Found: 0
- Bug Description: There is a bug in the code, but it is not detectable by unit tests.
                   Please refer to refactor.c for more information.

#######################
cardtest3.c: Tests executeVillageCard()
#######################
- Bugs Found: 1 
- Bug Description: The number of actions is wrong. The code is adding two more actions
				   than expected.

#######################
cardtest4.c: Tests executeGreatHallCard()
#######################
- Bugs Found: 1 
- Bug Description: The number of cards drawn is wrong. The code is adding one more card 
				   to the hand than expected.
