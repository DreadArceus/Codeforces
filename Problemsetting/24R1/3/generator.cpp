#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int tests = 100;
    cout << tests << endl;
    for (int i = 0; i < tests; i++)
        cout << rnd.next(100000000000000000, 1000000000000000000) << " " << rnd.next(100000000000000000, 1000000000000000000) << endl;
}
