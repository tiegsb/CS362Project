//Solomon Huynh - huynhtri
//CS362 Quiz 2

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
    //Generates the code from the ASCII value 32 to 125 so it can generate all the special characters in the testme function.
    char c = rand() % (125 - 32 + 1) + 32;
    return c;
}

char *inputString()
{
    // TODO: rewrite this function
    //Allocate memory to hold 5 letters plus a null terminator
    char *s = malloc(sizeof(char) * 6);
    int randomNumber;               //Used to hold a random number
    int secondRand;                 //Used to hold a second random number
    char testWord[] = "reset";
    int i;

    //For loop to randomly generate numbers ranging from the letters a (97) to z (122) using ASCII values.
    for(i = 0; i < 5; i++){
        randomNumber = rand() % (122 - 97 + 1) + 97;
        s[i] = randomNumber;
    }

    //Randomly place the correct letters in two positions to shorten the iteration to form the word reset
    //from 26^5 to 26^3.
    randomNumber = rand() % 5;
    s[randomNumber] = testWord[randomNumber];
    secondRand = rand() % 5;
    //Sets a while loop to make sure secondRand doesn't equal randomNumber
    while(randomNumber == secondRand){
        secondRand = rand() % 5;
    }
    s[secondRand] = testWord[secondRand];

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
    if (c == ' ' && state == 3) state = 4;
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
