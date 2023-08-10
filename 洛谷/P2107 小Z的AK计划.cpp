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
    using input::read;
    using output::write;
    struct Node
    {
        LL x, t;
    };
    bool operator<(const Node a, const Node b)
    {
        return a.x < b.x;
    }
    LL cost = 0;
    LL ans = 0, cnt = 0;
    LL n, m;
    Node node[MAXN];
    std::priority_queue<LL> q;
    int main()
    {
        read(n, m);
        for (int i = 1; i <= n; i++)
        {
            read(node[i].x, node[i].t);
        }
        std::sort(node + 1, node + n + 1);
        for (int i = 1; i <= n; i++)
        {
            if (node[i].x > m)
            {
                break;
            }
            while (cost + node[i].x > m)
            {
                cost -= q.top();
                cnt--;
                q.pop();
            }
            if (cost + node[i].t + node[i].x <= m)
            {
                q.push(node[i].t);
                cost += node[i].t;
                cnt++;
            }
            else
            {
                if (!q.empty() && node[i].t < q.top())
                {
                    q.pop();
                    cost -= q.top();
                    cost += node[i].t;
                }
            }
            ans = std::max(ans, cnt);
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