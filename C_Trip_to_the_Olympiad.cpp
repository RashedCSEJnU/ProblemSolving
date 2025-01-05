#include <bits/stdc++.h>
using namespace std;
#define int long long

// Sets the k-th bit of x (0-indexed)
#define SetBit(x, k) (x |= (1LL << k))
// Clears the k-th bit of x (0-indexed)
#define ClearBit(x, k) (x &= ~(1LL << k))
// Checks if the k-th bit of x is set (returns non-zero if true, 0 if false)
#define CheckBit(x, k) (x & (1LL << k))

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;

        if (r - l <= 100)
        {
            int a = r, b, c, maxi = 0;
            for (int i = l; i < r; i++)
            {
                for (int j = i + 1; j <= r; j++)
                {
                    int x = i ^ j;
                    if (x > maxi)
                    {
                        maxi = x;
                        b = i, c = j;
                    }
                }
            }
            cout << a << " " << b << " " << c << endl;
        }
        else
        {
            int bestA = r, bestB = 0, bestC = 0;
            int sz = __lg(r);
            for (int i = 0; i < sz; i++)
            {
                if (CheckBit(r, i))
                    continue;
                SetBit(bestB, i);
            }
            cout << bestA << " " << bestB << " " << bestC << endl;
        }
    }
    return 0;
}
