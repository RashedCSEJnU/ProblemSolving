#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int r, c, k;
    cin >> r >> c >> k;
    map<int, int> mp;
    for (int i = 0; i < c; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    vector<int> v;
    for (auto x : mp)
        v.push_back(x.second);

    sort(v.rbegin(), v.rend());
    int ans = 0;
    for (int i = 0; i < v.size() && i < k; i++)
        ans += v[i];
    cout << ans << '\n';

    return 0;
}