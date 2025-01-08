#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());

        map<int, int> freq;
        for (int i = 0; i < n; i++)
            freq[a[i]]++;
        vector<pair<int, int>> vp;
        for (auto i : freq)
            vp.push_back({i.second, i.first});
        sort(vp.begin(), vp.end());

        int cnt = 0;
        for (int i = 0; i < vp.size(); i++)
        {
            if (k < vp[i].first)
                break;
            else
            {
                k -= vp[i].first;
                cnt++;
            }
        }
        int ans = max((int)vp.size() - cnt, 1);
        cout << ans << '\n';
    }
    return 0;
}