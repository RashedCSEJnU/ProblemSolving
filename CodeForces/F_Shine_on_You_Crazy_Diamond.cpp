#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define Sezar ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define tc(t) \
    int t;    \
    cin >> t; \
    while (t--)
#define ll long long
#define int long long
#define ld long double

typedef pair<int, int> pii;
typedef pair<int, int> pll;
typedef vector<int> vi;
typedef vector<int> vll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<int, int> umii;
typedef map<int, int> mii;
typedef unordered_map<int, int> umll;
typedef map<int, int> mll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#define all(v) (v).begin(), (v).end()
#define all1(v) (v).begin() + 1, (v).end()
#define sort0(v) sort(all(v))
#define pb emplace_back
#define ppb pop_back
#define mkp make_pair
#define ff first
#define ss second

#define forf(i, n) for (int i = 0; i < n; i++)
#define forb(i, n) for (int i = n - 1; i >= 0; i--)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define rloop(i, a, b) for (int i = a; i >= b; i--)

#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define inf 9223372036854775807

const int mod = 998244353;
const int MOD = 1000000007;
const int INF = LLONG_MAX;

const int N = 1e6 + 100;
vector<int> spf(N + 10, 1);
void sieve()
{
    spf[0] = 0;
    for (int i = 2; i <= N; i++)
    {
        if (spf[i] == 1)
        {
            for (int j = i; j <= N; j += i)
            {
                if (spf[j] == 1)
                    spf[j] = i;
            }
        }
    }
}

void solution()
{
    sieve();
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x = spf[v[i]];
        if (x != 1)
            mp[x]++;
    }
    vector<pair<int, int>> vp; // cnt ,value
    for (auto val : mp)
        vp.push_back({val.second, val.first});

    sort(vp.rbegin(), vp.rend());

    if (vp.size() == 0)
    {
        cout << n << endl;
        cout << 2 << ' ' << 3 << endl;
    }
    else if (vp.size() == 1)
    {
        cout << n - vp[0].first << endl;
        cout << vp[0].second << ' ' << 2 << endl;
    }
    else
    {
        int cnt = n - vp[0].first - vp[1].first;
        cout << cnt << endl;
        cout << vp[0].second << ' ' << vp[1].second << endl;
    }
}

int32_t main()
{
    Sezar;
    // tc(t) solution();
    solution();
}