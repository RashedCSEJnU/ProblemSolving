#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, x, y, count = 0, total = 0;
        cin >> n >> x >> y;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            total += a[i];
        }
        sort(all(a));
        for (int i = 0; i < n - 1; i++)
        {
            int findX = total - a[i] - x;
            int findY = total - a[i] - y;
            auto low = upper_bound(a.begin() + i + 1, a.end(), findX);
            auto high = lower_bound(a.begin() + i + 1, a.end(), findY);
            count += abs(high - low);
        }
        cout << count << endl;
    }
    return 0;
}