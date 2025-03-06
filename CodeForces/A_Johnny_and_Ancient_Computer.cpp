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
        int a, b, ans = 0;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        while (a < b)
        {
            if (a * 8 <= b)
                a *= 8;
            else if (a * 4 <= b)
                a *= 4;
            else if (a * 2 <= b)
                a *= 2;
            else
                break;
            ans++;
        }
        if (a != b)
            ans = -1;
        cout << ans << '\n';
    }
    return 0;
}