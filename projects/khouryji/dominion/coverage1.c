The dominion coverage was very low. It was lower than seems normal. I am going to
spend time investigating what may have caused such a low result. Unfortunately,
because the functions weren't in their own files, it was harder to get a better
idea of what percentage coverage there was for each function. I might create
separate files for these functions and then link them to dominion to see if I
can get more specific coverage percentages. 

While I was going through the dominion gcov file, I noticed that there were 
conditions that had not being covered. It would appear that this debugging
session did not even attain good statement coverage, let alone branch coverage.

I might have been able to get better coverage simply by increasing the number
of tests, but because we are storing the output for each test, I didn't want
to create too much output.

Ultimately, I would like to not only get a good statement coverage, where every
code statement is covered, but I would also like to get good branch coverage,
where many combinations of conditions and paths are explored.

These were the results from running gcov on each of the unittests:
flip2 ~/CS362/HW3 319% gcov cardtest1.c
File 'cardtest1.c'
Lines executed:89.58% of 48
cardtest1.c:creating 'cardtest1.c.gcov'

flip2 ~/CS362/HW3 320% gcov cardtest2.c
File 'cardtest2.c'
Lines executed:96.55% of 58
cardtest2.c:creating 'cardtest2.c.gcov'

flip2 ~/CS362/HW3 321% gcov cardtest3.c
File 'cardtest3.c'
Lines executed:80.52% of 77
cardtest3.c:creating 'cardtest3.c.gcov'

flip2 ~/CS362/HW3 322% gcov cardtest4.c
File 'cardtest4.c'
Lines executed:93.75% of 48
cardtest4.c:creating 'cardtest4.c.gcov'

flip2 ~/CS362/HW3 323% gcov unittest1.c
File 'unittest1.c'
Lines executed:64.89% of 94
unittest1.c:creating 'unittest1.c.gcov'

flip2 ~/CS362/HW3 324% gcov unittest2.c
File 'unittest2.c'
Lines executed:81.97% of 61
unittest2.c:creating 'unittest2.c.gcov'

flip2 ~/CS362/HW3 325% gcov unittest3.c
File 'unittest3.c'
Lines executed:79.25% of 53
unittest3.c:creating 'unittest3.c.gcov'

flip2 ~/CS362/HW3 326% gcov unittest4.c
File 'unittest4.c'
Lines executed:65.48% of 84
unittest4.c:creating 'unittest4.c.gcov'

Please see unittestresults.out for other results.