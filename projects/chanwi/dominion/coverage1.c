/* Coverage

There is a large portion of code in dominion.c that is not executed. That is to be expected as much of the card effects and game functions were not tested. Although 4 unittests and 4 cardtests did account for almost a third of the lines that were executed. Some of unittests and cardtests were testing the same code, so a few statements were ran a proportionally higher than other lines that may be ran once or twice. For example, all the cardtests have a discardCard() portion to the card effect that always get ran when a card is played. However, some effects such as drawCard is less often played. You can see this distribution of which statements and branches are ran more often that others  in the gcov files.

Unittests and Cardtests
The 4 unittest and 4 cardtests score high statement coverage, most of them in the 90%, the branch coverage was a bit lower, but some still score in the low to mid 80%. My test utilizes a lot of if statements, so not all branches of the code would be ran if conditions are not met. Look at the gcov files, I would definitely like to write tests for the statements and branches that are less covered in my tests and overall improve my test suite. It is important to me that branch coverage is a bit higher because, of the high interplay of functions calling on other functions in dominion.c. I also noticed that the boundary cases could have been written a bit better and it is something I will want to improve upon in future test suite I write. 


*/