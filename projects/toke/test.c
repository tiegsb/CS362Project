#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

// GLOBALs
char *string;

int GenerateRandomNumber(const int minNumber, const int maxNumber);

char inputChar()
{
  // randomly generate a char between 'space' and '~'
  int randChar = GenerateRandomNumber(32, 126);
  return randChar;
}

char *inputString()
{
  int i;

  // Free the global string
  free(string);

  // Allocate new memory for the string
  string = malloc(sizeof(char) * 6);

  // Randomly generate the string with letters between 'e' and 't'
  for (i = 0; i < 5; i++)
  {
    string[i] = GenerateRandomNumber(101, 116);
  }
  string[5] = '\0'; // Null terminate the string

  return string;
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

int GenerateRandomNumber(const int minNumber, const int maxNumber)
{
  // Generate random number
  int range = maxNumber - minNumber;
  return (minNumber + (rand() % (range + 1)));
}