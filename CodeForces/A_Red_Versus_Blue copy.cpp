#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        string ans;
        while (b)
        {
            int x = (a + b) / (b + 1);
            ans += string(x, 'R');
            ans += 'B';
            a -= x, b--;
        }
        ans += string(a, 'R');
        cout << ans << '\n';
    }
    return 0;
}