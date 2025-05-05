#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAX_SIZE = 1000001;
vector<int> isprime(MAX_SIZE, true);
vector<int> prime;
vector<int> spf(MAX_SIZE);
void seive(int N)
{
    isprime[0] = isprime[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (isprime[i])
        {
            prime.push_back(i);
            spf[i] = i;
        }
        for (int j = 0; j < prime.size() && i * prime[j] < N && prime[j] <= spf[i]; j++)
        {
            isprime[i * prime[j]] = false;
            spf[i * prime[j]] = prime[j];
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;

    seive(MAX_SIZE);

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        if (n == 1)
        {
            cout << (k == 2 ? "YES\n" : "NO\n");
            continue;
        }

        if (k > 1)
            cout << "NO\n";
        else
        {
            bool flag = true;
            for (int i = 0; prime[i] * prime[i] <= n; i++)
            {
                if (n % prime[i] == 0)
                {
                    flag = false;
                    break;
                }
            }
            cout << (flag ? "YES\n" : "NO\n");
        }
    }
    return 0;
}