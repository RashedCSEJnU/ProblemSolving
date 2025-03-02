#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, maxi = INT_MAX;
        cin >> n;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;
        pair<int, int> p = {1, 1};
        for (int i = 0; i < n; i++)
        {
            int boro = 0, soto = 0;
            for (int j = i; j < n; j++)
            {
                if (v[j] > v[i])
                    boro++;
                else if (v[j] < v[i])
                    soto++;
                int cnt = boro - soto;
                if (maxi > cnt)
                {
                    maxi = cnt;
                    p = {i + 1, j + 1};
                }
            }
        }
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}