#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        bool flag = (y == x + 1 || (x - y) % 9 == 8);
        cout << (flag ? "Yes" : "No") << endl;
    }
    return 0;
}