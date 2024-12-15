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
        int n = s.length();
        bool flag = true;
        while (flag)
        {
            flag = false;
            for (int i = 1; i < n; i++)
            {
                if (s[i - 1] < s[i] - 1)
                {
                    char tmp = s[i - 1];
                    s[i - 1] = s[i] - 1;
                    s[i] = tmp;
                    flag = true;
                }
            }
        }
        cout << s << '\n';
    }
    return 0;
}