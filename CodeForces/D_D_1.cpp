#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v(n), arr;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    arr = v;
    sort(all(arr));

    for (int i = 0; i < n; i++)
    {
        int l = v[i] - a;
        int ll = v[i] - b;
        int u = v[i] + a;
        int uu = v[i] + b;

        int cntA = upper_bound(all(arr), ll) - lower_bound(all(arr), l);
        int cntB = lower_bound(all(arr), uu) - upper_bound(all(arr), u);
        cout << cntB << ' ' << cntA << '\n';
        cout << endl;
    }

    return 0;
}