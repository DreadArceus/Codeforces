#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int length = 200000;
    cout << length << endl;
    cout << rnd.next("[a-z]{200000}") << endl;
    cout << length << endl;
    for (int i = 0; i < length; i++){
        int type = rnd.next(1, 2);
        cout << type << " ";
        if(type == 1)
        {
            int l = rnd.next(1, length);
            cout << l << " " << rnd.next(l, length) << endl;
        }
        else
            cout << rnd.next(1, length) << " " << rnd.next("[a-z]{1}") << endl;
    }
}
