-----------------------Dominion Refactor Documentation-----------------------

#######################
Changes to the Smithy Code in cardEffect()
#######################
Refactor Changes: Added a method at the bottom of dominion.c called executeSmithyCard().
                               Replaced the Smithy code in cardEffect() with the new function. Added
                               the method signature to the dominion header file.
Bug Introduced: Changed the Smithy code to draw 5 cards instead of 3.

#######################
Changes to the Adventurer Code in cardEffect()
#######################
Refactor Changes: Added a method at the bottom of dominion.c called executeAdventurerCard().
                               Replaced the Adventurer code in cardEffect() with the new function. Added
                               the method signature to the dominion header file.
Bug Introduced: Changed the Adventurer code to draw 4 treasures, instead of 2. Also changed 
                Adventurer to count each treasure drawn as two treasures. This will be a very
                hard bug to detect because the Adventurer card will still only draw 2 treasure
                cards. Here there is a bug in the code, but it can only be detected by code
                review, since the end behavior is correct.

#######################
Changes to the Village Code in cardEffect()
#######################
Refactor Changes: Added a method at the bottom of dominion.c called executeVillageCard().
                               Replaced the Village code in cardEffect() with the new function. Added
                               the method signature to the dominion header file.
Bug Introduced: Changed the Village code to add 4 actions, instead of 2.

#######################
Changes to the Council Room Code in cardEffect()
#######################
Refactor Changes: Added a method at the bottom of dominion.c called executeCouncilRoomCard().
                               Replaced the Council Room code in cardEffect() with the new function. Added
                               the method signature to the dominion header file.
Bug Introduced: Changed the Council Room code to add 2 buys instead of 1.

#######################
Changes to the Great Hall Code in cardEffect()
#######################
Refactor Changes: Added a method at the bottom of dominion.c called executeGreatHallCard().
                               Replaced the Great Hall code in cardEffect() with the new function. Added
                               the method signature to the dominion header file.
Bug Introduced: Changed the Great Hall code to draw two cards instead of 1.
