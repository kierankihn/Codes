#include <bits/stdc++.h>
namespace input
{
    template <typename T>
    void read(T &x)
    {
        T res = 0, s = 1;
        char ch;
        while ((ch = getchar()) < '0' || ch > '9')
            if (ch == '-')
                s = -1;
        while (ch >= '0' && ch <= '9')
            res = res * 10 + ch - '0', ch = getchar();
        x = res * s;
    }
    template <typename First, typename... Rest>
    void read(First &first, Rest &...rest)
    {
        read(first);
        read(rest...);
    }
}
namespace output
{
    void write()
    {
        putchar('\n');
    }
    void write(char ch)
    {
        putchar(ch);
    }
    template <typename T>
    void write(char delimiter, T x)
    {
        if (x < 0)
            putchar('-'), x = -x;
        if (x > 9)
            write(delimiter, x / 10);
        putchar((x % 10) + '0');
    }
    template <typename First, typename... Rest>
    void write(char delimiter, First &first, Rest &...rest)
    {
        write(delimiter, first);
        putchar(delimiter);
        if (sizeof...(rest) >= 1)
        {
            write(delimiter, rest...);
        }
    }
    template <typename First, typename... Rest>
    void write(char delimiter, char linedelimiter, First &first, Rest &...rest)
    {
        write(delimiter, first);
        putchar(delimiter);
        if (sizeof...(rest) >= 1)
        {
            write(delimiter, rest...);
        }
        putchar(linedelimiter);
    }
    template <typename... T>
    void write(T... t)
    {
        write(' ', '\n', t...);
    }
}
namespace solution
{
    typedef long long LL;
    const int MOD = 1e9 + 7;
    const int MAXN = 2e5 + 5;
    using input::read;
    using output::write;
    int n;
    int tot;
    LL val[MAXN];
    LL tmp[MAXN];
    struct Node
    {
        LL max, cnt;
        Node(LL max_ = 0, LL cnt_ = 0) : max(max_), cnt(cnt_) {}
    };
    Node operator+(const Node a, const Node b)
    {
        Node res;
        if (a.max > b.max)
        {
            res.max = a.max, res.cnt = a.cnt;
        }
        if (a.max == b.max)
        {
            res.max = a.max, res.cnt = a.cnt + b.cnt;
        }
        if (a.max < b.max)
        {
            res.max = b.max, res.cnt = b.cnt;
        }
        res.max %= MOD, res.cnt %= MOD;
        return res;
    }
    Node ans;
    Node s[MAXN][2];
    LL lowbit(LL x)
    {
        return x & (-x);
    }
    void update(LL idx, LL x, Node v)
    {
        while (x <= n)
        {
            s[x][idx] = s[x][idx] + v;
            x += lowbit(x);
        }
    }
    Node query(LL idx, LL x)
    {
        Node res;
        while (x > 0)
        {
            res = res + s[x][idx];
            x -= lowbit(x);
        }
        return res;
    }
    LL qpow(LL a, LL b, LL c)
    {
        LL res = 1;
        while (b)
        {
            if (b & 1)
            {
                res = res * a % c;
            }
            b = b >> 1;
            a = a * a % c;
        }
        return res;
    }
    int main()
    {
        read(n);
        for (int i = 1; i <= n; i++)
        {
            read(val[i]);
            tmp[i] = val[i];
        }
        std::sort(tmp + 1, tmp + n + 1);
        tot = std::unique(tmp + 1, tmp + n + 1) - tmp;
        for (int i = 1; i <= n; i++)
        {
            val[i] = std::lower_bound(tmp + 1, tmp + n + 1, val[i]) - tmp;
        }
        for (int i = n; i >= 1; i--)
        {
            Node x = query(0, n - val[i]), y = query(1, val[i] - 1);
            x.max++, y.max++;
            if (x.max == 1)
            {
                x.cnt = 1;
            }
            if (y.max == 1)
            {
                y.cnt = 1;
            }
            update(0, n - val[i] + 1, x), update(1, val[i], y);
            int len = x.max + y.max - 1;
            if (len > ans.max)
            {
                ans.max = len, ans.cnt = x.cnt * y.cnt % MOD * qpow(2, n - len, MOD) % MOD;
                ans.cnt %= MOD;
            }
            else if (len == ans.max)
            {
                ans.cnt += x.cnt * y.cnt % MOD * qpow(2, n - len, MOD) % MOD;
                ans.cnt %= MOD;
            }
        }
        write(ans.max, ans.cnt);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}