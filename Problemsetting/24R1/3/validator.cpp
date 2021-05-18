#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int t = inf.readInt(1, 100, "t");
    inf.readEoln();
    for (int i = 0; i < t; i++) {
        setTestCase(i + 1);
        int a = inf.readLong(1, 1000000000000000000, "a");
        inf.readSpace();
        int b = inf.readLong(1, 1000000000000000000, "b");
        inf.readEoln();
    }
    inf.readEof();
}
