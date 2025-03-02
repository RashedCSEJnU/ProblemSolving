#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, ans = 0, last = 0;
        char ch;
        string s;
        cin >> n >> ch >> s;
        s = s + s;
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            if (s[i] == 'g')
                last = i;
            if (s[i] == ch)
                ans = max(ans, last - i);
        }
        cout << ans << '\n';
    }
    return 0;
}