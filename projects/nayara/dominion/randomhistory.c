/* Ashok Nayar
* cs362, Fall 2015
* Assignment 4: Random Testing
* Write up
*/

*Coverage for randomtestadventurer.out: Lines executed:9.85% of 660

*Coverage for randomtestcard.out (council card) : Lines executed:10.15% of 660

* Coverage summary
At first glance, it appears that we have less coverage than our unit tests from the previous assignment, but this is not the case at all. 
First, in the random tests we are not using the “initialize()” function, so that means that we are not calling a significant chunk of code.
In our random testing, however, this makes little difference wince we are initializing all the variables and arrays that we need directly 
in our tests. While the percentage may appear lower, we’re actually testing portions of the code more times than we were with our direct 
unit testing. For example, my unit tests did not make extensive use of empty decks. As a result, portions of the code that ran when the 
deck was empty seldom ran, if at all. However, the random testing ensures that the decks are empty at least sometimes, thus running 
those parts of the code. In fact, in one test alone, the drawCard function ran the code for an empty deck 163, which is far more than 
our previous test. While our coverage only runs a minimal part of the dominion code outside of the functions we are testing, it still 
makes sure that the function in question is run thoroughly enough in several different situations.

* Random test summary
The hardest part about running these random tests were ensure that the correct arrays and variables had valid data in them. Several times 
the code with crash, throw an error, or behave in unpredictable ways and it was hard to tell if it was a result of the function itself 
(a valid bug) or due to a poor dataset. The drawback to this method was that setting up a random test took quite a bit of digging around 
in the code to find out what arrays and variables were needed and making sure that they were set up correctly. The trade off, however, is
 that we can easily test multiple types of situations and datasets and find any bugs. The bugs that were introduced in previous 
 assignments were caught correctly and nothing slipped by unnoticed. 
