#include <algorithm> 
#include <chrono> 
#include <iostream>
#include <cstdio> 
#include <unordered_map>
#include <set>
using namespace std; 
using namespace std::chrono;

#define ll long long

int main() 
{
    // Get starting timepoint 
    auto start = high_resolution_clock::now(); 
    int n = 0, x = 0, q = 0;
    std::scanf("%d %d", &n, &x);
    int v[n];
    for(int i = 0; i < n; i++)
    {
        std::scanf("%d", &v[i]);
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
    int temp = 0;
    unordered_map<ll, ll> *hashMap = new unordered_map<ll, ll>;
    for(auto it: sums)
    {
        while(it >= temp)
        {
            hashMap->insert({temp++, it});
        }
    }
    std::scanf("%d", &q);
    while(q--)
    {
        ll d = 0;
        std::scanf("%lld", &d);
        if(d > sum)
        {
            printf("-1\n");
            continue;
        }
        printf("%lld\n", hashMap->at(d));
    }
    // Get ending timepoint 
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 
  
    return 0; 
} 
