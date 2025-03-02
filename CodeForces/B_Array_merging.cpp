#include <bits/stdc++.h>
using namespace std;

void func(vector<int> &a, map<int, int> &mpA)
{
    int cnt = 1, val = a[0];
    mpA[val] = 1;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] == val)
            cnt++;
        else
        {
            mpA[val] = max(mpA[val], cnt);
            val = a[i], cnt = 1;
        }
    }
    if (cnt)
        mpA[val] = max(mpA[val], cnt);
}
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n), c;
        for (int &i : a)
            cin >> i;
        for (int &i : b)
            cin >> i;
        map<int, int> mpA, mpB;
        func(a, mpA), func(b, mpB);

        int ans = 0;
        for (auto [a, b] : mpA)
            ans = max(ans, b + mpB[a]);
        for (auto [a, b] : mpB)
            ans = max(ans, b + mpA[a]);
        cout << ans << '\n';
    }
    return 0;
}