#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    return __gcd(a, b);
}
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << ' ' << lcm(a, b) << endl;
}