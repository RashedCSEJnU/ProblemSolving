#include <bits/stdc++.h>
using namespace std;

int func(vector<int> &ar)
{
    int ans = 0;
    for (int i = 0; i <= 2; i++)
    {
        if (ar[i + 2] == ar[i] + ar[i + 1])
            ans++;
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        vector<int> ar(4);
        cin >> ar[0] >> ar[1] >> ar[3] >> ar[4];

        int x = ar[0] + ar[1];
        int y = ar[3] - ar[1];

        int ans = 0;
        ar[2] = x;
        ans = func(ar);
        ar[2] = y;
        ans = max(ans, func(ar));
        cout << ans << '\n';
    }
    return 0;
}