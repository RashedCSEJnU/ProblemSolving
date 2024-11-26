#include <bits/stdc++.h>
using namespace std;

void add(int i, string &s, set<int> &block)
{
    int n = s.length();

    if (i == 0 && s[i] == 'L')
        block.insert(i);

    if (i > 0 && s[i] == 'L' && s[i + 1] == 'R')
    {
        block.insert(i);
        block.insert(i + 1);
    }
}

void remove(int i, string &s, set<int> &block)
{
    int n = s.length();

    if (i == 0 && s[i] == 'L')
        block.erase(i);

    if (i > 0 && s[i] == 'L' && s[i + 1] == 'R')
    {
        block.erase(i);
        block.erase(i + 1);
    }
    if (i > 0 && s[i] == 'R' && s[i - 1] == 'L')
    {
        block.erase(i);
        block.erase(i - 1);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> v(n), preMax(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            preMax[i] = v[i];
            if (i > 0)
                preMax[i] = max(preMax[i], preMax[i - 1]);
        }
        string s;
        cin >> s;
        // LR is the block
        set<int> block;
        for (int i = 0; i < n; i++)
        {
            if (preMax[i] > i + 1)
                add(i, s, block);
        }

        // for (auto val : v)
        //     cout << val << ' ';
        // cout << '\n';
        // for (auto val : preMax)
        //     cout << val << ' ';
        // cout << '\n';
        // cout << s << '\n';
        // for (auto val : block)
        //     cout << val << ' ';
        // cout << '\n';

        while (q--)
        {
            int i;
            cin >> i;
            --i;
            remove(i, s, block);
            s[i] = (s[i] == 'R' ? 'L' : 'R');
            add(i, s, block);

            cout << (block.size() ? "NO\n" : "YES\n");
        }

        cout << '\n';
    }
    return 0;
}