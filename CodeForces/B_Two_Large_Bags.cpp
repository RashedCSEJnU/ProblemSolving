#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> mp(n + 1), a, b;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            mp[x]++;
        }
        for (int i = n; i > 0; i--)
        {
            while (mp[i] > 0)
            {
                if (mp[i] > 0)
                {
                    b.push_back(i);
                    mp[i]--;
                }
                if (mp[i] > 0)
                {
                    a.push_back(i);
                    mp[i]--;
                }
            }
        }
        sort(b.rbegin(), b.rend());
        while (b.size() > a.size())
        {
            a.push_back(b.back());
            b.pop_back();
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if (a > b)
            swap(a, b);
        // cout << "VecA: ";
        // for (auto val : a)
        //     cout << val << ' ';
        // cout << '\n';
        // cout << "VecB: ";
        // for (auto val : b)
        //     cout << val << ' ';
        // cout << '\n';
        // cout << '\n';
        vector<int> va(n + 1), vb(n + 1);
        for (int i = 0; i < a.size(); i++)
        {
            va[a[i]]++;
            vb[b[i]]++;
        }
        bool flag = true;
        while (a.size() && b.size())
        {
            if (a.back() == b.back())
            {
                va[a.back()]--;
                vb[b.back()]--;
                a.pop_back();
                b.pop_back();
                continue;
            }
            bool possile = true;
            int cur = a.back();
            for (int i = a.back(); i <= b.back(); i++)
            {
                cur += vb[i];

                if (vb[i] == 0 && cur < b.back())
                {
                    possile = false;
                    break;
                }
            }
            if (!possile)
            {
                flag = false;
                break;
            }
            else
            {
                va[a.back()]--;
                vb[b.back()]--;
                a.pop_back();
                b.pop_back();
            }
        }
        cout << (flag ? "Yes\n" : "No\n");
    }
    return 0;
}
