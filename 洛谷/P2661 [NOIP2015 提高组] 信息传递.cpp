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
    const int MAXN = 2e5 + 5;
    const int INF = 0x3f3f3f3f;
    using input::read;
    using output::write;
    int n;
    int ans = INF;
    int nxt[MAXN];
    int in[MAXN];
    bool vis[MAXN];
    std::queue<int> q;
    void topo()
    {
        for (int i = 1; i <= n; i++)
        {
            if (in[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            vis[u] = true;
            in[nxt[u]]--;
            if (in[nxt[u]] == 0)
            {
                q.push(nxt[u]);
            }
        }
    }
    int dfs(int u)
    {
        int res = 0;
        vis[u] = true;
        if (vis[nxt[u]] == false)
        {
            res = dfs(nxt[u]) + 1;
        }
        else
        {
            res = 1;
        }
        return res;
    }
    int main()
    {
        read(n);
        for (int i = 1; i <= n; i++)
        {
            read(nxt[i]);
            in[nxt[i]]++;
        }
        topo();
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == false)
            {
                ans = std::min(ans, dfs(i));
            }
        }
        write(ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}