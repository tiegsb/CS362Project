The main principle, as I saw it, and as we learned in Lesson ‘11RadomTesting.pdf’, is that we need to identify the interface under test and what it is expecting.  This really helped in identifying how the functions should function.

Regarding how ‘inputChar()’ is being consumed by the calling code and being compared to other chars it is clear that values such as ‘NUL’ – ‘US’ (0-31) and DEL (127) would not be relevant, so I restricted my random chars to the range of ‘Space’ through ‘~’ (32 – 126).  This method is completely random and eventually finds the sequence needed to raise state to the needed criteria. 

Regarding how ‘inputString()’ is being consumed and examined it did not make sense to pass nonsensical words composed of randomly of random chars where each character making up the string would be randomly generated.  The odds of a real ‘word’ being generated is very very low, let alone the possibility of the word ‘reset’ being randomly generated in such a fashion, so my implementation was to pass back one of one-thousand words to the calling section at random.  This fell within the instructions to ‘Try to “stay random” but shift the probability space.  Augment random with fixed inputs of interest.’ as we learned in the same lecture listed above.  This method is much like the first in that it eventually finds the word ‘reset’ after the proper state has been reached by ‘inputChar’.

All in all I think it was a success and a great learning opportunity. :) 

Thank you so much!!

Ben
