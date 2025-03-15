#include <bits/stdc++.h>
using namespace std;
#define int long long
void areaCal(int cnt, int &ans)
{
    int x = (cnt + 1) / 2;
    int y = cnt - x + 1;
    int area = x * y;
    ans = max(ans, area);
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        int cnt = count(s.begin(), s.end(), '1');
        if (cnt == 0 || cnt == s.length())
        {
            cout << cnt * cnt << '\n';
            continue;
        }

        s += s;
        int ans = 0, n = s.length();
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                cnt++;
            else
            {
                areaCal(cnt, ans);
                cnt = 0;
            }
        }
        areaCal(cnt, ans);
        cout << ans << '\n';
    }
    return 0;
}