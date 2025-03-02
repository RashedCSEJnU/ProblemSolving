#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        n -= 2;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;
        bool flag = false;
        for (int i = 0; i < n - 2; i++)
        {
            if (v[i] == 1 && v[i + 1] == 0 && v[i + 2] == 1)
                flag = true;
        }
        cout << (!flag ? "YES\n" : "NO\n");
    }
    return 0;
}