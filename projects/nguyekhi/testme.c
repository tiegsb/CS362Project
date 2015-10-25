#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    char c = rand() % (128 - 32 + 1) + 32;  // generate random character which represent by number 32 to 128

    return c;
}

char *inputString()
{
    // so I try to generate the random string of lower case letter which represented by number 97 to 122 but it took quiet a long time
    //to achieve the terminate condition. So I think it is best to generate the random string from the corrected characters which is
    char array[4] = {'e','r','s','t'};
    char *randomString = malloc(sizeof (char) * 6);
    randomString[5] = '\0';     //set the last character of the string is \0
    int i;
    for (i = 0; i < 5; i++)
    {
      randomString[i] = array[rand() % 4]; // generate random character (lower case letter) represented by number 97 to 122
    }
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
