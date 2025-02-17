#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, cnt = 0;
        string s;
        cin >> n >> s;

        for (int i = 1; i < n; i++)
        {
            if (s[i - 1] != s[i])
                cnt++;
        }
        if (s[0] == '1')
            cout << cnt + 1 << '\n';
        else
            cout << cnt << '\n';
    }
    return 0;
}