I chose to test villageEffect card for my randomtestcard.

I used the alarm syscall to build a timeout for the adventurer tests so that it wouldn't suffer from infinite loops. It turned out that the bugs I introduced broke it so badly that wasn't even an issue.

I successfully discovered the bugs I introduced into the advernturerEffect and villageEffect functions.

The random tests I wrote have the unfortunate possibility of running 0 times. This wouldn't be hard at all to fix.
