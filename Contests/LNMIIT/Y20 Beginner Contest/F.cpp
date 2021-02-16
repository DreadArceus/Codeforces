#include <cstdio>
#include <vector>
using namespace std;

#define pii pair<int, int>

int main()
{
    int t = 0;
    scanf("%d", &t);
    while(t--)
    {
        int n = 0, m = 0, count = 0;
        scanf("%d %d", &n, &m);
        pii columns[m];
        bool inc = false;
        for(int i = 0; i < n; i++)
        {
            pii row = make_pair(0, 0);
            for(int j = 0; j < m; j++)
            {
                int x = 0;
                scanf("%d", &x);
                count += x;
                if(!inc)
                {
                    if(x)
                    {
                        row.first++;
                        columns[j].first++;
                    }
                    else
                    {
                        row.second = 1;
                        columns[j].second = 1;
                    }
                }
            }
            if(!inc && row.second && row.first % 2)
            {
                inc = true;
            }
        }
        if(!inc)
        {
            for(int i = 0; i < m; i++)
            {
                if(columns[i].second && columns[i].first % 2)
                {
                    inc = true;
                    break;
                }
            }            
        }
        printf("%d\n", count + inc);
    }
}