#include <bits/stdc++.h>
using namespace std;
#define int long long

bool check(int x, int y)
{
    int xy = x ^ y;
    vector<int> v{x, y, xy};
    sort(v.begin(), v.end());
    return (v[0] + v[1] > v[2]);
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int y;
        cin >> y;

        int ans = -1, x = 1;

        while (2 * x < y)
            x *= 2;
        if (check(x - 1, y))
            ans = x - 1;
        cout << ans << '\n';
    }
    return 0;
}