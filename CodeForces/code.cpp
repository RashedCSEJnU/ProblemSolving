#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, k;
    cin >> n >> k;
    int ans = 0, mid = (n + 1) / 2;
    int totalSize = n * k;
    int sum = 0, fst = mid - 1, lst = mid + 1; // assume the n is divisiable by 2
    if (n & 1)
        lst = mid;
    fst = max(1LL, fst);

    for (int i = 0, j = totalSize - lst; i < j && i < totalSize; i += fst, j -= lst)
    {
        cout << i << ' ' << j << '\n';
    }

    return 0;
}