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
        int x, n;
        cin >> x >> n;
        int rem = n % 4;
        for (int i = n - rem + 1; i <= n; i++)
        {
            if (x & 1)
                x += i;
            else
                x -= i;
        }
        cout << x << endl;
    }
    return 0;
}