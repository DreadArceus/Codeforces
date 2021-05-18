#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    for (int i = 11; i <= 15; i++){
        startTest(i);
        int length = 100000;
        cout << length << endl;
        cout << 1000000000 << " ";
        int x = rnd.next(5, 1000000);
        for (int i = 1; i < length - 1; i++)
        {
            cout << x << " ";
            if(i >= length / 2)
                x--;
            else
                x++;
        }
        cout << 1000000000 << endl;
    }
}
