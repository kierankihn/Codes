#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MAXN = 1e8 + 5;
int n = 1e6;
int l, r;
int ans = 0;
LL prime[MAXN];
bool notprime[MAXN];
void getPrime()
{
    for (int i = 2; i <= n; i++)
    {
        if (!notprime[i])
        {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] <= n; j++)
        {
            notprime[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
}
int main()
{
    cin >> l >> r;
    getPrime();
    if (l == 1)
    {
        l = 2;
    }
    memset(notprime, 0, sizeof(notprime));
    for (int i = 1; i <= prime[0]; i++)
    {
        LL p = prime[i], j = (l - p + 1) / p * p > 2 * p ? (l - p + 1) / p * p : 2 * p;
        for (; j <= r; j += p)
        {
            notprime[j - l + 1] = true;
        }
    }
    for (int i = 1; i <= r - l + 1; i++)
    {
        if (!notprime[i])
        {
            ans++;
        }
    }
    cout << ans << endl;
}