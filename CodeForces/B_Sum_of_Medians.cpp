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
        int n, k;
        cin >> n >> k;
        vector<int> v(n * k);
        for (int &i : v)
            cin >> i;

        int mid = n / 2, sum = 0, total = n * k;
        for (int i = 0, j = total - mid - 1; i < k; i++, j -= (mid + 1))
        {
            sum += v[j];
        }
        cout << sum << '\n';
    }
    return 0;
}