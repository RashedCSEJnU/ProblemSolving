#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s);
        int n = s.size();
        bool flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ' ')
            {
                flag = 0;
            }
            else if (flag == 0)
            {
                cout << s[i];
                flag = 1;
            }
        }
        cout << '\n';
    }
    return 0;
}