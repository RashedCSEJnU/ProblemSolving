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
        int a, b, c;
        cin >> a >> b >> c;
        int x = a ^ b;
        int y = b ^ c;
        int z = a ^ c;
        cout << x + y + z << endl;
    }
    return 0;
}