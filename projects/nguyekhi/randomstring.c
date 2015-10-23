/*
	I kind of write the generate functions according to the conditions in the testMe() function
	
	For function char inputChar(), I generate the random character that represented by number
	32 to 128, they include all the character in the testMe() function: '[', '(', '{', ' ',
	'a', 'x', '}', ')', ']'. However it also generate other chracter to test the condition
	
	For function inputString(), I try to generate the random string from lowercase letter
	which represented by number 97 to 122. But it took really long to achieve the terminate
	condition in the testMe() function. So I reduce the randomness to the corrected letter
	in the testMe() function which are 'e', 'r', 's', 't'. Of course they finally reach the
	termination condition, in order to printf("error") and exit 

	I also check the gcov and it achieve 100% branch coverage which is pretty good for testing

*/