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
        int n, ans = 1;
        string s;
        cin >> n >> s;
        int up = 0, down = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '-')
                up++;
            else
                down++;
        }
        // cout << up << ' ' << down << '\n';
        if (up >= 2 && down > 0)
        {
            int half = up / 2;
            int rem = up - half;
            ans = half * rem * down;
        }
        else
            ans = 0;
        cout << ans << '\n';
    }
    return 0;
}