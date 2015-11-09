To run the random tests use: make randomtestcard.out

The random test for adventurer was still designed to test the number of treasure cards after
calls to the adventureCard function, but used a randomizer to randomly add treasure cards
to the players hand prior to the call to adventureCard. The smithyCard random test took
a different approach in that it called the smithy function a random number of times to look
for anomalies across multiple function calls.

The coverage was good for both of the tests, but I think that the test methodology could be
improved. If I were to rewrite the tests I would probably combine the testing methods I have 
implemented with a randomized deck creator. That way I could look for anomalies across
a wider range of potential hand scenarios. I found that since my unit tests had good coverage
I wasn't able to improve the coverage, but I don't think that coverage should be the only 
assessment of test efficacy with these functions as they are relatively simplistic. Getting
good coverage is not terribly difficult. What might be considered a better metric is randomized
input to expected output comparison.

At the same time these functions may be more realistic than say the quiz function in which
the outcome is very easy to design a specified random test for that does not look for bugs
as much as it attempts prove a determined output.