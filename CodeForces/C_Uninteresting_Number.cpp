#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        vector<int> v;
        int n = s.length(), sum = 0;
        for (int i = 0; i < n; i++)
        {
            int x = s[i] - '0';
            sum = (sum + x) % 9;
            if (x == 2 || x == 3)
                v.push_back(x);
        }
        bool flag = false;
        int two = count(v.begin(), v.end(), 2);
        int three = count(v.begin(), v.end(), 3);

        for (int i = 0; i <= min(10LL, two); i++)
        {
            for (int j = 0; j <= min(10LL, three); j++)
            {
                if ((sum + (i * 2) + (j * 6)) % 9 == 0)
                    flag = true;
            }
        }

        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}