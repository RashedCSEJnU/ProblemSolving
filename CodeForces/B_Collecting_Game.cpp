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
        vector<int> v(n), ans(n);
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            arr[i] = {v[i], i};
        }
        sort(arr.begin(), arr.end());
        for (int i = 0, j = 0, c = 0; i < n; i++)
        {
            int fst = arr[i].first, ind = arr[i].second;
            while (j < n && arr[j].first <= fst)
            {
                c += arr[j].first;
                j++;
            }
            while (j < n && arr[j].first <= c)
            {
                c += arr[j].first;
                j++;
            }
            ans[ind] = j - 1;
        }
        for (auto val : ans)
            cout << val << ' ';
        cout << '\n';
    }
    return 0;
}