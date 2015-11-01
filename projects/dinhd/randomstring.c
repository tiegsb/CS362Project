For the first part, there are 9 conditionals that use the inputChar() function. 
Once one conditional passes, the next conditional is evaluated until inputChar() 
can generate the correct character. Since we’re only interested in the input domain 
of ascii characters ranging from 32 “ “ to 125 “}“, I decided to use a mutation 
based random testing with “ “ as the base case and randomly generating a range when 
adding to “ “ will range from “ “ to “}”. This gives us a 1 in 94 chance of hitting 
the right character for each of the 9 conditionals that rely on inputChar().

For part two, since the correct string is dependent on 6^X combinations, 
I decided to reduce my input domain to increase my chance of actually satisfying 
the error condition. I made a randomly generated 5 ascii values: ‘r’, ‘e’, ‘s’, ‘t’,
and ‘\0’. This gives 6^5 combinations or a 1 in 15625 chance that the second stage 
would pass. 
