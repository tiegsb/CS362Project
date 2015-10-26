I couldn't find any bugs in the unit tests for the functions. I did, however, find bugs in the 
cards. I found bugs in the village, and smithy, but I did not find bugs in the
great hall or adventure cards.

I did not look at the bugs I introduced before writing the tests. 

The bugs in the village and smithy cards were pretty obvious. For village I tested the number of
actions before and after the function call and compared with the expected outcome from the function
call. They did not match. The same applied to the village card except I measured the number of
cards in the players hand after calling smithy. They also did not match. 

I did a similar thing for great hall and the numbers matched the expectations. The numbers
for adventurer also worked, but I found out after based on gcov and then looking at my notes
that I did not cover the section of code that I changed.