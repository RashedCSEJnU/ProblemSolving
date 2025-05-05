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
        string p, s;
        cin >> p >> s;

        bool flag = true;
        int i = 0, j = 0, n = p.size(), m = s.size();

        while (i < n && j < m)
        {
            if (p[i] != s[j])
            {
                flag = false;
                break;
            }

            int ii = i, jj = j, cntp = 0, cnts = 0;
            while (ii < n && p[ii] == p[i])
                ii++, cntp++;
            while (jj < m && s[jj] == s[j])
                jj++, cnts++;

            if (cnts < cntp || cnts > 2 * cntp)
            {
                flag = false;
                break;
            }

            i = ii, j = jj;
        }

        if (i != n || j != m)
            flag = false;

        cout << (flag ? "YES\n" : "NO\n");
    }

    return 0;
}
