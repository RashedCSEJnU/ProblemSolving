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
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;
        reverse(v.begin(), v.end());
        int sum = 0;
        multiset<int> s(v.begin(), v.end());
        for (int i = 0; i < n; i++)
        {
            int newSum = sum + *s.rbegin();
            cout << newSum << " ";
            sum += v[i];
            s.erase(s.find(v[i]));
        }
        cout << "\n";
    }
    return 0;
}