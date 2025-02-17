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

        bool flag = false;
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == s[i - 1])
                flag = true;
        }
        cout << (flag ? 1 : s.length()) << '\n';
    }
    return 0;
}