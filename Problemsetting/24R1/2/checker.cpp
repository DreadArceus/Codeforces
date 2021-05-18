#include <iostream>
#include "testlib.h"

using namespace std;

pair<char, int> readAndCheckAnswer(InStream& in) {
    char c = in.readChar();
    int y = in.readInt(1, 100000);
    return make_pair(c, y);
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    
    int n = inf.readInt();
    string s = inf.readString();

    pair<char, int> ja = readAndCheckAnswer(ans);
    pair<char, int> pa = readAndCheckAnswer(ouf);

    if(ja.second != pa.second)
        quitf(_wa, "Jury has the better answer");
    if(ja.first != pa.first)
        quitf(_wa, "Jury has chosen a different letter");

    quitf(_ok, "Correct Answer", n, s);
}
