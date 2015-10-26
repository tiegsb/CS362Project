#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
	//Create the random character from ASCII 32 - ASCII 125
	//this range includes all the special chars required
	char randchar = rand() % (125 - 32) + 32;
	return randchar;
}

char *inputString()
{
	int i = 0,
		randNum = 0;
	//allocate enough memory for the string (5 chars + NULL terminator)
	char *randstring = malloc(sizeof(char) * 7);	
	char *targetStr = "reset";

	//iterate through ever space in randstring and assign
	//a variable to it from the target
	for (i = 0; i < 5; i++)
	{
		randNum = rand() % 5;
		randstring[i] = &targetStr[randNum];
	}
	randstring[5] = '\0';
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


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
