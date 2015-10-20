#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // Get a random ASCII character
    // ASCII characters range from #0-127
    int N = 0;
    int M = 127;
    //get a random number between 0 and 127
    char cRand = M + rand() / (RAND_MAX / (N - M + 1) + 1);
    //return the randomly created character
    return cRand;
}

char *inputString()
{
    //Get 5 random letters 
    // ASCII characters 97-122 (lowercase a-z)
    
    // lowercase 'a'
    int N = 97;
    // lowercase 'z'
    int M = 122;
    int i = 0;
    //create space to store 5 char's
    char *sRand = malloc(sizeof(char) * 5);
    char cRand;
    //add 5 random characters to the input string
    for (i=0; i<5; i++){
        cRand = M + rand() / (RAND_MAX / (N - M + 1) +1);
	sRand[i] = cRand;
    }
    //return the array of 5 char's
    return sRand;
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
