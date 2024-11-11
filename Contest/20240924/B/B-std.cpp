#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
int powmod(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1) ans = 1ll * ans * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return ans;
}
const int maxn = 1000010;
bool vis[maxn];
int pri[maxn], cnt;
int d[maxn];
int mx[maxn];
int id[maxn];
void init()
{
    d[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        if (!vis[i])
        {
            pri[++cnt] = i;
            d[i]       = i;
            id[i]      = cnt;
        }
        for (int j = 1; j <= cnt && pri[j] * i < maxn; j++)
        {
            vis[i * pri[j]] = 1;
            d[i * pri[j]]   = pri[j];
            if (i % pri[j] == 0)
            {
                break;
            }
        }
    }
    for (int i = 1000; i < maxn; i++)
    {
        int tmp = i;
        while (d[tmp] != tmp)
        {
            tmp /= d[tmp];
        }
        if (tmp > 1000)
        {
            mx[i] = tmp;
        }
    }
}
typedef bitset<169> bst;
int main()
{
#ifdef LOCAL
    std::freopen("B.in", "r", stdin);
    std::freopen("B-std.out", "w", stdout);
#endif

    init();
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        map<int, vector<int> > mp;
        for (int i = 0; i < n; i++)
        {
            if (mx[a[i]])
            {
                mp[mx[a[i]]].push_back(a[i] / mx[a[i]]);
            }
            else
            {
                mp[0].push_back(a[i]);
            }
        }
        int ans = 1;
        bst b[169];
        for (auto &x : mp)
        {
            vector<int> &v = x.second;
            int fi         = (x.first != 0);
            vector<bst> vi;
            for (int i = 0; i < v.size(); i++)
            {
                int val = v[i];
                bst tmp;
                while (val != 1)
                {
                    tmp[id[d[val]] - 1] = 1;
                    val /= d[val];
                }
                vi.push_back(tmp);
            }
            auto insert = [&](bst x) -> bool
            {
                for (int j = 0; j < 169; j++)
                {
                    if (x[j] == 0) continue;
                    if (b[j].count() == 0)
                    {
                        b[j] = x;
                        return true;
                    }
                    else
                    {
                        x ^= b[j];
                    }
                }
                return false;
            };
            if (fi == 0)
            {
                for (int i = 0; i < vi.size(); i++)
                {
                    if (!insert(vi[i]))
                    {
                        ans = ans * 2 % mod;
                    }
                }
            }
            else
            {
                for (int i = 1; i < vi.size(); i++)
                {
                    if (!insert(vi[i] ^ vi[0]))
                    {
                        cnt++;
                        ans = ans * 2 % mod;
                    }
                }
            }
        }
        cout << (ans + mod - 1) % mod << endl;
    }
    return 0;
}