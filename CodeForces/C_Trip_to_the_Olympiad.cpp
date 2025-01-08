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
        int l, r, LOG = 30;
        cin >> l >> r;
        int x = l ^ r;
        int pos = 0;
        for (int i = 0; i < LOG; i++)
        {
            if (x & (1 << i))
            {
                pos = i;
            }
        }
        int cur = ((r >> pos) << pos);
        int t = r;
        if (t == cur)
        {
            t = l;
        }
        cout << cur << " " << cur - 1 << " " << t << endl;
    }
    return 0;
}