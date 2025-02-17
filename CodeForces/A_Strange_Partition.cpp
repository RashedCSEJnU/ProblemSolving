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
        int mini = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            mini += ((x + k - 1) / k);
            sum += x;
        }
        int maxi = (sum + k - 1) / k;
        cout << min(mini, maxi) << " " << max(mini, maxi) << '\n';
    }
    return 0;
}