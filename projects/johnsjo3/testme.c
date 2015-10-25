#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


char inputChar()
{
	char randChar = rand() % 256;			//range of valid ascii characters
    return randChar;
}

char *inputString()
{
	int i;
	const int STRING_SIZE = 6;							// 5 chars + 1 NULL char
	char * s = malloc(sizeof(char)* STRING_SIZE);
	memchr(s, 0, STRING_SIZE);
	
	char charArr[4] = {'e', 'r', 's', 't'};				//the letters that can cause failure if entered in the correct order
	
	//fill the random string
	for (i = 0; i < STRING_SIZE - 1; i++) {
		//s[i] = (rand() % 26) + 'a';				//26 letters in lowercase alphabet, ASCII offset is 'a' (or 97)
		s[i] = charArr[(rand() % 4)];
	}

    return s;
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
	
	free(s);
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
