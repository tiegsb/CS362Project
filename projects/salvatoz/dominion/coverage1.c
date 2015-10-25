/*
According to gcov, my unit tests achieve 100% statement and branch coverage.

My card tests achieve fairly good coverage. Smithy's branch coverage basically 
reveals the exact bug that I introduced if you pay attention. Adventurer
gets no coverage data because of a segfault, but this still exposes a bug.
Council Room gets 100% line, branch, loop, and call coverage. Mine gets 88%
line coverage, 100% branch coverage, 60% loop coverage, and 100% call coverage.

I think this test suite can uncover a reasonable amount of bugs. It has pretty 
good coverage and does an adequate job of checking state validity. However,
the high coverage doesn't tell us much about its quality. It would be easy to
make a bunch of calls to get high coverage scores without actually checking that
the program is in a valid state afterwards. All high coverage really 
accomplishes is checking that nothing segfaults.
*/

int main(int argc, char **argv) {
  return 0;
}