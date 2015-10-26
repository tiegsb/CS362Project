#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // To minimize the input range, use only these characters:
    char * chars_to_test = "[({ ax})]";
    int rand_num = rand() % 9; // 9 chars to test 
    char output = chars_to_test[rand_num];
    return output;
}

char *inputString()
{
    int length = 6; // That's how long testme() tests up until
    char * output = malloc(sizeof(int) * length);
    int i;
    char * chars_to_test = "erst"; //Used to minimize input range
    for (i = 0; i < length - 1; i++) {
      int rand_num = rand() % 4;
      char output_char = chars_to_test[rand_num];
      output[i] = output_char;
    }
    output[length - 1] = '\0'; // Assuming the string should have null term
    return output;
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
