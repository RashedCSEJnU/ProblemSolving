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
        vector<int> a(n), b(n);
        for (auto &i : a)
            cin >> i;
        for (auto &i : b)
            cin >> i;
        b.push_back(0);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > b[i + 1])
                sum += a[i] - b[i + 1];
        }
        cout << sum << '\n';
    }

    return 0;
}