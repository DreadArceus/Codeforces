#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;
#define ll long long

int main()
{
    int n = 0, x = 0, q = 0;
    scanf("%d %d", &n, &x);
    int v[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    
    ll sum = 0;
    for(int i = 0; i < x - 1; i++)
    {
        sum += v[i];
    }
    set<ll> sums;
    for(int i = x - 1; i < n; i++)
    {
        sum += v[i] - ((i == x - 1) ? 0 : v[i - x]);
        sums.insert(sum);
    }
    scanf("%d", &q);
    while(q--)
    {
        ll d = 0;
        scanf("%lld", &d);
        auto ans = lower_bound(sums.begin(), sums.end(), d);
        if(ans == sums.end())
        {
            printf("-1\n");
            continue;
        }
        printf("%lld\n", *ans);
    }
}