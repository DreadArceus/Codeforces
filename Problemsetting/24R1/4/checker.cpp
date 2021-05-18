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

    int t = inf.readInt();

    for (int i = 0; i < t; i++)
    {
        setTestCase(i + 1);
        long long a = inf.readLong();
        long long b = inf.readLong();

        long long ja = readAndCheckAnswer(ans);
        long long pa = readAndCheckAnswer(ouf);

        if (ja != pa)
            quitf(_wa, "jury has a different answer");
    }

    quitf(_ok, "Correct Answer");
}
