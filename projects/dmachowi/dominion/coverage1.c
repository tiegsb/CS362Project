unittest1 - 
This test executed 93.75% of the lines. It has 100% branch execution. For the boundaries I tried
to give it values that would allow it to test each possible card and a few numbers near to valid 
values. 

unittest2 -
This test execute 96.43% of the lines. It has 100% branch execution. Boundary coverage doesn't seem
to be much of an issue here as the number just needs to be checked to see if its correct or incorrect.
You have have to validate that the coin number is correct.

unittest3 - 
This test executed 79.41% of the lines, but only manged to 40% branch execution. This means that
the testing code I wrote is probalby not sufficient for actual testing purposes. As for the boundaries
in this unit test, I tried to  check the values before and after the function was called in order to see
if the values matched how they were supposed to. For example, if there were 5 cards in the discard pile before
the function call, I checked to see that there were 6 after.

unittest4 - 
This test executed 73.81% of the lines, but only manged to have 20% branch execution. This means that
the testing code I wrote is probably not sufficient for actual testing purposes. Similarly to the test above,
I checked the values before and after execution to check for correctness.

cardtest1 - 
This test executed 80.95% of the lines and received 83.33% branch execution. For the boundaries, I checked
that the values before and after execution for corrected and how they should be after execution.

cardtest2 - 
This test executed 92.73% of the lines and received 100% branch execution. For the boundaries I checked that
various number of cards in the hand and piles were correct. I did this by comparing the values before and 
after execution and figuring out wht they should be.

cardtest3 - 
This test executed 92.06% of the lines and had 100% branch execution. As in the previous example, I put all the
card count values and other counters in variables and compared the before and after execution values. I know
what they should be after execution, so if they are incorrect it is easy to see. 

cardtest4 - 
This test executed 90.12% of the lines and had 100% branch execution. As this was the smithy card, I just had to
check that there were three more cards added to the hand and that the smithy card was discarded. So like the other 
tests I just compared the counter values before and after execution.

I also ran gcov on the dominion code as per the instructions and it says that 18.07% of the lines were
executed and there was 18% branch coverage.
