#include "testlib.h"
#include <iostream>
#include <vector>

using namespace std;

struct Edge
{
    int u, v, w;
};

vector<Edge> edges;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    int n = 1000;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            edges.push_back({i, j, rnd.next(1, 1000)});
        }
    }
    cout << n << " " << edges.size() << endl;
    for (auto e : edges)
        cout << e.u << " " << e.v << " " << e.w << endl;
}
