
James Riccelli

My inputChar() function makes use of c's random number generator to produce random ascii values. I used the formula (rand()%(max-min)+min)using
ascii values from the Ascii table (asciitable.com)). 
once thsi value was stored to char c, c would be returned.

In my inputString() function, I tried using the same approach as above, but it
was taking forever to span that range and come up with the correct combination
of reset. I chose to store r,e,s,t in a character array. to limit my random
cases. Then I called rand() %4 ) on that array value. This ran in many less
iterations. Once reset is captured, the program throws error 200 and escapes
