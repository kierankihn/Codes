/**
 * @author Kieran Kihn
 * @date 2024.07.16
 * @name D
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

    constexpr int MAXN    = 1e6 + 5;
    constexpr int MAXLOGN = 20 + 1;

    int n, m;

    std::vector<i64> a[MAXN];

    i64 ans[MAXN], max[MAXN];

    int st[MAXN][MAXLOGN];
    void build(std::vector<i64> &x)
    {
        int size = x.size();
        for (int i = 1; i <= size; i++)
        {
            st[i][0] = x[i - 1];
        }
        for (int i = 1; i <= std::__lg(size); i++)
        {
            for (int j = 1; j + (1 << i) - 1 <= size; j++)
            {
                st[j][i] = std::max(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
            }
        }
    }
    int query(int l, int r)
    {
        int k = std::__lg(r - l + 1);
        return std::max(st[l][k], st[r - (1 << k) + 1][k]);
    }

    struct Node
    {
        i64 max, tag;
    };
    Node operator+(const Node &a, const Node &b)
    {
        return {std::max(a.max, b.max), 0};
    }

    i64 b[MAXN];
    Node node[MAXN << 2];
    void modify(int o, i64 v)
    {
        node[o].max += v, node[o].tag += v;
    }
    void pushup(int o)
    {
        node[o] = node[o << 1] + node[o << 1 | 1];
    }
    void pushdown(int o)
    {
        modify(o << 1, node[o].tag), modify(o << 1 | 1, node[o].tag);
    }
    void build(int o = 1, int l = 1, int r = m)
    {
        if (l == r)
        {
            node[o].max = b[l];
            return;
        }

        int mid = (l + r) >> 1;
        build(o << 1, l, mid), build(o << 1 | 1, mid + 1, r);

        pushup(o);
    }
    void update(int ql, int qr, i64 v, int o = 1, int l = 1, int r = m)
    {
        if (ql > qr)
        {
            return;
        }
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
    void solve(int o = 1, int l = 1, int r = m)
    {
        if (l == r)
        {
            ans[l] = node[o].max;
            return;
        }

        pushdown(o);

        int mid = (l + r) >> 1;
        solve(o << 1, l, mid), solve(o << 1 | 1, mid + 1, r);
    }

    int main()
    {
        read(n, m);
        for (int i = 1; i <= n; i++)
        {
            int size = readi();
            for (int j = 1; j <= size; j++)
            {
                a[i].push_back(readi());
            }
        }

        for (int i = 1; i <= n; i++)
        {
            build(a[i]);

            i64 size = a[i].size();

            for (int j = 1; j <= size; j++)
            {
                i64 pos = j;
                int l = std::max(1LL, size - (m - pos)), r = std::min(pos, 1LL * size);

                int v = query(l, r);
                if (size - (m - pos) < 1 || pos > size)
                {
                    v = std::max(v, 0);
                }

                b[pos] += v;
            }
            for (int j = 1; j <= size; j++)
            {
                i64 pos = m - j + 1;
                if (pos <= size)
                {
                    break;
                }

                int l = std::max(1LL, size - (m - pos)), r = std::min(pos, size);

                int v = query(l, r);
                if (size - (m - pos) < 1 || pos > size)
                {
                    v = std::max(v, 0);
                }

                b[pos] += v;
            }

            for (auto j : a[i])
            {
                max[i] = std::max(max[i], j);
            }
        }

        build();

        for (int i = 1; i <= n; i++)
        {
            int len = a[i].size();
            update(len + 1, m - len, max[i]);
        }

        solve();

        writeAll(ans + 1, ans + m + 1);

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}