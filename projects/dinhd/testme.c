#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    char base = ' ';
    char mutation = base + (rand() % 94);
    //printf ("mutation is %c", mutation);
    return mutation;
}

char *inputString()
{
  char *outputString  = (char *) malloc(sizeof (char));

    // Randomly fills each spot 0 - 6 of a character block with characters r, e, s , t, \0
    for (int i = 0; i < 6; i++)
    {
      int randGen = rand() % 5;
      //printf ("randGen is %i", randGen);

      switch (randGen)
      {
        case 0:
          outputString[i] = 'r';
          //printf ("inserted %c", outputString[i]);
          break;

        case 1:
          outputString[i] = 'e';
          //printf ("inserted %c", outputString[i]);
          break;

        case 2:
          outputString[i] = 's';
          break;

        case 3:
          outputString[i] = 't';
          break;

        case 4: 
          outputString[i] = '\0';
          break;
      }

    }
    printf ("the output string is %s" , outputString);
    return outputString;
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
    // printf ("the state is %i", state);
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) 
    {
       // printf ("reached level state 1!"); 
       state = 1;
       
    }
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) 
    {
      state = 9;
      // printf ("reached level state 9!");
    }
    if (  s[0] == 'r' 
       && s[1] == 'e'
       && s[2] == 's' 
       && s[3] == 'e'
       && s[4] == 't' 
       && s[5] == '\0'
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
