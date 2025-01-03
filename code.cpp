#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &v)
    {
        int n = v.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        int afterBuy = 0, afterSell = 0, curBuy = 0, curSell = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            curBuy = max(afterBuy, -v[i] + afterSell);
            curSell = max(afterSell, v[i] + afterBuy);

            afterBuy = curBuy;
            afterSell = curSell;
        }
        return afterBuy;
    }
};
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    Solution ob;
    cout << ob.maxProfit(v) << '\n';

    return 0;
}
