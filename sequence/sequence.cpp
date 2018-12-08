// CHALLENGE
// -----------------------------------------------------------------
// Write a program to generate the following sequence
// A = (11110000111000110010)
//
// Do not Hard Code
// Do not use switch or if statements
// Do not manipulate loops to make them match if statements either
// Don't use more than 5 for/do while/while loops in any combination
// -----------------------------------------------------------------

#include <iostream>
#include <array>

using namespace std;

int main(int argc, char *argv[]) {
    cout << "A = (";

    for(int i = 4; i > 0; i--) {
        for(int j = 0; j < i; j++){
            cout << "1";
        }

        for(int k = 0; k < i; k++) {
            cout << "0";
        }
    }

    cout << ")";

    return 0;
}
