#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int h, w, k, fst, lst, ans = 0;
        cin >> w >> h;
        for (int i = 0; i < 4; i++)
        {
            cin >> k;
            for (int j = 0; j < k; j++)
            {
                int x;
                cin >> x;
                if (!j)
                    fst = x;
                lst = x;
            }
            int y = (i <= 1 ? h : w);
            int val = (lst - fst) * y;
            ans = max(ans, val);
        }
        cout << ans << '\n';
    }
    return 0;
}