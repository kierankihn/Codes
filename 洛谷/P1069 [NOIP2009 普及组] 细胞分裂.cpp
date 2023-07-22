#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int MAXN = 10000 + 5;
const int MAXM = 30000 + 5;
int n, m1, m2;
vector<pair<int, int>> fac;
int prime[MAXM];
bool notprime[MAXM];
double cnt[MAXN];
double maxcnt = INF;
int val[MAXN];
void getPrime(int x)
{
    for (int i = 2; i <= x; i++)
    {
        if (notprime[i])
        {
            continue;
        }
        prime[++prime[0]] = i;
        for (int j = i; j * i <= x; j++)
        {
            notprime[j * i] = true;
        }
    }
}
int getFactorNumber(int x, int factor)
{
    int res = 0;
    while (x != 0 && x % factor == 0)
    {
        res++;
        x /= factor;
    }
    return res;
}
void getFactor()
{
    getPrime(m1);
    for (int i = 1; i <= prime[0]; i++)
    {
        if (m1 % prime[i] == 0)
        {
            fac.push_back(pair<int, int>(prime[i], getFactorNumber(m1, prime[i])));
        }
    }
}
int main()
{
    cin >> n >> m1 >> m2;
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
    }
    getFactor();
    for (int i = 1; i <= n; i++)
    {
        for (unsigned int j = 0; j < fac.size(); j++)
        {
            if (val[i] % fac[j].first == 0)
            {
                cnt[i] = max(cnt[i], (double)fac[j].second / getFactorNumber(val[i], fac[j].first));
            }
            else
            {
                cnt[i] = INF;
            }
        }
        maxcnt = min(maxcnt, cnt[i]);
    }
    if (maxcnt == INF)
    {
        cout << -1 << endl;
        return 0;
    }
    else
    {
        cout << ceil(m2 * maxcnt) << endl;
    }
    return 0;
}