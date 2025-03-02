#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int x = n;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                x = i;
                break;
            }
        }
        cout << n / x << ' ' << n - (n / x) << '\n';
    }
    return 0;
}