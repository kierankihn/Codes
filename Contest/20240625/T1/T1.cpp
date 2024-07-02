/**
 * @author Kieran Kihn
 * @date 2024.06.25
 * @name T1
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
    typedef std::pair<std::pair<int, int>, int> p3i;

    constexpr int MAXN = 1e6 + 5;

    int n, q;
    int a[MAXN];

    int used[MAXN];

    int ans[MAXN];

    std::vector<p3i> qs[MAXN];

    std::vector<int> pos[MAXN];

    struct Node
    {
        int max;
    };
    Node operator+(const Node &a, const Node &b)
    {
        return {std::max(a.max, b.max)};
    }

    Node node[MAXN << 2];
    void update(int x, int v, int o = 1, int l = 1, int r = n)
    {
        if (l == r)
        {
            node[o].max = v;
            return;
        }

        int mid = (l + r) >> 1;
        if (x <= mid)
        {
            update(x, v, o << 1, l, mid);
        }
        if (x > mid)
        {
            update(x, v, o << 1 | 1, mid + 1, r);
        }

        node[o] = node[o << 1] + node[o << 1 | 1];
    }
    int query(int ql, int qr, int o = 1, int l = 1, int r = n)
    {
        if (ql <= l && r <= qr)
        {
            return node[o].max;
        }

        int mid = (l + r) >> 1;
        if (mid >= ql && mid < qr)
        {
            return std::max(query(ql, qr, o << 1, l, mid), query(ql, qr, o << 1 | 1, mid + 1, r));
        }
        if (mid >= ql)
        {
            return query(ql, qr, o << 1, l, mid);
        }
        if (mid < qr)
        {
            return query(ql, qr, o << 1 | 1, mid + 1, r);
        }

        return 0;
    }

    int sum[MAXN];
    int lowbit(int x)
    {
        return x & (-x);
    }
    void update_bit(int x, int v)
    {
        while (x <= n)
        {
            sum[x] += v, x += lowbit(x);
        }
    }
    int query_bit(int x)
    {
        int res = 0;
        while (x)
        {
            res += sum[x], x -= lowbit(x);
        }
        return res;
    }

    int main()
    {
        read(n, q);
        for (int i = 1; i <= n; i++)
        {
            pos[a[i] = readi()].push_back(i), used[a[i]] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            used[i] += used[i - 1];
        }
        for (int i = 1; i <= q; i++)
        {
            int l = readi(), r = readi();
            ans[i] = used[r] - used[l - 1];
            qs[l - 1].push_back({{l, -1}, i}), qs[r].push_back({{l, 1}, i});
        }

        for (int i = 1; i <= n; i++)
        {
            for (int prev = 0, next = 1; next < pos[i].size(); prev++, next++)
            {
                int max = query(pos[i][prev], pos[i][next]);
                if (max != 0)
                {
                    update_bit(max, 1);
                }
            }
            for (auto p : pos[i])
            {
                update(p, i);
            }

            for (auto qnow : qs[i])
            {
                ans[qnow.second] += qnow.first.second * (query_bit(n) - query_bit(qnow.first.first - 1));
            }
        }

        for (int i = 1; i <= q; i++)
        {
            write(ans[i]);
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}