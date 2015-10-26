/*
InputChar:
I basically took 9 chars representing [ through ] as cases in a switch statement.  
Cases were numbers and I used a random number generator to get to a specific case. 
Once in that case I set char ch to a specific char broke from that case and returned 
the result.

 InputString:
 My original logic was to create a c string called mySet = reset, then generate a 
 random number in a loop and assign myString[loop counter] to mySet[idx rand], 
 then return that value. I forgot to allocate memory for the character pointer and 
 other syntax so I looked up, citation provided in testme.c, a solution and made syntax
 changes because I used single quotes on mySet instead of double quotes.

*/

