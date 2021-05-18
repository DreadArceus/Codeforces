#include <iostream>
#include "testlib.h"

using namespace std;

long long gcd(long long x, long long y)
{
    if(x == 0)
        return y;
    return gcd(y % x, x);
}

long long a, b;

void readAndCheckAnswer(InStream& in) {
    long long x = in.readLong();
    if(x == -1){
        if(a + b != 2)
            in.quitf(_wa, "jury has a valid answer, participant does not");
        return;
    }
    long long y = in.readLong();
    if(x < 0 || y < 0){
        in.quitf(_wa, "x and y must be positive");
    }
    else if(a + b != x + y){
        in.quitf(_wa, "a + b != x + y");
    }
    else if(a == x){
        in.quitf(_wa, "a is equal to x");
    }
    else if(b == y){
        in.quitf(_wa, "b is equal to y");
    }
    else if(gcd(x, y) != 1){
        in.quitf(_wa, "gcd(x, y) != 1");
    }
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    
    int t = inf.readInt();

    for(int i = 0; i < t; i++) {
        setTestCase(i + 1);
        a = inf.readLong();
        b = inf.readLong();

        readAndCheckAnswer(ans);
        readAndCheckAnswer(ouf);
    }

    quitf(_ok, "Correct Answer");
}
