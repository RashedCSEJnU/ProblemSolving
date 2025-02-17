#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, res = INT_MAX;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            res &= x;
        }
        cout << res << '\n';
    }
    return 0;
}