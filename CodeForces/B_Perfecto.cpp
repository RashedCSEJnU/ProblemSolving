#include <bits/stdc++.h>
using namespace std;
#define int long long

bool perfectSqure(int sum)
{
    int sq = sqrt(sum);
    return sq * sq == sum;
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int tot = n * (n + 1) / 2;
        if (perfectSqure(tot))
        {
            cout << -1 << '\n';
            continue;
        }

        vector<int> v;
        deque<int> dq;
        int sum = 0;
        for (int i = 0; i < n; i++)
            dq.push_back(i + 1);

        bool flag = false;
        while (!dq.empty())
        {
            if (!perfectSqure(sum + dq.front()))
            {
                v.push_back(dq.front());
                sum += dq.front();
                dq.pop_front();
                continue;
            }
            if (!perfectSqure(sum + dq.back()))
            {
                v.push_back(dq.back());
                sum += dq.back();
                dq.pop_back();
                continue;
            }

            if (dq.size() > 1)
            {
                int fst = dq.front();
                dq.pop_front();
                if (!perfectSqure(sum + dq.front()))
                {
                    v.push_back(dq.front());
                    sum += dq.front();
                    dq.pop_front();
                    dq.push_front(fst);
                    continue;
                }
                dq.push_front(fst);
                int lst = dq.back();
                dq.pop_back();
                if (!perfectSqure(sum + dq.back()))
                {
                    v.push_back(dq.back());
                    sum += dq.back();
                    dq.pop_back();
                    dq.push_back(lst);
                    continue;
                }
                dq.push_back(lst);
            }

            flag = true;
            break;
        }

        if (flag)
        {
            cout << -1 << '\n';
            continue;
        }

        for (int i = 0; i < n; i++)
            cout << v[i] << " ";
        cout << '\n';
    }
    return 0;
}