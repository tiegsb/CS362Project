#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
    char c;

    // version 1 assigns random value in tested values of c in testme()
    //int r = rand() % 9;
    //switch(r) {
    //    case 0 :
    //        c = '[';
    //        break;
    //    case 1 :
    //        c = '(';
    //        break;
    //    case 2 :
    //        c = '{';
    //        break;
    //    case 3 :
    //        c = ' ';
    //        break;
    //    case 4 :
    //        c = 'a';
    //        break;
    //    case 5 :
    //        c = 'x';
    //        break;
    //    case 6 :
    //        c = '}';
    //        break;
    //    case 7 :
    //        c = ')';
    //        break;
    //    case 8 :
    //        c = ']';
    //        break;
    //}

    //version 2 gets random letter, symbol, or number
    c = (rand() % 95) + ' ';

    return c;
}

char *inputString()
{
    char s[6] = "     ";
    int i;
//version 1 (FAST)
    //for each index in s, assign random value of value subset
    for (i = 0; i < 6; i++) {
        int r = rand() % 5;
        if (r == 0) {
            s[i] = 'r';
        }
        else if (r == 1) {
            s[i] = 'e';
        }
        else if (r == 2) {
            s[i] = 's';
        }
        else if (r == 3) {
            s[i] = 't';
        }
        else
            s[i] = '\0';
    }

//version 2 (SLOW)
    //for each index in s, call inputChar v2
    //for (i = 0; i < 5; i++) {
    //    s[i] = inputChar();
    //}

    return &s;
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
