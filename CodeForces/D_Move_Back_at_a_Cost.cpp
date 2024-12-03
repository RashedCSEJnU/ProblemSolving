#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), ans;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        multiset<int> s;
        for (int i = 0; i < n; i++)
            s.insert(a[i]);

        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            s.erase(s.find(a[i]));
            if (!s.empty())
            {
                if (*s.begin() < a[i] || mini < a[i])
                {
                    mini = min(a[i] + 1, mini);
                    ans.push_back(a[i] + 1);
                }
                else
                    ans.push_back(a[i]);
            }
            else
            {
                if (mini < a[i])
                {
                    mini = min(a[i], mini);
                    ans.push_back(a[i] + 1);
                }
                else
                    ans.push_back(a[i]);
            }
        }
        sort(ans.begin(), ans.end());
        for (auto x : ans)
            cout << x << ' ';
        cout << '\n';
    }
    return 0;
}