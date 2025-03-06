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
        int n;
        cin >> n;
        n--;
        int lg = __lg(n);
        int val = round(pow(2, lg));
        // cout << n << ' ' << val << endl;
        for (int i = n; i > val; i--)
            cout << i << ' ';
        for (int i = 1; i < val; i++)
            cout << i << ' ';
        cout << 0 << ' ' << val << '\n';
    }
    return 0;
}