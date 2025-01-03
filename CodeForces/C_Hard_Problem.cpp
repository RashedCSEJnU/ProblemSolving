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
        int m, a, b, c;
        cin >> m >> a >> b >> c;
        int ans = 0;
        int fst = m, snd = m;
        int mini = min(fst, a);
        ans = mini;
        fst -= mini;
        mini = min(snd, b);
        snd -= mini;
        ans += mini;
        mini = min(fst, c);
        ans += mini;
        c -= mini;
        mini = min(snd, c);
        ans += mini;
        c -= mini;
        cout << ans << '\n';
    }
    return 0;
}