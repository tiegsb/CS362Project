Woo Choi
CS362
Quiz 2

Implement inputChar(), *inputString() for random testing. 
inputChar() will get printable chars from ASCII 32-127.
inputString() will get the alphabet (lowercase). 

testme will start with inputChar() match its char with below chars

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
	
As you see, it will slowly progress to state 9 after many iterations.

Then it will use inputString() for 5 letters in var s. s[5] will be set to null.
Once it randomly becomes reset\0, along with state that = 9, program will
exit and print error.

That's all it does.
I ran a test and it took me something of 20 million iterations. 
Fun stuff