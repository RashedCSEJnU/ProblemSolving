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
        int n, k;
        cin >> n >> k;

        vector<int> v(n);
        for (auto &i : v)
            cin >> i;
        int sum = accumulate(v.begin(), v.end(), 0LL);
        cout << (!(sum % (k * n)) ? "YES\n" : "NO\n");
    }
    return 0;
}