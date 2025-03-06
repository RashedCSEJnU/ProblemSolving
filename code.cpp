#include <bits/stdc++.h>
using namespace std;

void printValue(int x)
{
    for (int i = 3; i >= 0; i--)
    {
        if ((x >> i) & 1)
            cout << 1 << ' ';
        else
            cout << 0 << ' ';
    }
    cout << '\n';
}

int main()
{
    // int n;
    // cin >> n;
    // for (int i = 0; i <= n; i++)
    // {
    //     printValue(i);
    // }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;
        int val = 0;
        for (int i = 0; i < n - 1; i++)
        {
            val = max(val, v[i] ^ v[i + 1]);
        }
        cout << val << '\n';
    }

    return 0;
}