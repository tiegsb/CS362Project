#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{

    /*NOTE: I realized later that I didn't need to create a character array after all
    as all char's in c are represented by a unique number anyways. 
    My implementation could've led to some super special chars 
    being ommitted but the random test is still functional without any major 
    repercussions.*/

    char charArray[]="abcdefghijklmnopqrstuvwxyz ~`!@#$%^&*()_-+={[}]\\|\"\':;?/>.<,";
    int charMaxNumber=59;

    int randomNumber=rand() % 59;

    char chosenChar=charArray[randomNumber];

    return chosenChar;
}

char *inputString()
{
    
    char charArray[]="rest";
    int charMaxNumber=4;
    char* randomString = (char*)malloc(6 * sizeof(char));
    int knownStringLength=6;
    char string[6];
    char retString[6];
    int i;
    int randomNumber;


    for(i=0; i<knownStringLength-1; i++) {

        randomNumber=rand() % charMaxNumber;

        randomString[i]=charArray[randomNumber];
    }

    //append string escape character to the last index
    randomString[5]='\0';


    return randomString;
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