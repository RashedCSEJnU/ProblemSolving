#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cout << "Case " << tc << ": ";
        int p, s, r;
        cin >> p >> s >> r;

        if (s == p && r != 1)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
}
