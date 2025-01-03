#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    vector<int> tree;
    int n;
    void build(const vector<int> &b, int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = b[start];
        }
        else
        {
            int mid = (start + end) / 2;
            build(b, 2 * node, start, mid);
            build(b, 2 * node + 1, mid + 1, end);
            tree[node] = __gcd(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int node, int start, int end, int l, int r)
    {
        if (r < start || l > end)
            return 0; // Out of range
        if (l <= start && end <= r)
            return tree[node]; // Completely in range
        int mid = (start + end) / 2;
        int leftGCD = query(2 * node, start, mid, l, r);
        int rightGCD = query(2 * node + 1, mid + 1, end, l, r);
        return __gcd(leftGCD, rightGCD);
    }

    void update(int node, int start, int end, int idx, int value)
    {
        if (start == end)
        {
            // Update leaf node
            tree[node] = value;
        }
        else
        {
            int mid = (start + end) / 2;
            if (idx <= mid)
            {
                // Update in the left subtree
                update(2 * node, start, mid, idx, value);
            }
            else
            {
                // Update in the right subtree
                update(2 * node + 1, mid + 1, end, idx, value);
            }
            // Recalculate GCD for this node
            tree[node] = __gcd(tree[2 * node], tree[2 * node + 1]);
        }
    }

public:
    SegmentTree(const vector<int> &b)
    {
        n = b.size();
        tree.resize(4 * n);
        build(b, 1, 0, n - 1);
    }
    int query(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
    }
    void update(int idx, int value)
    {
        update(1, 0, n - 1, idx, value);
    }
};

// // Build the Segment Tree
// SegmentTree segTree(b);
// l--, r--; // Convert to 0-based indexing
// cout << segTree.query(l, r - 1) << " ";

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    if (n == 1)
    {
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            cout << 0 << " ";
        }
        cout << "\n";
        return;
    }

    // Build the difference array
    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; i++)
        b[i] = abs(a[i + 1] - a[i]);

    // Build the Segment Tree
    SegmentTree segTree(b);

    while (q--)
    {

        int l, r;
        cin >> l >> r;
        if (l == r)
        {
            cout << 0 << " ";
        }
        else
        {
            l--, r--; // Convert to 0-based indexing
            cout << segTree.query(l, r - 1) << " ";
        }
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
