#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vector<int> v[n], prefix[n];
    for (int i = 0; i < n; i++)
    {
        int month;
        cin >> month;
        for (int j = 0; j < month; j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
            prefix[i].push_back(x);
            if (j > 0)
                prefix[i][j] += prefix[i][j - 1];
        }
    }

    int q;
    cin >> q;

    for (int qc = 1; qc <= q; qc++)
    {
        cout << "Query " << qc << ": ";
        int c1, c2, day, month, year;
        cin >> c1 >> c2 >> day >> month >> year;
        c1--, c2--, month--;

        int year1 = prefix[c1].back(), year2 = prefix[c2].back();
        int totalDay = (year - 1) * year1 + day;
        if (month)
            totalDay += prefix[c1][month - 1];

        int newDay = 0, newMonth = 0, newYear;
        newYear = 1 + (totalDay / year2);
        totalDay %= year2;

        if (totalDay == 0)
        {
            newYear--;
            newMonth = v[c2].size();
            newDay = v[c2].back();
        }
        else
        {
            vector<int> &temp = prefix[c2];
            auto it = lower_bound(temp.begin(), temp.end(), totalDay);
            if (it == temp.begin())
            {
                newMonth = 1;
                newDay = totalDay;
            }
            else
            {

                newMonth = it - temp.begin() + 1;
                it--;
                totalDay -= *it;
                newDay = totalDay;
            }
        }

        cout << newDay << ' ' << newMonth << ' ' << newYear << '\n';
    }
    return 0;
}