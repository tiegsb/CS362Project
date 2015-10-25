-----------------------Dominion Coverage1 Documentation-----------------------
Total Percentage of Code Covered by all tests: 35.49%

#######################
unittest1.c: Covers whoseTurn()
#######################
Individual Test Coverage Percentage (excluding all other tests): 15.70%
Coverage Discussion: The code for this method was very simple. It only contained 
					 one line of code with no branches. There was statement 
					 and boundary coverage. There was statement coverage because
					 all lines were covered. There was boundary coverage because
					 the min and max players were checked. Looking at gcov for this 
					 specific method, all lines were covered. The single line of code
					 in this method was run 7 times.

#######################
unittest2.c: Covers fullDeckCount()
#######################
Individual Test Coverage Percentage (excluding all other tests): 17.92%
Coverage Discussion: My tests had full statement coverage, but did not have full 
					 branch and boundary coverage. I did not check for all of the 
					 possible cards. There would be hundreds of permutations if I 
					 went that route. Looking at gcov, this method was called 41
					 times. All the loops and if statements in this method were
					 run hundreds of times. The return statement was executed 41 
					 times. Gcov shows that everything was covered for this 
					 method.

#######################
unittest3.c: Covers isGameOver()
#######################
Individual Test Coverage Percentage (excluding all other tests): 1.71%
Coverage Discussion: My tests had full statement coverage, but did not have full
					 branch and boundary coverage. I tested every supply position, 
					 but I did not test every single combination of supplies. Looking
					 at gcov, the method was executed 28 times, and every important line
					 of code was covered. The loops were covered hundreds of times.

#######################
unittest4.c: Covers getCost()
#######################
Individual Test Coverage Percentage (excluding all other tests): 5.12%
Coverage Discussion: My tests had full statement and branch coverage. I believe I have good 
					 branch coverage because I tested the case statement for every single
					 card. I did not have full boundary coverage because I did not test all 
					 possible numbers up to infinity. Looking at gcov, this method was run 29
					 times and every single case statement was covered once. All lines were 
					 covered.

#######################
cardtest1.c: Covers executeSmithyCard()
#######################
Individual Test Coverage Percentage (excluding all other tests): 18.09%
Coverage Discussion: My tests had full statement coverage. There is only a for loop in the
					 method, so there werent any branches to cover. I did not have full
					 boundary coverage because I did not test every single combination of 
					 hand positions. Looking at gcov, this function was executed 4 times, 
					 and every single statement was covered.

#######################
cardtest2.c: Covers executeAdventurerCard()
#######################
Individual Test Coverage Percentage (excluding all other tests): 21.16%
Coverage Discussion: My tests have full statement coverage, but they do not have full branch
					 branch coverage. The branch that requires the most permutations is the 
					 if statement detecting whether the drawn card is a treasure or not. I would
					 have to test all permutations of all the cards in order to get full branch 
					 coverage, but I thought that wasnt necessary. Looking at gcov, this function
					 was run a total of 6 times, and all statements were covered.

#######################
cardtest3.c: Covers executeVillageCard()
#######################
Individual Test Coverage Percentage (excluding all other tests): 18.09%
Coverage Discussion: My tests have full statement coverage. There are no branches in this function
 					 so I did not have to worry about branches coverage. Looking at gcov, this 
 					 function is run 5 times and every statement was also run 5 times.

#######################
cardtest4.c: Covers executeGreatHallCard()
#######################
Individual Test Coverage Percentage (excluding all other tests): 18.26%
Coverage Discussion: My tests have full statement coverage. There are no branches in this function
 					 so I did not have to worry about branches coverage. Looking at gcov, this 
 					 function is run 6 times and all statements within this function are run
 					 6 times.
