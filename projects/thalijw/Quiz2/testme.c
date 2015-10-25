/**************************************************************************************
File Name: testme.c
Modified by: Wisam Thalij
Date Modified: 10-22-2015
Last Modified: 10-22-2015
**************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char inputChar()
{
    // TODO: rewrite this function
    // Create a random number between 126 and 32 (all the ASCII chars for the keyboard)
    int Number = rand() % (127 - 32) + 32;
    //  Cast the number to a character
    char Character = ((char) Number);
    return Character;
}

char *inputString()
{
    // TODO: rewrite this function

    int index;                                        // variable for loop
    int Number;                                       // variable to store the random lower case letter 
    char *Desired_String = malloc(sizeof(char) * 6);  // allocate memory for the returned string

    for (index = 0; index < 5 ; index++)
    {
      // Generate random number between 122 and 97 ASCII chars for lower case characters
      Number = rand() % (123 - 97) + 97;
      // cast the number to char and add it to the string
      Desired_String[index] = ((char) Number);

    }
    // Fix the last element on the string to be the terminating character
    Desired_String[5] = '\0';

    return Desired_String;
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
    // Free the string after each round to avoid the memory leak
    free(s);
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}