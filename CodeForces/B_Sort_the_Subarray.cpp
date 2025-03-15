#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, l = -1, r = -1;
        cin >> n;
        vector<int> a(n), b(n);
        for (auto &i : a)
            cin >> i;
        for (auto &i : b)
            cin >> i;

        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                r = i;
                if (l == -1)
                    l = i;
            }
        }
        while (l - 1 >= 0 && b[l - 1] <= b[l])
            l--;
        while (r + 1 < n && b[r + 1] >= b[r])
            r++;
        cout << l + 1 << ' ' << r + 1 << '\n';
    }
    return 0;
}