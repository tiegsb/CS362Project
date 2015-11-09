
    The adventurer card test is now at full coverage from its 67% from last time. For the
adventurer card test the bugs I introduced would cause the currentPlayer variable to become
overwritten by what appear to be a array bounds overflow. This now invaild data would cause a
Segfault in the tester and crash. To get pass this I place a check in the code at the exact spot
it happens to let my test finish. Overall this check is called 641 out of 2000 tests. The other
Card I tested was the smithy again which when writing the random tester I found that when I
introduce the bugs in it. I had but a unintional bug on top of the bug I intended to make.
I have fixed that said bug as it was unintentional and was going to cause the scope to segfault
every time unless I made the tester not so random anymore. The smithy card had full coverage before
but I still found more bugs by putting it through a random tester. This show that even having full
coverage with some tests can still let bugs slip though.
