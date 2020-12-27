#include <iostream>
#include <vector>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define pii pair<int, int>

int main()
{
    int n = 0, t = 0;
    cin >> n >> t;
    vector<int> v(n);
    ordered_set<pii> oset;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        pii x = {v[i], i};
        oset.insert(x);
    }
    while(t--)
    {
        int k = 0, x = 0;
        cin >> k;
        auto it = oset.find_by_order(k - 1);
        cout << it->first << "\n";
        oset.erase(it);
    }
}