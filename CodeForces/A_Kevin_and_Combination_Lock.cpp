#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;

        while (x >= 33)
        {
            string s = to_string(x);
            if (s.find("33") != -1)
            {
                s.erase(s.find("33"), 2);
                x = stoll(s.empty() ? "0" : s);
            }
            else
                x -= 33;
        }
        cout << (x == 0 ? "YES" : "NO") << '\n';
    }
    return 0;
}