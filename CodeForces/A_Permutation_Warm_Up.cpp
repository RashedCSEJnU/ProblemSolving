#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;

    int N = 501;
    vector<int> dp(N, 0);
    dp[1] = 1, dp[2] = 2, dp[3] = 3, dp[4] = 5;

    int cnt = 2, f = 0, pre = 1;

    for (int i = 5; i < N; i++)
    {
        dp[i] = i + cnt + pre;
        f++;
        pre += cnt;
        if (f == 2)
        {
            cnt++;
            f = 0;
        }
    }
    while (t--)
    {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}