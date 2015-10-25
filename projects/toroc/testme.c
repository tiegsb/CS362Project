/*
*	CS362 - Quiz #2 - testme.c
*	
*	Author: Carol D. Toro
*	Date: 10/21/2015
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


/*
* returns a random char
*/
char inputChar()
{
	char allowedChars[22];

	allowedChars[0] = 'a';
	allowedChars[1] = 'x';
	allowedChars[2] = 'r'; 
	allowedChars[3] = '(';
	allowedChars[4] = 'S'; 
	allowedChars[5] = '[';
	allowedChars[6] = 'e';
	allowedChars[7] = ')';
	allowedChars[8] = 't';
	allowedChars[9] = '{';
	allowedChars[10] = 'e';
	allowedChars[11] = 's'; 
	allowedChars[12] = ' ';
	allowedChars[13] = 'e';
	allowedChars[14] = 'R'; 
	allowedChars[15] = '}';
	allowedChars[16] = '\0';
	allowedChars[17] = 'E';
	allowedChars[18] = ']';
	allowedChars[19] = 'T';
	allowedChars[20] = ']';
	allowedChars[21] = 'E'; 

	int i;
	i = rand() % 22;
   
	return (unsigned char)allowedChars[i];
}

/*
* returns a string created by random chars
*/
char *inputString()
{
	int i;
	char randString[6];

	for (i = 0; i < 6; i++)	{		randString[i] = inputChar();	}	/*Always make last character in string as '\0'*/	randString[5] = '\0';	char *temp;	temp = (char*)malloc(6 * sizeof(char));	for (i = 0; i < 6; i++)	{		temp[i] = randString[i];	}	return temp;
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
