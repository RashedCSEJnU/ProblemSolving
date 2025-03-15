#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;

        int op = 0, i = 0, j = n - 1, leftSum = 0, rightSum = 0, ans = 0;
        while (i <= j)
        {
            if (leftSum == rightSum)
            {
                ans = max(ans, op);
                if (v[i] < v[j])
                    leftSum += v[i++];
                else
                    rightSum += v[j--];
                op++;
                continue;
            }

            if (leftSum < rightSum)
                leftSum += v[i++];
            else
                rightSum += v[j--];
            op++;
        }
        // cout << leftSum << ' ' << rightSum << endl;
        if (leftSum == rightSum)
            ans = max(ans, op);
        cout << ans << '\n';
    }
    return 0;
}