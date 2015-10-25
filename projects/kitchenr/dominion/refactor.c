Adventurer: This contains a bug where if 2 coins are not found, the function will continue to draw cards indefinitely. This will cause a shuffle, which is not allowed by the game rules, and if the coins are not found, this will cause an infinite loop/segfault

Smithy: This bug is not using a pointer, but rather passing the state by value. This will cause no error but will not do anything at all.

Village: This omits removing the village card from the hand, so it can be played again


