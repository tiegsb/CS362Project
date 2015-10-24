#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

static const size_t MIN_INPUT_STRING = 2;
static const size_t MAX_INPUT_STRING = 9;

int randRange(int min, int max) {
  return (rand() % (max - min)) + min;
}

char randChar(const char *chars, size_t nchars) {
  return chars[rand() % nchars];
}

char inputChar() {
  // TODO: rewrite this function

  char cs[] = "[](){}ax ";
  size_t n = sizeof(cs) / sizeof(cs[0]);

  return randChar(cs, n - 1);
}

char *inputString() {
  static char s[MAX_INPUT_STRING];
  char x[] = "reset";
  size_t n = sizeof(x) / sizeof(x[0]);
  size_t i;
  int len = randRange(MIN_INPUT_STRING, MAX_INPUT_STRING);

  for (i = 0; i < len; i++) {
    s[i] = randChar(x, n);
  }

  return s;
}

void testme() {
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1) {
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
    if (s[0] == 'r' && s[1] == 'e' && s[2] == 's' && s[3] == 'e' &&
        s[4] == 't' && s[5] == '\0' && state == 9) {
      printf("error ");
      exit(200);
    }
  }
}

int main(int argc, char *argv[]) {


  srand(time(NULL));
  testme();
  return 0;
}