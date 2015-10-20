/*


*/


cardtest3: cardEffect(sea_hag)
BUGS IDENTIFIED:
	The sea_hag case in cardEffect() contains 
	several bugs. Namely, the deck count is erroneously reduced by 3 cards, 
	when the overall deck count should not have changed - i.e. the deck 
	count should have only been decremented once when top of deck was 
	discarded, then incremented when curse card was added. Instead, the deck 
	count was decremented three times and the deck was not incremented when 
	the curse was placed at the top of the pile. Also, the supply count of 
	curse cards was not decremented when the curse card was placed on top 
	of opponents' decks.