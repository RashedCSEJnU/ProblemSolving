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
        deque<int> q(n);
        for (int i = 0; i < n; i++)
            cin >> q[i];

        while (!q.empty() && q.front() == 0)
            q.pop_front();
        while (!q.empty() && q.back() == 0)
            q.pop_back();

        if (q.empty())
        {
            cout << 0 << endl;
            continue;
        }

        int cnt = 0;
        for (int i = 0; i < q.size(); i++)
        {
            if (q[i] == 0)
                cnt++;
        }
        if (cnt == 0)
            cout << 1 << endl;
        else
            cout << 2 << endl;
    }
    return 0;
}