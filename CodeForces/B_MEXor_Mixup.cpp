#include <bits/stdc++.h>
using namespace std;
int calCulateXor(int n)
{
    // If n is a multiple of 4
    if (n % 4 == 0)
        return n;
    // If n%4 gives remainder 1
    if (n % 4 == 1)
        return 1;
    // If n%4 gives remainder 2
    if (n % 4 == 2)
        return n + 1;
    // If n%4 gives remainder 3
    return 0;
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int a, b, val = 0;
        cin >> a >> b;
        val = calCulateXor(a - 1);

        if (val == b)
            cout << a << '\n';
        else if (val != b && (val ^ b) != a)
            cout << a + 1 << '\n';
        else if (val != b && (val ^ b) == a)
            cout << a + 2 << '\n';
    }
    return 0;
}