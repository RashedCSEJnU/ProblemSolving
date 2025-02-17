#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n), mp(n + 2);
        for (int &x : a)
        {
            cin >> x;
            mp[x]++;
        }

        int left = -1, right = -1;
        for (int i = 0; i < n; i++)
        {
            int j = i;
            while (j < n && mp[a[j]] == 1)
                j++;

            if (j - i > right - left)
            {
                left = i;
                right = j - 1;
            }
            i = j;
        }
        if (left == -1)
            cout << 0 << '\n';
        else
            cout << left + 1 << ' ' << right + 1 << '\n';
    }
    return 0;
}