/*
------------------------------
randomhistory.c
Assignment 4
jenkinch
------------------------------

Comments on the individual coverage accomplishments of each function can be found below,
along with comments on the random testing methodologies and correctness checking.
Note that test counts (n) were left low to allow for more readable output in the .out files.

randomtestadventurer: cardEffect(adventurer)
    Coverage - Assignment 3 Non-Random:
        Lines executed:23.22% of 577
        Branches executed:25.18% of 417
        Taken at least once:17.75% of 417
        Calls executed:12.63% of 95

    Coverage - Assignment 4 Random (n = 4):
        Lines executed:23.40% of 577
        Branches executed:25.66% of 417
        Taken at least once:18.23% of 417
        Calls executed:12.63% of 95

    Statement/Branch Coverage Comparison:
        Overall, coverage increased between Assignments 3 and 4. In comparing the gcov
        files, the main notable differences were:
            - Branch executions of the compare function were more 50-50 in A4 than in A3.
            - The initialization function block executions increased by 3% in A4.
            - For the shuffle function, branch execution splits were far less even in the A4 results.
            - In the actual activateAdventurer function: 
                - The branches involving whether a shuffle is required were executed much less evenly.
                - The checks of cardDrawn against the various treasure cards were less even but executed 
                  all branches in A4 whereas A3 missed a branch.
        
        Beside what was noted above, coverage was generally very similar between A3 and A4, and variations
        would likely become less pronounced as more test iterations were run for the random tester in A4.
        
    Random Tester Methodology:
        Input data was randomized as follows:
            - Most of the gamestate had random integer assignments, except as noted below.
            - Number of players random between 2 and 4
            - whoseTurn randomized based on number of players
            - deckCount, discardCount, and handCount randomized up to their MAX constants
            - deckCount given increased chance to be zero to allow for more even testing of discard to deck conversion
            - deck, discard, and hand given random valid cards
            - If at least two treasures have not been added between the deck and discard, two are added to meet preconditions
              of adventurer card.
              
        Two gamestates were created, pre and post, where pre simulates the expected operations of the cardEffect for later 
        specific comparisons with post which is subject to the cardEffect function.
    
    Random Tester Correctness Checking:
        Test cases:
        - Test for successful cardEffect function call
        - Test for matching pre and post handCount
        - Test for matching pre and post discardCount + deckCount sum
        - Test for matching pre and post hand up to newly added cards in hand
        - Test that new cards in hand are copper, silver or gold
        - Test that all other players' handCount, discardCount and deckCount were unaffected by current player's actions
            
        These test cases do a generally solid job of testing for correctness at least so far as pointing out large bugs.
        The bugs discovered were that the post discard and deck piles do not sum to the correct number indicating card loss,
        and the cards (or lack thereof) present where the new treasure cards should be generally were not treasure cards.
        
        While this was beneficial, the preferred oracle would be one that could check that the entire resulting gamestate
        in post is the same as pre, unfortunately this was impractical to achieve due to the random shuffling behavior
        happening in the cases where the deck runs out of cards.
        
randomtestcard: cardEffect(village)
    Coverage - Assignment 3 Non-Random:
        Lines executed:19.93% of 577
        Branches executed:22.78% of 417
        Taken at least once:14.15% of 417
        Calls executed:11.58% of 95
 
    Coverage - Assignment 4 Random (n = 4):
        Lines executed:24.09% of 577
        Branches executed:24.22% of 417
        Taken at least once:16.79% of 417
        Calls executed:12.63% of 95     
        
    Statement/Branch Coverage Comparison:
        Overall, coverage increased between Assignments 3 and 4. In comparing the gcov
        files, the main notable differences were:
            - Branch executions of the compare function were more 50-50 in A4 than in A3 and branch
              execution percentage rose to 100% from 83%.
            - The initialization function block executions increased by 7% in A4.
            - For the drawCard function, branch execution greatly increased from 36% to 93% from A3 to A4.
        
        Beside what was noted above, coverage was generally very similar to or the same between A3 and A4 and
        variations would likely become less pronounced as more test iterations were run for the random tester
        in A4.
        
    Random Tester Methodology:
        Input data was randomized as follows:
            - Most of the gamestate had random integer assignments, except as noted below.
            - Number of players random between 2 and 4
            - whoseTurn randomized based on number of players
            - deckCount, discardCount, and handCount randomized up to their MAX constants
            - deckCount given increased chance to be zero to allow for more even testing of discard to deck conversion
            - deck, discard, and hand given random valid cards
            - A village card was inserted into a random position in each player's hand.
              
        Two gamestates were created, pre and post, where pre simulates the expected operations of the cardEffect for later 
        specific comparisons with post which is subject to the cardEffect function.  
    
    Random Tester Correctness Checking:
        Test cases:
        - Test for successful cardEffect function call
        - Test for matching pre and post handCount
        - Test for matching pre and post discardCount
        - Test that the latest card in discard pile in pre and post match (should be a village)
        - Test for matching pre and post deckCount
        - Test for matching pre and post numActions
        - Test that all other players' handCount, discardCount and deckCount were unaffected by current player's actions
            
        These test cases are generally good at testing for correctness at least so far as pointing out major bugs.
        The bugs discovered were that the post discard pile does not update properly, the last post discard pile card is
        incorrect, and numActions was not updated properly.
        
        A preferred oracle would be one that could check that the entire resulting gamestate in post is the same as pre,
        but again this was impractical to achieve due to the random shuffling behavior happening in the cases where the deck 
        runs out of cards.
*/