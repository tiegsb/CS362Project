Refactor effects into their own functions
=========================================

This fulfills part 3 of assignment 2.
The following functions were created during the refactor:
* adventurerEffect
* council_roomEffect
* smithyEffect
* baronEffect
* villageEffect

Bugs introduced
---------------
1. adventurerEffect: z is not initialized.
2. council_roomEffect: The number of buys is not changed.
3. smithyEffect: The index variable i is not properly initialized.
4. baronEffect: When baronEffect is called, its value is not returned. Control
   will fall through into the next case statement.
5. villageEffect: The arguments are given in the wrong order.
