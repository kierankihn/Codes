/**
 * @author Kieran Kihn
 * @date 2024.07.16
 * @name I
 * @link
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

    constexpr int MAXN = 2e5 + 5;

    int n, m;

    std::vector<int> e[MAXN];

    i64 dfc = 0;
    i64 dep[MAXN], dfn[MAXN], end[MAXN], a[MAXN], b[MAXN];

    void dfs(int u, int fa)
    {
        dep[u] = dep[fa] + 1, dfn[u] = ++dfc, b[u] = (dep[u] & 1) ? 1 : -1;

        for (auto v : e[u])
        {
            if (v != fa)
            {
                dfs(v, u);
            }
        }

        end[u] = dfc;
    }

    struct Node
    {
        i64 sum, tag;
    };
    Node operator+(const Node &a, const Node &b)
    {
        return {std::max(a.sum, b.sum), 0};
    }

    i64 val[MAXN];

    Node node[MAXN << 2];
    void modify(int o, i64 v)
    {
        node[o].sum += v, node[o].tag += v;
    }
    void pushup(int o)
    {
        node[o] = node[o << 1] + node[o << 1 | 1];
    }
    void pushdown(int o)
    {
        modify(o << 1, node[o].tag), modify(o << 1 | 1, node[o].tag), node[o].tag = 0;
    }
    void build(int o = 1, int l = 1, int r = n)
    {
        if (l == r)
        {
            node[o].sum = val[l];
            return;
        }

        int mid = (l + r) >> 1;
        build(o << 1, l, mid), build(o << 1 | 1, mid + 1, r);

        pushup(o);
    }
    void update(int ql, int qr, i64 v, int o = 1, int l = 1, int r = n)
    {
        if (ql <= l && r <= qr)
        {
            modify(o, v);
            return;
        }

        pushdown(o);

        int mid = (l + r) >> 1;
        if (mid >= ql)
        {
            update(ql, qr, v, o << 1, l, mid);
        }
        if (mid < qr)
        {
            update(ql, qr, v, o << 1 | 1, mid + 1, r);
        }

        pushup(o);
    }
    i64 query(int x, int o = 1, int l = 1, int r = n)
    {
        if (l == r)
        {
            return node[o].sum;
        }

        pushdown(o);

        int mid = (l + r) >> 1;
        if (x <= mid)
        {
            return query(x, o << 1, l, mid);
        }
        else
        {
            return query(x, o << 1 | 1, mid + 1, r);
        }
    }

    int main()
    {
        read(n, m);
        readAll(a + 1, a + n + 1);

        for (int i = 1; i < n; i++)
        {
            int u = readi(), v = readi();
            e[u].push_back(v), e[v].push_back(u);
        }

        dfs(1, 0);

        for (int i = 1; i <= n; i++)
        {
            val[dfn[i]] = a[i] * b[i];
        }

        build();

        for (int i = 1; i <= m; i++)
        {
            int op = readi();
            if (op == 1)
            {
                int x = readi(), v = readi() * b[x];
                update(dfn[x], end[x], v);
            }
            if (op == 2)
            {
                int x = readi();
                write(query(dfn[x]) * b[x]);
            }
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}