#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int length = rnd.next(500, 1000);
    cout << length << endl;
    for (int i = 0; i < length; i++)
        cout << char('a' + rnd.next(26));
    cout << endl;
}
