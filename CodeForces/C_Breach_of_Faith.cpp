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
        int n, ans = -1;
        cin >> n;
        n *= 2;
        vector<int> a(n), soto, boro;
        for (auto &i : a)
            cin >> i;
        sort(a.begin(), a.end());
        for (int i = 1; i < n / 2; i++)
            soto.push_back(a[i]);
        for (int i = n / 2; i < n; i++)
            boro.push_back(a[i]);
        boro.push_back(a[0]);
        int sum = accumulate(boro.begin(), boro.end(), 0LL) - accumulate(soto.begin(), soto.end(), 0LL);
        soto.push_back(sum);
        while (soto.size() && boro.size())
        {
            cout << boro.back() << ' ' << soto.back() << ' ';
            boro.pop_back(), soto.pop_back();
        }
        cout << boro[0] << '\n';
    }
    return 0;
}
