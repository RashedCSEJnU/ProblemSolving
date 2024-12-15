#include <bits/stdc++.h>
using namespace std;

#define Sezar ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define int long long
#define vi vector<int>

bool check(const vi &v, int sec)
{
    int n = v.size();
    int idx1 = upper_bound(v.begin(), v.end(), sec + 1) - v.begin();
    int idx2 = lower_bound(v.begin(), v.end(), 1e6 - sec) - v.begin();
    return (idx1 + (n - idx2)) >= n;
}

void solution()
{
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());

    int lo = 0, hi = 1e6;
    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (check(v, mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << lo << "\n";
}

int32_t main()
{
    Sezar;
    solution();
}
