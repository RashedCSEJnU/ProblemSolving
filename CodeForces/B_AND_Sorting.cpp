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
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;
        vector<int> arr = v;
        sort(arr.begin(), arr.end());
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != v[i])
                ans &= v[i];
        }
        cout << ans << '\n';
    }
    return 0;
}