#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    priority_queue<int> pq;
    multiset<int> st;

    int rem = m, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (rem >= v[i])
        {
            cnt++;
            rem -= v[i];
            pq.push(v[i]);
        }
        else
        {
            if (!pq.empty() && pq.top() > v[i])
            {
                rem += pq.top();
                st.insert(pq.top());
                pq.pop();
                rem -= v[i];
                pq.push(v[i]);
            }
            else
            {
                st.insert(v[i]);
            }
        }
        cout << cnt << '\n';
    }
    cout << '\n';
    return 0;
}