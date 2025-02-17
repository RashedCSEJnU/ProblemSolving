#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        int cnt = 0, zero = 0, one = 0, n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0' && one > 0)
            {
                cnt++;
                one--;
            }
            else if (s[i] == '1' && zero > 0)
            {
                cnt++;
                zero--;
            }
            else
            {
                if (s[i] == '0')
                    zero++;
                else
                    one++;
            }
        }
        // cout << cnt << '\n';
        cout << (cnt & 1 ? "DA\n" : "NET\n");
    }
    return 0;
}