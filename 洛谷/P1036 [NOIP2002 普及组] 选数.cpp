#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 20 + 5;
const int MAXS = 30;
int n, k;
int ans = 0;
int a[MAXN];
bool checkNumberOfOne(int x)
{
    int res = 0;
    while (x)
    {
        if (x & 1)
        {
            res++;
        }
        x = x >> 1;
    }
    return res == k;
}
LL qpow(LL a, LL b, LL mod)
{
    LL res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = res * a % mod;
        }
        a = a * a % mod;
        b = b >> 1;
    }
    return res;
}
bool checkIsPrime(int x)
{
    for (int i = 1; i <= MAXS; i++)
    {
        int tmp = rand() % (x - 1) + 1;
        if (qpow(tmp, x - 1, x) != 1)
        {
            return false;
        }
    }
    return true;
}
int getValue(int x)
{
    int res = 0, tot = n;
    while (x)
    {
        if (x & 1)
        {
            res += a[tot];
        }
        tot--, x >>= 1;
    }
    return res;
}
void solve()
{
    for (int i = 0; i < (1 << n); i++)
    {
        if (checkNumberOfOne(i) && checkIsPrime(getValue(i)))
        {
            ans++;
        }
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    solve();
    cout << ans << endl;
    return 0;
}