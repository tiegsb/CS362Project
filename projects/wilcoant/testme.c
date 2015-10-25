#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    
    char randc = ' ' + (rand() % 94); //all values below space not considered
    //max possible is 125 (32 + 93)
    return randc;
}

char *inputString()
{
    //time_t t;
    //srand((unsigned) time(&t));
    char randstring[6];//5 letter null terminated string 
    int i; //loop counter
    for(i = 0; i < 5; i++)
    {
        randstring[i] = 'a' + (rand() % 26); //only letters considered for string
    }        
    return randstring;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}
int main()
{   
    time_t t;
    srand((unsigned) time(&t));
    testme();
    return 0;
}
