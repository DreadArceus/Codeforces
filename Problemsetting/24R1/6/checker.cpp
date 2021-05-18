#include <iostream>
#include "testlib.h"

using namespace std;

long long readAndCheckAnswer(InStream &in)
{
    long long ans = in.readLong();
    return ans;
}

int main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);

    int n = inf.readInt();
    int x = inf.readInt();
    for (int i = 0; i < n; i++)
        int a = inf.readInt();

    long long ja = readAndCheckAnswer(ans);
    long long pa = readAndCheckAnswer(ouf);

    if (ja != pa)
        quitf(_wa, "jury has a different answer");

    quitf(_ok, "Correct Answer");
}
