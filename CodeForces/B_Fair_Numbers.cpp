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

        int tmp = n;
        while (tmp != 0)
        {
            int rem = tmp % 10;
            tmp /= 10;
            if (rem > 1 && n % rem != 0)
            {
                n++;
                tmp = n;
            }
        }
        cout << n << '\n';
    }
    return 0;
}