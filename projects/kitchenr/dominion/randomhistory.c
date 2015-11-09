

Adventurer random testing.
  I had expected Adventurer to give me an infinite loop or a segfault (based on what I remembered from the original code) however I forgot that I had changed
  this bug to do something different.
  
  My testing specifications were based on the number of coins in the deck and discard piles, as well as the number of cards in each pile.
  The tests check if the card is drawing only from the deck, or also drawing from the discard pile as well. If there are less than two cards in the deck, it will 
  allow shuffling of the discard pile into the deck. My original test simply checked if the number of coins was 2 or discard coins + deck coins, but that turned out
  to be inaccurate according to the card rules.
  
  This testing revealed that the implementation of adventurer will draw from both piles regardless of the amount in the deck, which is a bug.
  
Mine random testing.
  I made this test to check the mine card. The specific tests are listed in the comments on the testing file. The key things I was looking for was whether the card 
  was checking to see if the input and output cards were valid, and if it was actually trashing the input card or just putting it in discard. Also of importance
  was to check whether it was imposing cost increase limitations. Upon reading the log, however, I discovered that it was passing sometimes when the input should
  have failed. So I had to go back and change my test cases to include testing for false success, which I had forgotten to implement the first time around.
  
  One thing I had to add was setting the supply count and checking if there was enough to buy- this provided clarification for the errors I recieved.
  
  From the failure log, I have determined that for many cards, the mine would allow them to be purchased as long as the input was a coin. I did not have a check for
  the price of invalid cards, only valid ones, so it appears that only cards the user can afford can be purchased from the logs. This would be a test case to include
  
  