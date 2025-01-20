#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;

        bool flag = true;
        for (int i = 0; i < n - 1; i++)
        {
            int mini = min(v[i], v[i + 1]);
            v[i] -= mini;
            v[i + 1] -= mini;
            if (v[i] > v[i + 1])
            {
                flag = false;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}