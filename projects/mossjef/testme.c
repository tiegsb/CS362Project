/*
 * File Name:	testme.c
 * Author:	Jeff Moss
 * Date:	10-20-15
 * Description:	Random tester of the testme function
 * Class:	CS362 Fall 2015
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//Top of the ASCII scale for characters
#define TOP 126
//Bottom of the ASCII scale for characters
#define BOTTOM 32
//Bottom of the ASCII scale for lower case letters
#define BOTTOMa 97
//Top of the ASCII scale for lower case letters
#define TOPz 122
#define STLEN 6

char inputChar()
{
	//Create a random number from BOTTOM to TOP inclusive
	int randNum;
	randNum = rand() % (TOP+1-BOTTOM) + BOTTOM; 
	//Return a casted char
	return ((char) randNum);
}

char *inputString()
{
	int randNum;	
	//Create a string of size STLEN
	char * testString = malloc(STLEN);
	int i;

	//Set first char to r to make random testing deeper
	testString[0] = 'r';
	for(i=1; i < STLEN-1; i++) {
		//Create a random number from BOTTOMa to TOPz inclusive
		randNum = rand() %(TOPz+1-BOTTOMa) + BOTTOMa;
		testString[i] = (char) randNum;
	}
	testString[STLEN] = '\0';	
	return testString;
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
	//Added to free allocated memory
	free(s);
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
