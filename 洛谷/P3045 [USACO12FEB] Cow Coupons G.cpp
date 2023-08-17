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
    const int MAXN = 5e4 + 5;
    using input::read;
    using output::write;
    struct Node
    {
        LL c, p;
    };
    bool sortCmpMinC(const Node a, const Node b)
    {
        return a.c < b.c;
    }
    bool sortCmpMinP(const Node a, const Node b)
    {
        return a.p < b.p;
    }
    struct CmpP
    {
        bool operator()(const Node a, const Node b)
        {
            return a.p > b.p;
        }
    };
    struct CmpC
    {
        bool operator()(const Node a, const Node b)
        {
            return a.p - a.c > b.p - b.c;
        }
    };
    LL n, m, k;
    LL cnt = 0;
    int ans = 0;
    Node node[MAXN];
    std::priority_queue<Node, std::vector<Node>, CmpC> qc;
    int main()
    {
        read(n, k, m);
        for (int i = 1; i <= n; i++)
        {
            read(node[i].p, node[i].c);
        }
        std::sort(node + 1, node + n + 1, sortCmpMinC);
        std::sort(node + k + 1, node + n + 1, sortCmpMinP);
        for (int i = 1; i <= n; i++)
        {
            if (i <= k)
            {
                if (cnt + node[i].c <= m)
                {
                    cnt += node[i].c;
                    qc.push(node[i]);
                    ans++;
                }
            }
            else
            {
                if ((!qc.empty() && cnt - qc.top().c + qc.top().p + node[i].c <= m) || (cnt + node[i].p <= m))
                {
                    if (!qc.empty() && (qc.top().p - qc.top().c + node[i].c < node[i].p))
                    {
                        ans++;
                        cnt -= qc.top().c;
                        cnt += node[i].c;
                        cnt += qc.top().p;
                        qc.pop();
                        qc.push(node[i]);
                    }
                    else
                    {
                        if (cnt + node[i].p <= m)
                        {
                            ans++;
                            cnt += node[i].p;
                        }
                    }
                }
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