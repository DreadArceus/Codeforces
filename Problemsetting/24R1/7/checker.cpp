#include <iostream>
#include "testlib.h"

using namespace std;

int n, cntQ1;

vector<int> readAndCheckAnswer(InStream& in) {
    vector<int> ans;
    for (int i = 0; i < cntQ1; i++){
        int x = in.readInt();
        if(x < 0 || x > n){
            in.quitf(_wa, "does not satisfy constraints");
            break;
        }
        ans.push_back(x);
    }
    return ans;
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    n = inf.readInt();
    inf.readEoln();
    string s = inf.readString();
    int q = inf.readInt();
    cntQ1 = 0;
    for (int i = 0; i < q; i++) {
        int type = inf.readInt();
        if(type == 1){
            int l = inf.readInt();
            int r = inf.readInt();
            cntQ1++;
        }
        else if(type == 2){
            int i = inf.readInt();
            inf.readToken();
        }
    }

    vector<int> ja = readAndCheckAnswer(ans);
    vector<int> pa = readAndCheckAnswer(ouf);

    for(int i = 0; i < cntQ1; i++){
        if(ja[i] != pa[i]){
            quitf(_wa, "non optimal");
        }
    }

    quitf(_ok, "Correct Answer");
}
