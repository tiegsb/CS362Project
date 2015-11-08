#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
    int randNum = rand() % 33;
    char randomChar;

    switch(randNum) {
        case 0:
            randomChar = 'a';
            break;
        case 1:
                randomChar = 'b';
        break;
        case 2:
                randomChar = 'c';
        break;
        case 3:
                randomChar = 'd';
        break;
        case 4:
                randomChar = 'e';
        break;
        case 5:
                randomChar = 'f';
        break;
        case 6:
                randomChar = 'g';
        break;
        case 7:
                randomChar = 'h';
        break;
        case 8:
                randomChar = 'i';
        break;
        case 9:
                randomChar = 'j';
        break;
        case 10:
                randomChar = 'k';
        break;
        case 11:
                randomChar = 'l';
        break;
        case 12:
                randomChar = 'm';
        break;
        case 13:
                randomChar = 'n';
        break;
        case 14:
                randomChar = 'o';
        break;
        case 15:
                randomChar = 'p';
        break;
        case 16:
                randomChar = 'q';
        break;
        case 17:
                randomChar = 'r';
        break;
        case 18:
                randomChar = 's';
        break;
        case 19:
                randomChar = 't';
        break;
        case 20:
                randomChar = 'u';
        break;
        case 21:
                randomChar = 'v';
        break;
        case 22:
                randomChar = 'w';
        break;
        case 23:
                randomChar = 'x';
        break;
        case 24:
                randomChar = 'y';
        break;
        case 25:
                randomChar = 'z';
        break;
        case 26:
                randomChar = '{';
        break;
        case 27:
                randomChar = '[';
        break;
        case 28:
                randomChar = '(';
        break;
        case 29:
                randomChar = ')';
        break;
        case 30:
                randomChar = '}';
        break;
        case 31:
                randomChar = ']';
        break;
        case 32:
                randomChar = ' ';
        break;
    }

    return randomChar;
}

char *inputString()
{
    // TODO: rewrite this function
    char randomString[6];
    int t = 0;

    for (t = 0; t < 5; t++) {
        randomString[t] = inputChar();
    }
    randomString[5] = '\0';

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
