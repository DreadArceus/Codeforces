#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int x;

inline void readAndCheckAnswer(InStream& in) {
    int y = in.readInt(); 

    if(2 * x >= y) {
        in.quitf(_wa, "y must be greater than 2 * x");
    }
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    
    x = inf.readInt();

    readAndCheckAnswer(ans);
    readAndCheckAnswer(ouf);

    quitf(_ok, "x=%d", x);
}
