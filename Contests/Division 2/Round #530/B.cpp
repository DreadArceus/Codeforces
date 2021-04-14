#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int root = sqrt(n);
    long rowNum = root, columnNum = root;
    while(n > rowNum * columnNum)
    {
        rowNum++;
        if(n > rowNum * columnNum)
            columnNum++;
    }
    cout << rowNum + columnNum;
}