#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(2 * n + 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int x;
                cin >> x;
                a[i + j] = x;
            }
        }
        set<int> st;
        for (int i = 1; i <= 2 * n; i++)
            st.insert(i);

        for (int i = 0; i <= 2 * n; i++)
        {
            if (st.find(a[i]) != st.end())
            {
                st.erase(a[i]);
            }
        }
        cout << *st.begin() << ' ';
        for (int i = 0; i < 2 * n - 1; i++)
            cout << a[i] << ' ';
        cout << '\n';
    }
    return 0;
}