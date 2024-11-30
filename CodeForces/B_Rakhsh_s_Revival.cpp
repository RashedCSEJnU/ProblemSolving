#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;

        int ans = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                sum++;
                if (sum == m)
                {
                    for (int j = i; j < min(i + k, n); j++)
                    {
                        s[j] = '1';
                    }
                    ans++;
                    sum = 0;
                }
            }
            else
                sum = 0;
        }

        cout << ans << '\n';
    }

    return 0;
}
