/*

Development of random tester:

I first looked at the code I'm instructed to test. We realize a few things
    1 - to get the error message we must have these conditions fulfilled:
        a: s[] = "reset\0"
        b: state = 9
    2 - to trigger get to state 9, we must trigger state 1 thru 8 sequentially
    3 - states 1 to 9 are triggered when our character c is some specific
        lower alpha char or special char

We also know that the previously triggered state in the while loop is kept,
because the bi-conditional statements && require states integer to go up.

Knowing these, to trigger it we must then create our inputChar() function
to generate lowercase values and special characters. I chose to implement
the function to return any character values between ASCII SPACE and DEL
and convert any uppercase alpha characters to lower case as such:

        char inputChar()
        {
            char c = (rand() % 95 + 32);

            if(c >= 'A' && c <= 'Z')
            {
                c = c + ('A' - 'a');
            }

            return c;
        }

We probably could have limited this generation to the characters required in the
function being tested but since it wasn't stated, I left this to it's bare
necessity - this way it can be reused later if necessary.

For the second requirement of having s[] = 'reset\0' we randomly generate this using
a fixed set of target characters which are 'r' 'e' 's' 't'. and generating a string by
randomly picking from those 4 available characters. We could have used inputChar to generate
the string but because of the large range it produces, the while loop could take awhile to
generate 'reset' - the permutation of the 95 characters produced by inputChar would be too large
and we may end up with an overflow in the counter before we could get 'reset' produced.

char *inputString()
{
    char* this_string = (char*)malloc(6 * sizeof(char));
    char target[] = "rest";
    size_t len_target = strlen(target);
    int i;
    for(i=0; i<5; i++)
    {
        this_string[i]= target[rand() % len_target];
    }
    this_string[i] = '\0';
    return this_string;
}

*/
