randomhistory.c

improvements in coverage and effort to check the correctness of your specification.

The coverage of the random tests has increased significantly from the coverage of the unit tests that I built previously. The random tests are testing 26% of the code compared to the 17% that I was testing before. One of the improvements that I made was to use the initalizeGame() method. Before calling the constructor I filled the gameState with random bytes. 
The second test covered was the for the great_hall and it covered 36% of the dominion code. The branch coverage for both of these tests seems a little weak but I believe that is because in the case statements for cardEffect() they only go down one path. I think that this is a case where branch coverage results are misleading, in this case we only want to test a specific function and don't necessarily want to cover the un-related branches.
