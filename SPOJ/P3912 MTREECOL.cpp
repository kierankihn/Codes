#include <bits/stdc++.h>
namespace IO
{
    namespace basic_IO
    {
        template <typename T>
        void __read(T &x)
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
        template <typename First, typename... Rest>
        void __read(First &first, Rest &...rest)
        {
            __read(first);
            __read(rest...);
        }
        template <typename T>
        void __write(T x)
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
        template <typename First, typename... Rest>
        void __write(First &first, Rest &...rest)
        {
            __write(first), std::putchar(' '), __write(rest...);
        }
    }
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
    template <typename First, typename... Rest>
    void write(First &first, Rest &...rest)
    {
        basic_IO::__write(first, rest...), std::putchar('\n');
    }
    template <typename T>
    void writeAll(T *begin, T *end)
    {
        for (T *i = begin; i != end; i++)
        {
            basic_IO::__write(*i);
        }
    }
}
namespace solution
{
    using namespace IO;
    typedef double dbi;
    typedef long long i64;
    const int MAXN = 1e3 + 5;
    const int INF = 0x3f3f3f3f;
    int n, root;
    int ans = 0;
    int fa[MAXN];
    struct Node
    {
        int sum = 0, cnt = 0;
        dbi avr()
        {
            return double(sum) / double(cnt);
        }
    };
    Node operator+(const Node &a, const Node &b)
    {
        return {a.sum + b.sum, a.cnt + b.cnt};
    }
    Node node[MAXN << 2];
    int query()
    {
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            res = i != root && node[i].avr() > node[res].avr() ? i : res;
        }
        return res;
    }
    int father[MAXN];
    int find(int x)
    {
        return x == father[x] ? x : father[x] = find(father[x]);
    }
    void merge(int x, int y)
    {
        father[x] = y;
    }
    void init()
    {
        ans = 0;
        for (int i = 0; i <= n; i++)
        {
            father[i] = i;
            node[i].sum = -INF;
        }
    }
    int main()
    {
        while (read(n, root), n != 0 && root != 0)
        {
            init();
            for (int i = 1; i <= n; i++)
            {
                read(node[i].sum), node[i].cnt = 1, ans += node[i].sum;
            }
            for (int i = 1; i < n; i++)
            {
                int u, v;
                read(u, v), fa[v] = u;
            }
            for (int i = 1; i < n; i++)
            {
                int now = query(), f = find(fa[now]);
                ans += node[now].sum * node[f].cnt, node[f] = node[now] + node[f], node[now].sum = 0;
                merge(now, f);
            }
            write(ans);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}