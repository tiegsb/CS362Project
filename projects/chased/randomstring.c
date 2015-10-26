/*This is the file randomstring.c. 
Author: Dustin Chase
Email: chased@oregonstate.edu
Date: 10/17/2015
Assignment: Random Testing Quiz 2
*/

To develop this random tester, I examined the range of valid inputs to the function testme. I found that it only accepts 
one of 9 possible characters and the string input containing characters from the string "reset". I decided to randomly 
select from the 9 possible characters for inputChar(), along with a few other characters so the function would be tested
with characters that are not in the list of "good" inputs. In a similar manner, I added a few random "wrong" 
characters to the "reset" input string.

I exercised this code to make sure it would both run a reasonable number of times, that the number of combinations would cause the testme() function 
to run a significantly different number of times each time the code is executed and that it would eventually generate the word "reset" (with a null terminator). 

I found that it took anywhere from several hundred to tens of thousands of iterations to reach the "error" output. Examining the function output, I could see that
the code was being fully exercised and not aborting too soon. 