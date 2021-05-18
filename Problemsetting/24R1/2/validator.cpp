#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 100000, "n");
    inf.readEoln();
    string s = inf.readString("[a-z]{" + to_string(n) + "}", "s");
    inf.readEof();
}
