#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 100, "n");
    inf.readSpace();
    int x = inf.readInt(1, 100000, "x");
    inf.readEoln();
    for(int i = 0; i < n; i++){
        int a = inf.readInt(1, 100000, "a" + to_string(i));
        if(i != n - 1)
            inf.readSpace();
        else
            inf.readEoln();
    }
    inf.readEof();
}
