#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int t = inf.readInt(1, 100, "t");
    inf.readEoln();
    for (int i = 0; i < t; i++) {
        setTestCase(i + 1);
        int a = inf.readInt(1, 100, "a");
        inf.readSpace();
        int b = inf.readInt(1, 100, "b");
        inf.readEoln();
    }
    inf.readEof();
}
