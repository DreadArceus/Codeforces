#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int length = 100000;
    cout << length << endl;
    int x = rnd.next(1, 1000000000);
    for (int i = 0; i < length - 1; i++)
        cout << x << " ";
    cout << x << endl;
}
