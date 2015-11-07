AdventurerCard:

Deterministic
Lines executed:22.20% of 563
Branches executed:20.14% of 417
Taken at least once:17.27% of 417
Calls executed:11.00% of 100

Random:
Lines executed:23.45% of 563
Branches executed:20.14% of 417
Taken at least once:18.71% of 417
Calls executed:11.00% of 100

As you can see, there is a slight increase in coverage across the board.
This is due to testing many more kinds of cases around deck/hand/discard
card & card count allocations. It is catching errors where the added card count
is greater than 2. I caught this error previously as well.



Village Card:

Deterministic
Lines executed:19.01% of 563
Branches executed:17.75% of 417
Taken at least once:13.91% of 417
Calls executed:10.00% of 100

Random
Lines executed:22.91% of 563
Branches executed:18.71% of 417
Taken at least once:16.55% of 417
Calls executed:11.00% of 100

Same spec is checked as abefore but random gives us some freedom to test many more combinations
thus slightly increasing our coverage across the board. Improving my test spec to include testing for
proper discard allowed me to discover that the cards are not being discarded appropriately.
