#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, t;
        cin >> s >> t;
        int n = s.length(), m = t.length();
        int ans = n + m;
        for (int i = 0; i < n; i++)
        {
            string tmp;
            for (int j = i; j < n; j++)
            {
                tmp += s[j];
                if (t.find(tmp) != -1)
                    ans = min(ans, n + m - 2 * (j - i + 1));
            }
        }
        cout << ans << '\n';
    }
    return 0;
}