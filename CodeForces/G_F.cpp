#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, i;
    cin >> n;
    vector<int> v(n), dp(n, 1);
    for (auto &i : v)
        cin >> i;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }

    for (int i = 1; i < n; i++)
    {
    }

    return 0;
}