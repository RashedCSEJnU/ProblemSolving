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
        int n, pre = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int val = i + pre++;
            cout << val << " ";
        }
        cout << '\n';
    }
    return 0;
}