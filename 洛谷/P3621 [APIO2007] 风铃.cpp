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
    const int MAXN = 1e5 + 5;
    const int INF = 0x3f3f3f3f;
    using input::read;
    using output::write;
    int n;
    int ans = 0;
    int mindep = INF, maxdep = -INF;
    struct Node
    {
        int lson, rson;
    };
    Node node[MAXN];
    void getMinMaxDep(int u, int dep)
    {
        if (u == -1)
        {
            mindep = std::min(mindep, dep);
            maxdep = std::max(maxdep, dep);
            return;
        }
        getMinMaxDep(node[u].lson, dep + 1), getMinMaxDep(node[u].rson, dep + 1);
    }
    int solve(int u, int dep) // 0 : mindep, 1 : maxdep, 2 : mixdep
    {
        if (u == -1)
        {
            return dep == maxdep;
        }
        int l = solve(node[u].lson, dep + 1), r = solve(node[u].rson, dep + 1);
        if (l == 0)
        {
            if (r == 0)
            {
                return 0;
            }
            if (r == 1)
            {
                ans++;
                return 2;
            }
            if (r == 2)
            {
                ans++;
                return 2;
            }
        }
        if (l == 1)
        {
            if (r == 0)
            {
                return 2;
            }
            if (r == 1)
            {
                return 1;
            }
            if (r == 2)
            {
                return 2;
            }
        }
        if (l == 2)
        {
            if (r == 0)
            {
                return 2;
            }
            if (r == 1)
            {
                ans++;
                return 2;
            }
            if (r == 2)
            {
                write(-1);
                exit(0);
            }
        }
        return 0;
    }
    int main()
    {
        read(n);
        for (int i = 1; i <= n; i++)
        {
            read(node[i].lson, node[i].rson);
        }
        getMinMaxDep(1, 1);
        if (maxdep - mindep > 1)
        {
            write(-1);
            exit(0);
        }
        solve(1, 1);
        write(ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}