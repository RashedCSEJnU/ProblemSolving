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
        string s;
        cin >> n >> s;

        if (s.find("ps") != -1)
        {
            cout << "NO\n";
            continue;
        }
        if (s.find("s") == -1 && s.find("p") == -1)
        {
            cout << "YES\n";
            continue;
        }
        bool flag = 1;
        vector<int> pre(n), suf(n);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'p')
                pre[i] = i;
            if (s[i] == 's')
                suf[i] = n - i - 1;
        }
        for (int i = 1; i < n; i++)
            pre[i] = max(pre[i], pre[i - 1]);
        for (int i = n - 2; i >= 0; i--)
            suf[i] = max(suf[i], suf[i + 1]);

        for (auto val : pre)
            cout << val << ' ';
        cout << '\n';
        for (auto val : suf)
            cout << val << ' ';
        cout << '\n';

        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}