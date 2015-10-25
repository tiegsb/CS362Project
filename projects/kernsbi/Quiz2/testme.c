// Name: Billy Kerns
// File: testme.c
// Quiz 2

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <time.h>

char inputChar()
{
    char charArray[9] = {'[', '(', '{', ' ', 'a', 'x', '}', ')', ']'};
    int random;
    random = (rand() % (9));
    return charArray[random];
}

char *inputString()
{
  char stringArray[10] = {'r', 'e', 's', 't', 'a', 'b', 'c', 'd', 'k', '\0'};
  char *string = malloc(sizeof(char) * 6);
  int i;
  for(i = 0; i < 6; i++){
    string[i] = stringArray[(rand() % (10))];
//	string[i] = inputChar();
  }
    return string;
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
