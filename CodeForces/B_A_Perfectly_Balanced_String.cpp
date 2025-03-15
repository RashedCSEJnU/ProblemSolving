#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        bool flag = true;
        set<char> st;
        int i, n = s.length();
        for (i = 0; i < n; i++)
        {
            if (st.find(s[i]) == st.end())
                st.insert(s[i]);
            else
                break;
        }
        for (int j = i; j < n; j++)
        {
            if (s[j] != s[j - i])
                flag = false;
        }

        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}