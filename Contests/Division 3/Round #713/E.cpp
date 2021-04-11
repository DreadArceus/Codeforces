#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n = 0, l = 0, r = 0, s = 0;
        cin >> n >> l >> r >> s;

        int size = r - l + 1;
        int baseSum = (size * (size + 1)) / 2;
        if (baseSum > s)
        {
            cout << "-1\n";
            continue;
        }

        set<int> ans;
        for (int i = 1; i <= size; i++)
            ans.insert(i);
        int maxElement = n;

        while (baseSum < s)
        {
            int dif = s - baseSum;
            set<int>::iterator minIt = min_element(ans.begin(), ans.end());
            int minElement = *minIt;
            if (dif < maxElement - minElement)
                break;
            baseSum += maxElement - minElement;
            ans.erase(minIt);
            ans.insert(maxElement);
            maxElement--;
            if (maxElement <= size)
                break;
        }

        int dif = s - baseSum;
        maxElement = n;
        while (ans.find(maxElement) != ans.end())
            maxElement--;
        while (maxElement > size)
        {
            set<int>::iterator it = ans.find(maxElement - dif);
            if (it != ans.end())
            {
                baseSum += maxElement - *it;
                ans.erase(it);
                ans.insert(maxElement);
                break;
            }
            maxElement--;
        }

        if (baseSum != s)
        {
            cout << "-1\n";
            continue;
        }

        int x = 1;
        for (int i = 0; i < l - 1; i++)
        {
            while (ans.find(x) != ans.end())
                x++;
            cout << x++ << " ";
        }
        set<int>::iterator it = ans.begin();
        while (it != ans.end())
            cout << *it++ << " ";
        for (int i = r; i < n; i++)
        {
            while (ans.find(x) != ans.end())
                x++;
            cout << x++ << " ";
        }
        cout << "\n";
    }
}