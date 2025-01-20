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
        int n, k, ans = 0;
        cin >> n >> k;
        vector<int> ar(n);
        for (int &i : ar)
            cin >> i;
        sort(all(ar));
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int need = k - ar[i];
            if (mp[need] > 0)
            {
                ans++;
                mp[need]--;
            }
            else
                mp[ar[i]]++;
        }
        cout << ans << '\n';
    }
    return 0;
}