#include <bits/stdc++.h>
using namespace std;

class DSU
{
private:
    vector<int> parent, Size;

public:
    DSU(int n)
    {
        parent.resize(n + 1);
        Size.resize(n + 1, 1);
        for (int i = 1; i <= n; ++i)
        {
            parent[i] = i;
        }
    }
    int Find(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = Find(parent[v]); // path compression
    }
    void Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);
        if (a == b)
            return;
        // Union by size
        if (Size[a] < Size[b])
            swap(a, b);
        parent[b] = a;
        Size[a] += Size[b];
    }

    bool connected(int a, int b)
    {
        return Find(a) == Find(b);
    }
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m1, m2;
        cin >> n >> m1 >> m2;
        DSU dsuF(n), dsuG(n);
        set<pair<int, int>> graphF, graphG;
        for (int i = 0; i < m1; ++i)
        {
            int u, v;
            cin >> u >> v;
            if (u > v)
                swap(u, v);
            graphF.insert({u, v});
        }

        for (int i = 0; i < m2; ++i)
        {
            int u, v;
            cin >> u >> v;
            if (u > v)
                swap(u, v);
            graphG.insert({u, v});
        }

        int operations = 0, cnt1 = 0, cnt2 = 0;
        for (auto [u, v] : graphG)
            dsuG.Union(u, v);

        for (auto [u, v] : graphF)
        {
            if (dsuG.connected(u, v))
                dsuF.Union(u, v);
            else
                operations++;
        }

        for (int i = 1; i <= n; ++i)
        {
            if (dsuG.Find(i) == i)
                cnt1++;
            if (dsuF.Find(i) == i)
                cnt2++;
        }
        operations += abs(cnt1 - cnt2);
        cout << operations << endl;
    }
    return 0;
}