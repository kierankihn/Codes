/**
 * @author Kieran Kihn
 * @date 2024.07.02
 * @name P7219 [JOISC2020] 星座 3
 * @link https://www.luogu.com.cn/problem/P7219
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
    typedef std::pair<int, i64> pii;

    constexpr int MAXN = 2e5 + 5;

    int n, m;
    int a[MAXN];

    i64 sum = 0;

    int son[MAXN][2];

    std::vector<pii> star[MAXN];

    struct Node
    {
        i64 max, tag;
        int lson, rson;
    };

    int size;
    int root[MAXN];
    Node node[MAXN * 40];

    void pushup(int o)
    {
        node[o].max = std::max(node[node[o].lson].max, node[node[o].rson].max);
    }
    void modify(int o, i64 v)
    {
        if (o == 0)
        {
            return;
        }
        node[o].max += v, node[o].tag += v;
    }
    void pushdown(int o)
    {
        modify(node[o].lson, node[o].tag);
        modify(node[o].rson, node[o].tag);
        node[o].tag = 0;
    }
    void update(int x, i64 v, int &o, int l = 1, int r = n)
    {
        if (o == 0)
        {
            o = ++size;
        }
        if (l == r)
        {
            return modify(o, v);
        }

        pushdown(o);

        int mid = (l + r) >> 1;
        if (x <= mid)
        {
            update(x, v, node[o].lson, l, mid);
        }
        else
        {
            update(x, v, node[o].rson, mid + 1, r);
        }

        pushup(o);
    }
    i64 query(int ql, int qr, int o, int l = 1, int r = n)
    {
        if (o == 0 || l > qr || r < ql || ql > qr)
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
    void merge(int &x, int y, i64 limit, i64 maxx = 0, i64 maxy = 0, int l = 1, int r = n)
    {
        if (x == 0 && y == 0)
        {
            return;
        }
        if (x != 0 && y == 0)
        {
            return modify(x, maxy);
        }
        if (x == 0 && y != 0)
        {
            x = y;
            return modify(y, maxx);
        }
        if (l == r)
        {
            maxx = std::max(maxx, query(1, limit, x, l, r));
            maxy = std::max(maxy, query(1, limit, y, l, r));
            node[x].max = std::max(node[x].max + maxy, node[y].max + maxx);
            return;
        }

        pushdown(x), pushdown(y);

        int mid = (l + r) >> 1;

        i64 maxx_l = query(1, limit, node[x].lson, l, mid), maxy_l = query(1, limit, node[y].lson, l, mid);

        merge(node[x].lson, node[y].lson, limit, maxx, maxy, l, mid);
        merge(node[x].rson, node[y].rson, limit, std::max(maxx, maxx_l), std::max(maxy, maxy_l), mid + 1, r);

        pushup(x);
    }
    void solve(int u)
    {
        for (auto i : star[u])
        {
            update(i.first, i.second, root[u]);
        }
        for (auto v : son[u])
        {
            if (v != 0)
            {
                solve(v);
                merge(root[u], root[v], a[u]);
            }
        }
    }

    void build()
    {
        std::stack<int> s;
        a[0] = n + 1, s.push(0);
        for (int i = 1; i <= n; i++)
        {
            while (a[s.top()] <= a[i])
            {
                son[i][0] = s.top(), s.pop();
            }
            son[s.top()][1] = i;
            s.push(i);
        }
    }

    int main()
    {
        read(n);
        for (int i = 1; i <= n; i++)
        {
            read(a[i]);
        }

        read(m);
        for (int i = 1; i <= m; i++)
        {
            int x = readi(), y = readi(), c = readi();
            sum += c, star[x].push_back({y, c});
        }

        build();
        solve(son[0][1]);

        write(sum - node[root[son[0][1]]].max);

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}