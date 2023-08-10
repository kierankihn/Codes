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
    const int MAXN = 150000 + 5;
    int n;
    LL now = 0;
    int ans = 0;
    struct Node
    {
        int id;
        int t1, t2;
    };
    Node node[MAXN];
    bool operator<(const Node a, const Node b)
    {
        return a.t1 < b.t1;
    }
    bool cmp(const Node a, const Node b)
    {
        return a.t2 < b.t2;
    }
    std::priority_queue<int> q;
    int main()
    {
        using input::read;
        using output::write;
        read(n);
        for (int i = 1; i <= n; i++)
        {
            node[i].id = i;
            read(node[i].t1, node[i].t2);
        }
        std::sort(node + 1, node + n + 1, cmp);
        for (int i = 1; i <= n; i++)
        {
            if (node[i].t2 - now < node[i].t1)
            {
                if (!q.empty() && q .top() > node[i].t1)
                {
                    now = now - q.top() + node[i].t1;
                    q.pop();
                    q.push(node[i].t1);
                }
            }
            else
            {
                now += node[i].t1, ans++, q.push(node[i].t1);
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