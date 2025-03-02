#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, p;
        cin >> n >> p;
        vector<pair<int, int>> vp(n);
        for (int i = 0; i < n; i++)
            cin >> vp[i].second;
        for (int i = 0; i < n; i++)
            cin >> vp[i].first;
        sort(vp.begin(), vp.end());

        long long ans = n * p, total = p, rem = n - 1;
        for (int i = 0; i < n; i++)
        {
            long long cost = vp[i].first, power = vp[i].second;
            if (cost < p)
            {
                long long mini = min(power, rem);
                rem -= mini;
                total += (mini * cost);
            }
            else
            {
                total += (p * rem);
                break;
            }
        }
        cout << min(ans, total) << '\n';
    }
    return 0;
}