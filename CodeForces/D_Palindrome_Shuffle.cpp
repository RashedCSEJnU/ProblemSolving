#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Pair
{
    int i, j;
    char c1, c2;
};

int32_t main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();

        bool isPal = true;
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] != s[n - 1 - i])
            {
                isPal = false;
                break;
            }
        }
        if (isPal)
        {
            cout << 0 << "\n";
            continue;
        }

        vector<Pair> pairs;
        for (int i = 0; i < n / 2; i++)
        {
            int j = n - 1 - i;
            if (s[i] != s[j])
            {
                Pair p;
                p.i = i + 1; // convert to 1-indexed
                p.j = j + 1;
                p.c1 = s[i];
                p.c2 = s[j];
                pairs.push_back(p);
            }
        }

        vector<vector<int>> pref(n + 1, vector<int>(26, 0));
        for (int i = 1; i <= n; i++)
        {
            pref[i] = pref[i - 1];
            pref[i][s[i - 1] - 'a']++;
        }
        auto windowValid = [&](int L, int R) -> bool
        {
            vector<int> req(26, 0);
            for (auto &p : pairs)
            {
                bool in_i = (p.i >= L && p.i <= R);
                bool in_j = (p.j >= L && p.j <= R);
                if (!in_i && !in_j)
                    return false;
                if (in_i && !in_j)
                    req[p.c2 - 'a']++;

                if (!in_i && in_j)
                    req[p.c1 - 'a']++;
            }
            vector<int> avail(26, 0);
            for (int c = 0; c < 26; c++)
            {
                avail[c] = pref[R][c] - pref[L - 1][c];
                if (avail[c] < req[c])
                    return false;
            }
            return true;
        };

        int best = n;
        int low = 0, high = n;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            bool possible = false;

            for (int L = 1; L + mid - 1 <= n; L++)
            {
                int R = L + mid - 1;
                if (windowValid(L, R))
                {
                    possible = true;
                    break;
                }
            }
            if (possible)
            {
                best = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        cout << best << "\n";
    }
    return 0;
}