#include <iostream>
#include "testlib.h"

using namespace std;

int readAndCheckAnswer(InStream &in)
{
    int ans = in.readInt();
    return ans;
}

int main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);

    int n = inf.readInt();
    int m = inf.readInt();
    for (int i = 0; i < m; i++)
    {
        int u = inf.readInt();
        int v = inf.readInt();
        int w = inf.readInt();
    }

    int ja = readAndCheckAnswer(ans);
    int pa = readAndCheckAnswer(ouf);

    if (ja != pa)
        quitf(_wa, "jury has a different answer");

    quitf(_ok, "Correct Answer");
}
