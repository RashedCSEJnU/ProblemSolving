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
        int n, m, sum = 0, neg = 0, zero = 0;
        cin >> n >> m;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int x;
                cin >> x;
                v.push_back(abs(x));
                if (x < 0)
                    neg++;
                if (x == 0)
                    zero++;
            }
        }
        sort(v.begin(), v.end());
        neg %= 2;
        if (!neg && zero > 0)
            neg = 0;
        for (int i = v.size() - 1; i >= neg; i--)
            sum += v[i];
        for (int i = neg - 1; i >= 0; i--)
            sum -= v[i];

        cout << sum << '\n';
    }
    return 0;
}