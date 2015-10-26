#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

const char* chars = "[({ ax})]";
const char* str = "reset";


char inputChar()
{
  //get a number between 0-8
  int r = rand()%9;

  return chars[r];  
}


//changed function to return void and take in a preallocated string so that I don't have to delete the string after each
//call of the function
void inputString(char s[6])
{
  int i;
  int r;

  for (i=0; i<5; ++i)
  {    
    s[i] = str[rand()%5];
  }
  s[5] = '\0';
}

void testme()
{
  //set up random number generator
  srand(time(NULL));
  

  int tcCount = 0;
  char s[6];
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    inputString(s);
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


int main()
{
  testme();
  return 0;
}