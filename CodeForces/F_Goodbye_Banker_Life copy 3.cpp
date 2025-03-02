#include <bits/stdc++.h>
using namespace std;
#define int long long
int power(int n)
{
    int ans = 0;
    while (n)
    {
        ans += (n / 2);
        n /= 2;
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        n--;
        for (int i = 0; i <= n; i++)
        {
            int val = power(n) - power(n - i) - power(i);
            cout << (val ? 0 : k) << ' ';
        }
        cout << '\n';
    }
    return 0;
}