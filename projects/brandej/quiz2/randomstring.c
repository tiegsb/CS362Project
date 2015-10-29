input char finds a random number using rand() and time() as a seed. It then attempts to convert it to a char. We do not try to pick valid ascii values.

Input string creates a char array and fills the indices with random characters. There is a 1/10 chance at each indicie of placing either: 'r', 'e', 's', 't', or '\n'.
Probability of picking "reset\n" is (1/10)^6 or 0.000001.

