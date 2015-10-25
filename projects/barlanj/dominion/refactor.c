/* Filename: refactor.c
 * Author: Joseph Barlan (barlanj)
 * Description: This file contains the change logs for dominion.c
 *              for all refactored codes.
 */


/*

    ====================================================================================
    1.0 - Refactored Card Effects
    ====================================================================================

    1.01 - smithy
    ------------------------------------------------------------------------------------
    [10/11/2015]
    + cardEffect() codes moved to cardEffect_smithy(...)
    + bug: discardHand function call parameters passed are incorrect - switched
            trashflag and handPos

    1.02 - adventurer
    ------------------------------------------------------------------------------------
    [10/11/2015]
    + cardEffect() codes moved to cardEffect_adventurer(...)
    + bug: z not initialized
    + bug: temphand counter not properly incremented for discarding in else statement

    1.03 - council room
    ------------------------------------------------------------------------------------
    [10/11/2015]
    + cardEffect() codes moved to cardEffect_councilRoom(...)
    + bug: drawCard runs 5x instead of 4x
    + bug: numBuys counter not incrementing, instead coins are

    1.04 - embargo
    ------------------------------------------------------------------------------------
    [10/11/2015]
    + cardEffect() codes moved to cardEffect_embargo(...)
    + bug: discardCard trashflag changed to 0
    + bug: checking to see for selected pile is in play returns 0 (should be -1)

    1.05 - steward
    ------------------------------------------------------------------------------------
    [10/11/2015]
    + cardEffect() codes moved to cardEffect_steward(...)


 */
