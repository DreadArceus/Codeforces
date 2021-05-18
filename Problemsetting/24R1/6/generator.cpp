#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    for (int i = 1; i <= 10; i++){
        startTest(i);
        int length = 100000;
        cout << length << endl;
        for (int i = 0; i < length; i++)
            cout << rnd.next(1, 1000000000) << (i != length - 1 ? " " : "");
        cout << endl;
    }
}
