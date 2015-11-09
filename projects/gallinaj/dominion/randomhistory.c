Jana Gallina
CS362 Fall 2015
Assignment 4
11-8-15

In these tests I ended up executing them two different ways. In the randomtestadventurer file,
I modified the adventurer testing from the previous assignment, which used a testing function
rather than calling the original function from dominion.c.

In randomtestcard I tested the great_hall function by calling cardEffect(). Testing in this fashion
is a little more difficult because there isn't a good way to inject the test statements into the code--
rather, the test looks at the before and after function values. I think this way is better,
however, because it's using the actual function in the code rather than a modified version.

Both versions are giving much better coverage than I previously had. This time the adventurer test has
caught the bug I introduced in the first dominion assignment.
