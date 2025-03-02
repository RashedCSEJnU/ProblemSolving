#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, k;
        string s;
        cin >> n >> k >> s;
        int sum = 0, ans = k;
        for (int i = 0; i < k; i++)
        {
            if (s[i] == 'W')
                sum++;
        }
        ans = min(sum, ans);
        for (int i = k; i < n; i++)
        {
            if (s[i] == 'W')
                sum++;
            if (s[i - k] == 'W')
                sum--;
            ans = min(ans, sum);
        }
        cout << ans << '\n';
    }
    return 0;
}