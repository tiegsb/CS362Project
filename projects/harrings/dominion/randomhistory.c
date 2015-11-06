
RandomAdventurer
To develop this random test I used much of my unittest I developed for the adventurer card and 
modified it to randomize and expand input.
I changed the max player count to 4.
I then cycled through my tests 2000 times while only keeping track of number of passes and fails 
rather then reporting each pass or fail indvidually then totalled them up at the end
Inside of the test I randomized player count, which player was playing, and a random starting deck.
I then noted the number of cards in hand, deck and discard before and after the adventurer card was used.
my 3 pass fail tests were to check if the number of cards in deck changed the same amount as discard
I checked if the hand size increased by 1 and
if the last two cards in the hand were treasue cards.
My coverage was up from my unittest of the adventurer card in the dominion.c however my coverage was 
very similar on randomtestadventurer.c as it was on the adventurer unit test. This is likely
due to the fact that while I tested with more inputs (randomized) I never got any split
results every test either passed or failed 100% of the time.





Gcov of Randomtest adventurer.c
File 'dominion.c'
Lines executed:26.08% of 579
dominion.c:creating 'dominion.c.gcov'

File 'randomtestadventurer.c'
Lines executed:90.63% of 64
Branches executed:72.73% of 22
Taken at least once:50.00% of 22
Calls executed:100.00% of 14
randomtestadventurer.c:creating 'randomtestadventurer.c.gcov'


RandomCouncil card
To develop this random test I used much of my unittest I developed for the council card and 
modified it to randomize and expand input.
I changed the max player count to 4.
I then cycled through my tests 2000 times while only keeping track of number of passes and fails 
rather then reporting each pass or fail indvidually then totalled them up at the end
Inside of the test I randomized player count, which player was playing.
I then noted the number of cards in hand, number of cards in other players hands and number of buys before and after the council card was used.
my 3 pass fail tests were to check if the number of buys increased by 1
I checked if the hand size increased by 3 and
if all other players handsize increased by 1 as well
My coverage was up from my unittest of the council card in the dominion.c from 22 to 26% however my coverage was 
very similar on randomtestcard.c to my cardtest of the council card This is likely
due to the fact that while I tested with more inputs (randomized) I never got any split
results every test either passed or failed 100% of the time.








Gcov of Randomtestcard.c
File 'dominion.c'
Lines executed:26.08% of 579
dominion.c:creating 'dominion.c.gcov'

File 'randomtestcard.c'
Lines executed:90.32% of 62
Branches executed:100.00% of 20
Taken at least once:85.00% of 20
Calls executed:100.00% of 9
randomtestcard.c:creating 'randomtestcard.c.gcov'