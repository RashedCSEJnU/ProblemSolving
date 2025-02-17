#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> vp(n);
    for (auto &i : vp)
        cin >> i.first >> i.second;

    sort(vp.begin(), vp.end());
    int val = abs(vp.back().first - vp[0].first) + abs(vp.back().second - vp[0].second);
    int dis = (val + 1) / 2;
    cout << dis << '\n';
    return 0;
}