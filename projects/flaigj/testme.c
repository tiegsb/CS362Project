/*
 * Author: Jason Flaig
 * Date: 10/25/2015
 * Citation: http://codereview.stackexchange.com/questions/29198/random-string-generator-in-c
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // generate random number 0 - 8
    char ch;
    int ran = rand() % 9;

    // use random numbers as integer cases returning necessary output chars
    switch(ran)
    {
    	case 0:
    	ch = '[';
    	break;

    	case 1:
    	ch = '(';
    	break;

    	case 2:
    	ch = '{';
    	break;

    	case 3: 
    	ch = ' ';
    	break;

    	case 4:
    	ch = 'a';
    	break;

    	case 5:
    	ch = 'x';
    	break;

    	case 6:
    	ch = '}';
    	break;

    	case 7:
    	ch = ')';
		break;

		case 8:
		ch = ']';
		break;
    }

    return ch;
}

char *inputString()
{
	// generate random number 0 - 5
	// run a loop generating random numbers
	// assign myString to mySet[idx rand]
	
	int i;
	char *myString = malloc(sizeof (char)*6);
	const char mySet[] = "reset";
		
    for (i = 0; i < 5; i++) 
    {
        int ran = rand() % 5;
        myString[i] = mySet[ran];
    }
    
    myString[5] = '\0';

    return myString;
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
