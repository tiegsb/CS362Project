/*
char inputChar()
{
    char randomChar =  ' ' + (rand() % 95); 
    return randomChar;
}
finds random ASCII character 32-126 and returns


char * inputString()
{
  static char randomString[6];
  for (int i = 0; i < 5; i++) {
    randomString[i] = 'a' + (rand() % 26);
  }
  randomString[5] = 0;
  return randomString;
}
finds random string of 5 letters, eventually produces "reset" to produce an error
*/