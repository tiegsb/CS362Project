/************************************
* Author: Ashok Nayar
* Class: cs362, Fall 2015
* Project: Quiz 2 - Random Testing
************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // Set up array of chars that 
    // will be potentially be chosen
    char chars[] = "[({ ax})]";

    // There are 10 choices, so pick a 
    // number between 0-9
    int i =   rand() %9;

    // Return the respective character
    // at the randomly chosen index
    return chars[i];
}

char *inputString()
{
    // Set up an array of potential characters
    // to build a string from  
    char chars[] = "rest\0";

    // Allocate space for a word that has 6 characters
    char *word = malloc(6 * sizeof(char));
    int i;

    // Loop through each index and place a randomly
    // generated character at that index
    // NOTE: In this approach, it is possible for
    // the same character to appear multiple times in the word
    for(i=0;i<5;i++)
    {
      // Random choose a number between 0-5
      int j = rand() % 5;
      // Use that number to grab the char at that index
      // and use the char to assemble the string
      word[i] = chars[j];
    }
    
    // Return the assembled word
    return word;
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


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}