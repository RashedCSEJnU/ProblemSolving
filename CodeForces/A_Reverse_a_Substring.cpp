#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    cin >> n >> s;
    map<char, int> mp;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if (mp.find(ch) == mp.end())
            mp[ch] = i;
        for (auto [c, ind] : mp)
        {
            if (c > ch && ind < i)
            {
                cout << "YES\n";
                cout << ind + 1 << ' ' << i + 1 << '\n';
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }
    if (!flag)
        cout << "NO\n";

    return 0;
}