#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m, ans = 0, len = 0;
        cin >> n >> m;
        bool flag = 1;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            if (flag && len + s.size() <= m)
            {
                ans++;
                len += s.size();
            }
            else
                flag = 0;
        }
        cout << ans << '\n';
    }
    return 0;
}