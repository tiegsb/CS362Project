/************************************
 * Author:  Brian Stamm
 * Program:  randomstring.c
 * Date:  10.25.15
 * Notes:  This is a basic explanation of the testme.c program.
 * ********************************/

/*
 * In Quiz 2, it was asked to complete the program "testme.c", where 2
 * functions needed to be written - inputChar() and inputString().  The
 * testme() function was written, and in this function it has a forever
 * while loop that calls both inputChar() and inputString().  Then an series
 * of 'if' statements assesses the values returned by those functions, and if
 * they are in a certain range, the value of the a variable called "state" is
 * increased.  Once the state value reaches 9, the program exits with a 200
 * exit value.
 *
 * In writing the inputChar() function, I created a simple array [rArray] which has
 * all the values the if statement test for that specific function.  Since there
 * are only 9 values, the array is filled with only 9 characters.  Depending on the
 * need of the program, this could be increases to whatever was needed.  I chose to
 * use the minimal needed value so the testme.c file would not run for a long time.
 * Then using the rand() function, I created an int whose value was the range in the
 * array [r = rand() % 9].  This allowed the function to return the character in the 
 * array [rArray[r]].
 *
 * A similar thought process was used with inputString() function.  I created an
 * array [rArray] with the values of the string tested for in the testme() function.
 * Then a for loop was used to fill an char array (or a string) with those values.
 * The function then returns the completed string.  As with the previous function, 
 * rArray could have been filled with more character and options, but I chose brevity
 * rather than an exhaustive list.
 *
 * Enjoy running the program.  The few times I ran it, it goes through around 3500+
 * iterations before exiting, but I got as low as 226.
 */
