#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

// Adding comment to update git commit

char inputChar()
{
    // TODO: rewrite this function

    // create random character
    int randNum = rand()%127;
    char randChar = randNum;
	
    // return random character
	return randChar;//randChar;
}

char *inputString()
{
    // TODO: rewrite this function

	// declare some variables
    int strSize = 6;    // determine size of string
	char *randStr = malloc(16);
	char randChar;
    int i, testInt;

	if (!randStr) return NULL;	// return null if string mem cannot be allocated
	
	// create string of random lowercase letters 
    for(i = 0; i < strSize-1; i++){
        testInt = rand()%26 + 97;
		
		// narrow down the possibilities of the random lowercase letters
		// this will increase the chance of getting "reset"
		while(testInt < 101 || testInt > 116){
			testInt = rand()%26 + 97;
			// for "(test > 101 && testInt < X)", make X 114 to get max probability of getting
			// the word "reset" adjust to a lower number to decrease the chance
			while(testInt >101 && testInt < 112) testInt = rand()%26 + 97;
		}
		randChar = testInt;
		randStr[i] = randChar;
	}
    randStr[strSize-1] = '\0';
	
    return randStr;//randStr;
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
    //delay(1000);    // give this program a pause
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
