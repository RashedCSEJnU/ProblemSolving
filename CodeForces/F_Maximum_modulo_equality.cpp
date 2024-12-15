#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 2;
int tree[4 * N], a[N];
void build(int node, int st, int en)
{
    if (st == en)
    {
        tree[node] = a[st];
        return;
    }

    int mid = (st + en) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, en);
    // operation
    tree[node] = __gcd(tree[2 * node], tree[2 * node + 1]);
}

int query(int node, int st, int en, int l, int r)
{
    if (en < l || st > r)
    {
        return 0;
    }

    if (l <= st && en <= r)
        return tree[node];

    int mid = (st + en) / 2;
    int q1 = query(2 * node, st, mid, l, r);
    int q2 = query(2 * node + 1, mid + 1, en, l, r);

    // operation
    return __gcd(q1, q2);
}

void update(int node, int st, int en, int idx, int val)
{
    if (st == en)
    {
        a[st] = val;
        tree[node] = val;
        return;
    }

    int mid = (st + en) / 2;
    if (idx <= mid)
        update(2 * node, st, mid, idx, val);
    else
        update(2 * node + 1, mid + 1, en, idx, val);
    // operation
    tree[node] = __gcd(tree[2 * node], tree[2 * node + 1]);
}

// before use segment tree build first
// build(1, 0, n - 1);
// update(1, 0, n - 1, idx, val); // a[idx]=val
// query(1, 0, n - 1, l, r);      // sum in range [l,r]
// Taking array input in a[i]

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;

        for (int i = 0; i < n; i++)
            cin >> a[i];

        if (n == 1)
        {
            for (int i = 0; i < q; i++)
            {
                int l, r;
                cin >> l >> r;
                cout << 0 << ' ';
            }
            cout << '\n';
            continue;
        }

        for (int i = 0; i < n - 1; i++)
            a[i] = abs(a[i] - a[i + 1]);

        build(1, 0, n - 1);
        for (int i = 0; i < q; i++)
        {
            int l, r;
            cin >> l >> r;
            cout << query(1, 0, n - 1, l - 1, r - 1) << ' ';
        }
        cout << '\n';
    }
    return 0;
}