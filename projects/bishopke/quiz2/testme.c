#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
    //return ' ';
	switch(rand()%9){
		case 0: return '['; break;
		case 1: return '('; break;
		case 2: return '{'; break;
		case 3: return ' '; break;
		case 4: return 'a'; break;
		case 5: return 'x'; break;
		case 6: return '}'; break;
		case 7: return ')'; break;
		case 8: return ']'; break;
		default: return ' '; break;
	}
}

char *inputString()
{
	int i = 0;
	//make 5 char string
	char *s = malloc(6*sizeof(char));

	for(i = 0; i < 5; i++){
		switch(rand()%4){
			case 0: s[i] = 'r'; break;
			case 1: s[i] = 'e'; break;
			case 2: s[i] = 's'; break;
			case 3: s[i] = 't'; break;
			default: return ' '; break;
		}
	}
	//add null terminator
	s[6] = '\0';
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
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
