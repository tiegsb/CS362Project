/* First off, my coverage would benefit from being cumulative throughout my
 * unit tests.
 *
 * Based on my coverage metrics, my unit/card tests do a good job of hitting
 * certain basic functions. Most of my statement coverage percentage comes from
 * the initializeGame function, which I called uniformly to test other options.
 * This skewed results somewhat, as my other tests generally were less than 50
 * lines of the ~500 lines in dominion.c; between all of my tests, though, I
 * achieved moderate coverage of the basic utility functions. To improve my work in
 * the time to come, it will be necessary for me to target those functions that
 * I haven't hit yet, mainly contained within playCard.
 *
 * If I can put together better card tests to test within playCard(), I will
 * achieve better statement and branch coverage for dominion.c as a whole, and
 * can be more well-assured in my evaluation of possible bugs.
 */
