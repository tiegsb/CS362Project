//Unit test of compare function from dominion.c

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "assert.h"
#include "unittest1.h"

int compare(const void* a, const void* b);

int testCompare(int aValue, int bValue, int retval, const char* message)
{
	int* const a = malloc(sizeof(int));
	int* const b = malloc(sizeof(int));

	*a = aValue;
	*b = bValue;

	int fail = assert(compare((const void*)a, (const void*)b) == retval, "compare()", message);

	free(a);
	free(b);

	return fail;
}

//
int unitTest1()
{
	int fail_count = 0;

	fail_count += testCompare(0, 0, 0, "should return 0 when a and b are equal");
	fail_count += testCompare(1, 0, 1, "should return 1 when a is greater than b");
	fail_count += testCompare(0, 1, -1, "should return -1 when a is less than b");

	return fail_count;
}