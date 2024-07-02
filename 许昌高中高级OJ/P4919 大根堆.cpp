/**
 * @author Kieran Kihn
 * @date 2024.07.02
 * @name P4919 大根堆
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

    constexpr int V    = 1e9;
    constexpr int MAXN = 2e5 + 5;

    int n;
    int a[MAXN];

    std::vector<int> e[MAXN];

    struct Node
    {
        int max, tag;
        int lson, rson;
    };

    int size;
    int root[MAXN];
    Node node[MAXN * 40];
    void modify(int o, int v)
    {
        if (o == 0)
        {
            return;
        }
        node[o].max += v;
        node[o].tag += v;
    }
    void pushup(int o)
    {
        node[o].max = std::max(node[node[o].lson].max, node[node[o].rson].max);
    }
    void pushdown(int o)
    {
        if (o == 0)
        {
            return;
        }
        modify(node[o].lson, node[o].tag);
        modify(node[o].rson, node[o].tag);
        node[o].tag = 0;
    }
    void update(int x, int v, int &o, int l = 0, int r = V)
    {
        if (o == 0)
        {
            o = ++size;
        }
        if (l == r)
        {
            node[o].max += v;
            return;
        }

        pushdown(o);

        int mid = (l + r) >> 1;
        if (mid >= x)
        {
            update(x, v, node[o].lson, l, mid);
        }
        if (mid < x)
        {
            update(x, v, node[o].rson, mid + 1, r);
        }

        pushup(o);
    }
    void update_max(int x, int v, int &o, int l = 0, int r = V)
    {
        if (o == 0)
        {
            o = ++size;
        }
        if (l == r)
        {
            node[o].max = std::max(node[o].max, v);
            return;
        }

        pushdown(o);

        int mid = (l + r) >> 1;
        if (mid >= x)
        {
            update_max(x, v, node[o].lson, l, mid);
        }
        if (mid < x)
        {
            update_max(x, v, node[o].rson, mid + 1, r);
        }

        pushup(o);
    }
    int query(int ql, int qr, int o, int l = 0, int r = V)
    {
        if (o == 0 || ql > qr)
        {
            return 0;
        }
        if (ql <= l && r <= qr)
        {
            return node[o].max;
        }

        pushdown(o);

        int mid = (l + r) >> 1;
        if (mid >= ql && mid < qr)
        {
            return std::max(query(ql, qr, node[o].lson, l, mid), query(ql, qr, node[o].rson, mid + 1, r));
        }
        if (mid >= ql)
        {
            return query(ql, qr, node[o].lson, l, mid);
        }
        if (mid < qr)
        {
            return query(ql, qr, node[o].rson, mid + 1, r);
        }

        return 0;
    }
    void merge(int &x, int y, int maxx = 0, int maxy = 0, int l = 0, int r = V)
    {
        if (x == 0 && y == 0)
        {
            return;
        }
        if (x == 0 && y != 0)
        {
            x = y;
            return modify(y, maxx);
        }
        if (x != 0 && y == 0)
        {
            return modify(x, maxy);
        }
        if (l == r)
        {
            node[x].max = std::max(node[x].max, maxx) + std::max(node[y].max, maxy);
            return;
        }

        pushdown(x), pushdown(y);

        int mid = (l + r) >> 1;

        int maxx_l = node[node[x].lson].max, maxy_l = node[node[y].lson].max;

        merge(node[x].lson, node[y].lson, maxx, maxy, l, mid);
        merge(node[x].rson, node[y].rson, std::max(maxx, maxx_l), std::max(maxy, maxy_l), mid + 1, r);

        pushup(x);
    }
    void solve(int u)
    {
        for (auto v : e[u])
        {
            solve(v);
            merge(root[u], root[v]);
        }

        update_max(a[u], query(0, a[u] - 1, root[u]) + 1, root[u]);
    }

    int main()
    {
        read(n);
        for (int i = 1; i <= n; i++)
        {
            read(a[i]);
            e[readi()].push_back(i);
        }

        solve(1);

        write(node[root[1]].max);

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}