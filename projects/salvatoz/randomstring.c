/**
 * In order to test this code, I implemented inputChar to return random
 * characters in the expected range. I verified that this would cause the
 * program to eventually reach state 9 by using grep:
 *      ./testme | grep -n -m 1 "state = 9"
 * I then implemented inputString to return random permutations of the 
 * characters 'r', 'e', 's', 'e', 't', and '\0'. I then verified that this would 
 * cause the program to reach its error state and terminate, again using grep:
 *      ./testme | grep -n -m 1 "error"
 */

int main(int argc, char **argv) {
        return 0;
}