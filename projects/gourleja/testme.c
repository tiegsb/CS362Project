/*
 *  Jason Gourley
 *  gourleja@oregonstate.edu
 *  CS362-400
 *  Quiz - testme.c
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

#define TESTCHARFULLKEYBOARD        1   // 1 For all character input            0 for only expected character input
#define TESTSTRINGFULLALPHABET      1   // 1 For all lowercase alphabet input   0 for only expected character input
#define TESTPRINTDEBUG              0   // 1 For printing debug messages        0 for no debug messages

char inputChar()
{
    if(TESTCHARFULLKEYBOARD == 1) { // Test the Full Set of possible keyboard character input
        char randomPull = (rand()%95)+32;
        assert(randomPull > 31 && randomPull < 127); // Random number should match possible keyboard characters
        if (TESTPRINTDEBUG == 1) {printf("\nc randomPull : %i\n", (int)randomPull);}
        return randomPull;
    } else if (TESTCHARFULLKEYBOARD == 0) { // Test only Expected characters pulled at random
        char testCharacters[] = "[({ ax})]";
        int randomPull = rand()%9;
        if (TESTPRINTDEBUG == 1) {printf("\nc randomPull : %i\n", (int)randomPull);}
        return testCharacters[randomPull];
    } else {
        printf("error");
        exit(-1);
    }
}

char *inputString()
{
    char testString[5];
    int i;
    if (TESTPRINTDEBUG == 1) {printf("s randomPull : ");}

    if(TESTSTRINGFULLALPHABET == 1) { // Test the Full Set of possible keyboard character input
        for (i = 0; i < 5; i++){
            testString[i] = (rand()%26)+97;
            assert(testString[i] > 31 && testString[i] < 127); // Random number should match lowercase alphabet characters
            if (TESTPRINTDEBUG == 1) {printf(" %i ", (int)testString[i]);}
        }
        testString[5] = '\0';
        if (TESTPRINTDEBUG == 1) {printf("\n");}
        return testString;
    } else if (TESTSTRINGFULLALPHABET == 0) { // Test only Expected characters pulled at random
        char testCharacters[] = "erst";
        for (i = 0; i < 5; i++){
            int randomPull = rand()%4;
            testString[i] = testCharacters[randomPull];
            if (TESTPRINTDEBUG == 1) {printf(" %i ", (int)testString[i]);}
        }
        testString[5] = '\0';
        return testString;
    } else {
        printf("error");
        exit(-1);
    }
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
