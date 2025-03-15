#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n, n);
        if (k & 1)
            a.back() = n - 1;
        else
        {
            for (int i = 0; i < n; i++)
                a[i] = n - 1;
            a[n - 2] = n;
        }

        for (auto val : a)
            cout << val << ' ';
        cout << '\n';
    }
    return 0;
}