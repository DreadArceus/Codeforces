#include <iostream>
#include "testlib.h"

using namespace std;

int n;
vector<int> v;

vector<int> readAndCheckAnswer(InStream& in) {
    vector<int> ans = in.readInts(n);
    for(int i = 0; i < ans.size(); i++) {
        if(ans[i] == -1) continue;
        if(ans[i] < 0 || v[i] >= v[ans[i]])
        {
            in.quitf(_wa, "does not fit constraints");
            return { -2 };
        }
    }
    return ans;
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    
    n = inf.readInt();
    v = inf.readInts(n);

    vector<int> ja = readAndCheckAnswer(ans);
    vector<int> pa = readAndCheckAnswer(ouf);

    if(ja[0] == -2 || pa[0] == -2)
        return 0;

    for(int i = 0; i < n; i++)
    {
        if(pa[i] == -1)
        {
            if(ja[i] == -1) continue;
            quit(_wa, "jury has a better answer");
            return 0;
        }
        if(ja[i] == -1) continue;
        if(abs(pa[i] - i) > abs(ja[i] - i))
        {
            quit(_wa, "jury has a better answer");
            return 0;
        }
    }
    quitf(_ok, "Correct Answer");
}
