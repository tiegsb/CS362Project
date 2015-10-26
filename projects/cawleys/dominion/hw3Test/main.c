//test.c

#include <stdio.h>
#include <stdlib.h>
#include "unittest1.h"
#include "unittest2.h"
#include "unittest3.h"
#include "unittest4.h"
#include "cardtest1.h"
#include "cardtest2.h"
#include "cardtest3.h"
#include "cardtest4.h"

int main()
{
	int fail_count = 0;

	printf("\n");

	//call test case 1 - compare function
	fail_count += unitTest1();

	//call test case 2  - whoseTurn
	fail_count += unitTest2();

	//call test case 3 - updateCoins
	fail_count += unitTest3();

	//call test case 4 - fullDeckCount
	fail_count += unitTest4();

	//call card1 -Smithy
	fail_count += cardtest1_cardsReceived();

	//call card2 -Adventurer
	fail_count += cardtest2();

	//call card3 -Village
	fail_count += cardtest3();

	//call card4 - Great Hall
	fail_count += cardtest4();

	if (fail_count != 0) {
		printf("\n%i tests failed\n\n", fail_count);
	} else {
		printf("\nall tests passed\n\n");
	}

	// return 1 if any tests fail, or 0 if all tests pass.
	return fail_count != 0 ? 1 : 0;
}