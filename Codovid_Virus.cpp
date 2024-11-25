#include <bits/stdc++.h>
using namespace std;

string rev(string s)
{
    string tmp(s.rbegin(), s.rend());
    return tmp;
}

string flip(string s)
{
    string tmp = s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
            tmp[i] = '1';
        else
            tmp[i] = '0';
    }
    return tmp;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        string pre, cur, total;
        cin >> pre;
        total = pre;
        cout << total << '\n';
        for (int i = 0; i < 3; i++)
        {
            cur = rev(pre) + flip(pre) + rev(pre);
            total += cur;
            pre = cur;
        }
        for (int i = 0; i < total.length(); i++)
        {
            if (total[i] == '1')
                cout << i + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}