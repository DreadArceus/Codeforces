#include <string>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 200000, "n");
    inf.readEoln();
    string s = inf.readString("[a-z]{" + to_string(n) + "}", "s");
    int q = inf.readInt(1, 200000, "q");
    inf.readEoln();
    for (int i = 0; i < q; i++) {
        int type = inf.readInt(1, 2, "type");
        inf.readSpace();
        if(type == 1){
            int l = inf.readInt(1, n, "l");
            inf.readSpace();
            int r = inf.readInt(l, n, "r");
        }
        else if(type == 2){
            int i = inf.readInt(1, n, "i");
            inf.readSpace();
            inf.readToken("[a-z]{1}", "c");
        }
        inf.readEoln();
    }
    inf.readEof();
}
