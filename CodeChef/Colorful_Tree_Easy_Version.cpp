#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, ans = 0;
        cin >> n;
        vector<int> freq(n);
        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            freq[x - 1]++, freq[y - 1]++;
        }
        for (int i = 0; i < n; i++)
            ans += (freq[i] == 1 ? 3 : 2);
        cout << ans << '\n';
    }
    return 0;
}