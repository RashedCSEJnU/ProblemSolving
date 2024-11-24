#include <bits/stdc++.h>
using namespace std;
#define int long long

void printBinary(int n)
{
    string s;
    while (n)
    {
        s += to_string(n % 2);
        n /= 2;
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int x, m;
        cin >> x >> m;

        int count = 0;
        for (int y = 1; y <= m; y++)
        {

            int xorValue = x ^ y;

            if (xorValue % y == 0 || xorValue % x == 0)
            {
                if (xorValue % y == 0)
                    cout << "y: ";
                else
                    cout << "x: ";

                cout << x << ' ' << y << ' ' << xorValue << endl;

                // if (xorValue % x == 0 && xorValue % y != 0)
                // {
                //     printBinary(x);
                //     printBinary(y);
                //     printBinary(xorValue);
                //     cout << '\n';
                // }
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}