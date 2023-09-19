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
    int t;
    int n, k;
    bool vis[MAXN];
    int max[MAXN], min[MAXN];
    struct Node
    {
        int val, rank;
    };
    bool operator<(const Node a, const Node b)
    {
        return a.val < b.val;
    }
    Node node[MAXN];
    int main()
    {
        read(t);
        while (t--)
        {
            read(n, k);
            for (int i = 0; i <= k; i++)
            {
                max[i] = -INF, min[i] = INF;
            }
            for (int i = 1; i <= n; i++)
            {
                read(node[i].val);
                node[i].rank = i;
                vis[node[i].val] = true;
            }
            std::sort(node + 1, node + n + 1);
            std::reverse(node + 1, node + n + 1);
            for (int i = 1; i <= n; i++)
            {
                max[0] = std::max(max[0], node[i].rank), min[0] = std::min(min[0], node[i].rank);
                max[node[i].val] = std::max(max[node[i].val], max[0]), min[node[i].val] = std::min(min[node[i].val], min[0]);
            }
            for (int i = 1; i <= k; i++)
            {
                printf("%d ", vis[i] ? (max[i] - min[i] + 1) * 2 : 0);
            }
            printf("\n");
            for (int i = 1; i <= n; i++)
            {
                vis[node[i].val] = false;
            }
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}