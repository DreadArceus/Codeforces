#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int length = 10000;
    cout << length << endl;
    cout << rnd.next("[a-z]{10000}") << endl;
    cout << length << endl;
    for (int i = 0; i < length; i++)
        cout << "1 1 " << length << endl;
}
