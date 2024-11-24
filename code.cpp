#include <bits/stdc++.h>
using namespace std;
#define int long long

// printbinary number
void printBinary(int n)
{
    if (n == 0)
    {
        return;
    }
    printBinary(n / 2);
    cout << n % 2;
}

bool isDivisor(int a, int b)
{
    return b % a == 0;
}

int countValidY(int x, int m)
{
    int count = 0;
    cout << "x: " << x << " m: " << m << endl;
    for (int y = 1; y <= 2 * x; ++y)
    {
        if (x != y)
        {
            int xorValue = x ^ y;
            if (isDivisor(xorValue, y) || isDivisor(xorValue, x))
            {

                cout << xorValue << ' ' << y << endl;

                cout << x << ": ";
                printBinary(x);
                cout << endl;
                cout << y << ": ";
                printBinary(y);
                cout << endl;
                cout << xorValue << ": ";
                printBinary(xorValue);
                cout << endl;
                cout << endl;

                count++;
            }
        }
    }
    return count;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int x, m;
        cin >> x >> m;
        cout << countValidY(x, m) << '\n';
    }

    return 0;
}
