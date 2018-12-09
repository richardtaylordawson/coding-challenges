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
