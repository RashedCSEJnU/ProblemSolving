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
        int cnt = 0, i = 0, n = s.length(), flag = s.back() == '0';
        while (s.length() && s.back() == '0')
            s.pop_back(), cnt++;
        for (; i < s.length() - 1; i++)
        {
            if (s[i] != '0')
                cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}