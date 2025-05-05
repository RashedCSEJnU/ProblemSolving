#include <bits/stdc++.h>
using namespace std;
#define int long long
#define CheckBit(x, k) (x & (1LL << k))
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n), zero(31, 0), one(31, 0);
        for (auto &i : v)
            cin >> i;

        for (int i = 0; i < n; i++)
        {
            for (int b = 0; b <= 30; b++)
            {
                if (CheckBit(v[i], b))
                    one[b]++;
                else
                    zero[b]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int b = 0; b <= 30; b++)
            {
                if (CheckBit(v[i], b)) // set hole O biter gula plus
                    sum += zero[b] * (1LL << b);
                else // unset hole 1 biter gula plus
                    sum += one[b] * (1LL << b);
            }
            ans = max(ans, sum);
        }
        cout << ans << '\n';
    }
    return 0;
}