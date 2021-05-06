#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define int long long
#define pii pair<int, int>
int32_t mod = 1e9 + 7;

int n, m, x, k, l, r;
bool f1, f2, f3;
string s, s1, s2;
vector<int> v, v1, v2;
set<int> se, se1, se2;
map<int, int> mp1, mp2;
void initiateCase()
{
    n = m = x = k = l = r = 0;
    f1 = f2 = f3 = false;
    s = s1 = s2 = string();
    v = v1 = v2 = vector<int>();
    se = se1 = se2 = set<int>();
    mp1 = mp2 = map<int, int>();
}

void solveCase()
{
    initiateCase();
    int t = 0;
    cin >> n >> t >> k;
    l = 1;
    r = n;
    int oldR = r;
    int residue = 0;
    while (r != l)
    {
        cout << "? " << l << " " << r << endl;
        cin >> x;
        if (x == -1)
            exit(0);
        int zeroCount = r - l + 1 - x + residue;
        if (zeroCount < k)
        {
            l = r + 1;
            r = oldR;
            residue = zeroCount;
            r = (r + l) / 2;
        }
        else
        {
            oldR = r;
            r = (r + l) / 2;
        }
    }
    cout << "? " << l << " " << r << endl;
    cin >> x;
    if (x == -1)
        exit(0);
    int zeroCount = r - l + 1 - x + residue;
    if (zeroCount != k)
        l++;
    cout << "! " << l << endl;
    cout << "\n";
}

int32_t main()
{
    solveCase();
}