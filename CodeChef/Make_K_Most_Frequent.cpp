#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k, totalK = 0, maxi = 1;
        cin >> n >> k;
        vector<int> a(n), dane(21), bame(21);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            dane[a[i]]++;
            maxi = max(maxi, dane[a[i]]);
        }
        if (dane[k] >= maxi)
        {
            cout << 0 << endl;
            continue;
        }
        int ans = 2;
        for (int i = 0; i < n - 1; i++)
        {
            dane[a[i]]--;
            bame[a[i]]++;

            int maxFreqDane = 0, maxFreqBame = 0;
            for (int j = 0; j < 21; j++)
            {
                maxFreqDane = max(maxFreqDane, dane[j]);
                maxFreqBame = max(maxFreqBame, bame[j]);
            }

            if (maxFreqDane <= dane[k] || maxFreqBame <= bame[k])
            {
                ans = 1;
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
