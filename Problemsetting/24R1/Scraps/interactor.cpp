#include "testlib.h"

int main(int argc, char **argv)
{
    registerInteraction(argc, argv);
    int n = inf.readInt();
    cout.flush();
    int left = 35;
    bool found = false;
    while (left > 0 && !found)
    {
        left--;
        int a = ouf.readInt(1, 1000000000);
        if (a < n)
            cout << 0 << endl;
        else if (a > n)
            cout << 2 << endl;
        else
            cout << 1 << endl, found = true;
        cout.flush();
    }
    if (!found)
        quitf(_wa, "couldn't guess the number with 35 questions");
    ouf.readEof();
    quitf(_ok, "guessed the number with %d questions", 35 - left);
}