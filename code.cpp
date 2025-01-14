#include <bits/stdc++.h>
using namespace std;

vector<int> longestIncreasingSubsequence(int n, vector<int> &arr)
{
    vector<int> dp(n, 1), hash(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                hash[i] = j;
            }
        }
    }
    vector<int> ans;
    int maxi = -1, id = -1;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            id = i;
        }
    }
    while (id != -1)
    {
        ans.push_back(arr[id]);
        id = hash[id];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, i;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    auto it = longestIncreasingSubsequence(n, v);
    for (auto i : it)
        cout << i << " ";
    return 0;
}