/**
 * @author Kieran Kihn
 * @date 2024.09.15
 * @name traversing
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

    constexpr int MAXN = 1e5 + 5;

    int n, q;
    int a[MAXN], dfn[MAXN], val[MAXN], sum[MAXN];

    int lson[MAXN], rson[MAXN], left[MAXN], right[MAXN];

    int size = 0;
    void dfs(int u)
    {
        if (u == 0)
        {
            return;
        }

        dfn[u] = left[u] = ++size, sum[u] = 1;
        dfs(lson[u]), dfs(rson[u]);
        right[u] = size, sum[u] += sum[lson[u]] + sum[rson[u]], val[dfn[u]] = dfn[u];
    }

    struct Node
    {
        int val, tag;
    };
    Node operator+(const Node &a, const Node &b)
    {
        return {a.val + b.val, 0};
    }

    Node node[MAXN << 2];
    void modify(int o, int v)
    {
        node[o].val += v, node[o].tag += v;
    }
    void pushdown(int o)
    {
        modify(o << 1, node[o].tag), modify(o << 1 | 1, node[o].tag), node[o].tag = 0;
    }
    void build(int o = 1, int l = 1, int r = n)
    {
        if (l == r)
        {
            node[o] = {val[l], 0};
            return;
        }

        int mid = (l + r) >> 1;
        build(o << 1, l, mid), build(o << 1 | 1, mid + 1, r);

        node[o] = node[o << 1] + node[o << 1 | 1];
    }
    void update(int ql, int qr, int v, int o = 1, int l = 1, int r = n)
    {
        if (ql > qr || ql <= 0 || qr <= 0)
        {
            return;
        }
        if (ql <= l && r <= qr)
        {
            node[o].val += v, node[o].tag += v;
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

        node[o] = node[o << 1] + node[o << 1 | 1];
    }
    int query(int ql, int qr, int o = 1, int l = 1, int r = n)
    {
        if (ql <= l && r <= qr)
        {
            return node[o].val;
        }

        pushdown(o);

        int mid = (l + r) >> 1;
        if (mid >= qr)
        {
            return query(ql, qr, o << 1, l, mid);
        }
        if (mid < ql)
        {
            return query(ql, qr, o << 1 | 1, mid + 1, r);
        }

        return query(ql, qr, o << 1, l, mid) + query(ql, qr, o << 1 | 1, mid + 1, r);
    }

    void upd(int u, int x, int v)
    {
        if (x == -1)
        {
            update(left[u] + 1, right[u], v);
        }
        if (x == 0)
        {
            update(left[rson[u]], right[rson[u]], v);
        }
        if (x == 1)
        {
            update(x, x, v * (sum[lson[u]] + sum[rson[u]]));
        }
    }

    int main()
    {
        freopen("traversing.in", "r", stdin);
        freopen("traversing.out", "w", stdout);

        read(n, q);
        for (int i = 1; i <= n; i++)
        {
            a[i] = -1;
            read(lson[i], rson[i]);
        }

        dfs(1), build();

        for (int i = 1; i <= q; i++)
        {
            int op = readi();
            if (op == 1)
            {
                int l = readi(), r = readi(), x = readi();
                for (int j = l; j <= r; j++)
                {
                    upd(j, a[j], -1);
                    upd(j, a[j] = x, 1);
                }
            }
            if (op == 2)
            {
                int x = readi();
                write(query(dfn[x], dfn[x]));
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