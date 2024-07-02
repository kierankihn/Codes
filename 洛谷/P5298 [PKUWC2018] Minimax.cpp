/**
 * @author Kieran Kihn
 * @date 2024.07.01
 * @name P5298 [PKUWC2018] Minimax
 * @link https://www.luogu.com.cn/problem/P5298
 */
#include <bits/stdc++.h>
namespace IO
{
    namespace basic_IO
    {
        template <typename T>
        typename std::enable_if<std::is_integral<T>::value>::type __read(T &x)
        {
            char ch;
            T res = 0, f = 1;
            while (std::isdigit(ch = getchar()) == false)
            {
                f = (ch != '-');
            }
            do
            {
                res = res * 10 + (ch - '0');
            } while (std::isdigit(ch = getchar()) == true);
            x = res * (f ? 1 : -1);
        }
        template <typename T>
        typename std::enable_if<!std::is_integral<T>::value>::type __read(T &x)
        {
            std::cin >> x;
        }
        template <typename First, typename... Rest>
        void __read(First &first, Rest &...rest)
        {
            __read(first);
            __read(rest...);
        }
        template <typename T>
        typename std::enable_if<std::is_integral<T>::value>::type __write(T x)
        {
            if (x < 0)
            {
                std::putchar('-'), __write(-x);
                return;
            }
            if (x >= 10)
            {
                __write(x / 10);
            }
            std::putchar(x % 10 + '0');
        }
        template <typename T>
        typename std::enable_if<!std::is_integral<T>::value>::type __write(T x)
        {
            std::cout << x;
        }
        template <typename First, typename... Rest>
        void __write(First first, Rest... rest)
        {
            __write(first), std::putchar(' '), __write(rest...);
        }
    }  // namespace basic_IO
    template <typename First, typename... Rest>
    void read(First &first, Rest &...rest)
    {
        basic_IO::__read(first, rest...);
    }
    template <typename T>
    void readAll(T *begin, T *end)
    {
        for (T *i = begin; i != end; i++)
        {
            basic_IO::__read(*i);
        }
    }
    long long readi()
    {
        long long res;
        read(res);
        return res;
    }
    std::string reads()
    {
        std::string res;
        read(res);
        return res;
    }
    template <typename First, typename... Rest>
    void write(First first, Rest... rest)
    {
        basic_IO::__write(first, rest...), std::putchar('\n');
    }
    template <typename T>
    void writeAll(T *begin, T *end)
    {
        for (T *i = begin; i != end; i++)
        {
            basic_IO::__write(*i), std::putchar(' ');
        }
        std::putchar('\n');
    }
}  // namespace IO
namespace solution
{
    using namespace IO;
    typedef long long i64;

    constexpr int W    = 1e9;
    constexpr int MAXN = 3e5 + 5;
    constexpr int MOD  = 998244353;

    i64 qpow(i64 a, i64 b = MOD - 2, i64 c = MOD)
    {
        i64 res = 1;
        while (b)
        {
            if (b & 1)
            {
                res *= a, res %= c;
            }
            a *= a, a %= c, b >>= 1;
        }
        return res;
    }

    int n;
    i64 p[MAXN];

    std::vector<int> e[MAXN];

    struct Node
    {
        i64 sum, tag;
        int lson, rson;
    };

    int size = 0;
    int root[MAXN];
    Node node[MAXN * 40];
    void modify(int o, i64 v)
    {
        node[o].sum *= v, node[o].sum %= MOD, node[o].sum += MOD, node[o].sum %= MOD;
        node[o].tag *= v, node[o].tag %= MOD, node[o].tag += MOD, node[o].tag %= MOD;
    }
    void pushup(int o)
    {
        node[o].sum = (node[node[o].lson].sum + node[node[o].rson].sum) % MOD;
    }
    void pushdown(int o)
    {
        modify(node[o].lson, node[o].tag);
        modify(node[o].rson, node[o].tag);
        node[o].tag = 1;
    }
    void update(int x, int v, int &o, int l = 1, int r = W)
    {
        if (o == 0)
        {
            node[o = ++size].tag = 1;
        }
        if (l == r)
        {
            node[o].sum += v;
            return;
        }

        int mid = (l + r) >> 1;
        if (x <= mid)
        {
            update(x, v, node[o].lson, l, mid);
        }
        if (x > mid)
        {
            update(x, v, node[o].rson, mid + 1, r);
        }

        pushup(o);
    }
    int merge(int x, int y, int minp, int maxp, i64 sumx = 0, i64 sumy = 0, int l = 1, int r = W)
    {
        if (x == 0 && y == 0)
        {
            return 0;
        }
        if (x == 0 && y != 0)
        {
            sumy += node[y].sum, sumy %= MOD;
            modify(y, (sumx * maxp + (1 - sumx + MOD) % MOD * minp) % MOD);
            return y;
        }
        if (x != 0 && y == 0)
        {
            sumx += node[x].sum, sumx %= MOD;
            modify(x, (sumy * maxp + (1 - sumy + MOD) % MOD * minp) % MOD);
            return x;
        }

        pushdown(x), pushdown(y);

        int res = ++size;
        int mid = (l + r) >> 1;

        i64 sumx_l = node[node[x].lson].sum, sumy_l = node[node[y].lson].sum;

        node[res].tag  = 1;
        node[res].lson = merge(node[x].lson, node[y].lson, minp, maxp, sumx, sumy, l, mid);
        node[res].rson = merge(node[x].rson, node[y].rson, minp, maxp, (sumx + sumx_l) % MOD, (sumy + sumy_l) % MOD, mid + 1, r);

        pushup(res);

        return res;
    }

    void solve(int u)
    {
        if (e[u].size() == 0)
        {
            update(p[u], 1, root[u]);
            return;
        }
        for (auto v : e[u])
        {
            solve(v);
        }
        if (e[u].size() == 1)
        {
            root[u] = root[e[u][0]];
        }
        if (e[u].size() == 2)
        {
            int minp = (1 - p[u] + MOD) % MOD, maxp = p[u];
            root[u] = merge(root[e[u][0]], root[e[u][1]], minp, maxp);
        }
    }

    i64 tot = 0;
    i64 ans = 0;
    void dfs(int o, int l = 1, int r = W)
    {
        if (o == 0)
        {
            return;
        }
        if (l == r)
        {
            tot++, ans += tot * l % MOD * node[o].sum % MOD * node[o].sum % MOD, ans %= MOD;
            return;
        }

        pushdown(o);

        int mid = (l + r) >> 1;

        dfs(node[o].lson, l, mid), dfs(node[o].rson, mid + 1, r);
    }

    int main()
    {
        read(n);
        for (int i = 1; i <= n; i++)
        {
            e[readi()].push_back(i);
        }
        for (int i = 1, inv = qpow(10000); i <= n; i++)
        {
            read(p[i]);
            if (e[i].size() != 0)
            {
                p[i] = p[i] * inv % MOD;
            }
        }

        solve(1);

        dfs(root[1]);

        write(ans);

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}