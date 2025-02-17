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
    while (t--)
    {
        vector<int> valid = {25, 50, 75, 100, 200, 300};
        int n;
        cin >> n;

        vector<int> rem;
        while (n != 0)
        {
            rem.push_back(n % 10);
            n /= 10;
        }
        reverse(rem.begin(), rem.end());
        // for (auto val : rem)
        //     cout << val << ' ';
        // cout << '\n';
        int sz = rem.size(), ans = INT_MAX;
        for (int i = 0; i < sz - 1; i++)
        {
            for (int j = i + 1; j < sz; j++)
            {
                if (rem[i] == 2 && rem[j] == 5)
                {
                    int dif = (sz - j - 1) + (j - i - 1);
                    ans = min(ans, dif);
                }
                if (rem[i] == 5 && rem[j] == 0)
                {
                    int dif = (sz - j - 1) + (j - i - 1);
                    ans = min(ans, dif);
                }
                if (rem[i] == 7 && rem[j] == 5)
                {
                    int dif = (sz - j - 1) + (j - i - 1);
                    ans = min(ans, dif);
                }
                if (rem[i] == 0 && rem[j] == 0)
                {
                    int dif = (sz - j - 1) + (j - i - 1);
                    ans = min(ans, dif);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}