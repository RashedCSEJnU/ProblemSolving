#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    map<char, char> mp;
    mp['p'] = 'q';
    mp['q'] = 'p';
    mp['w'] = 'w';
    while (t--)
    {
        string s;
        cin >> s;
        while (s.size())
        {
            cout << mp[s.back()];
            s.pop_back();
        }
        cout << '\n';
    }
    return 0;
}