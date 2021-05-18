#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 100000, "n");
    inf.readEoln();
    for(int i = 0; i < n; i++){
        int x = inf.readInt(1, 1000000000, "x" + to_string(i));
        if(i != n - 1)
            inf.readSpace();
        else
            inf.readEoln();
    }
    inf.readEof();
}
