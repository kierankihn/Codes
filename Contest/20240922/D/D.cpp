/**
 * @author Kieran Kihn
 * @date 2024.09.22
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
    typedef __int128 i128;

    constexpr int MAXN = 1e6 + 5;

    std::mt19937 rand(std::time(nullptr));

    int t;

    int n, q;
    i64 a[MAXN];

    i128 val[MAXN];
    i128 sum[5][MAXN];

    struct Node
    {
        int sum = 0;
        int lson, rson;
    };

    int size, root[MAXN];
    Node node[MAXN * 20];
    void pushup(int o)
    {
        node[o].sum = node[node[o].lson].sum + node[node[o].rson].sum;
    }
    void update(int x, int v, int &o, int l = 1, int r = MAXN)
    {
        size++, node[size] = node[o], o = size;
        if (l == r)
        {
            node[o].sum += v;
            return;
        }

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
    int query(int ql, int qr, int o, int l = 1, int r = MAXN)
    {
        if (o == 0)
        {
            return 0;
        }
        if (ql <= l && r <= qr)
        {
            return node[o].sum;
        }

        int mid = (l + r) >> 1;
        if (qr <= mid)
        {
            return query(ql, qr, node[o].lson, l, mid);
        }
        if (ql > mid)
        {
            return query(ql, qr, node[o].rson, mid + 1, r);
        }

        return query(ql, qr, node[o].lson, l, mid) + query(ql, qr, node[o].rson, mid + 1, r);
    }

    int main()
    {
        std::freopen("similar.in", "r", stdin);
        std::freopen("similar.out", "w", stdout);

        read(n, q);
        readAll(a + 1, a + n + 1);

        for (int i = 1; i <= 1e5; i++)
        {
            val[i] = val[i - 1] + rand() % 10 + 1;
        }

        for (int i = 1; i <= n; i++)
        {
            a[i] = val[a[i]];

            sum[1][i] = sum[1][i - 1] + i128(1) * a[i];
            sum[2][i] = sum[2][i - 1] + i128(1) * a[i] * a[i];
            sum[3][i] = sum[3][i - 1] + i128(1) * a[i] * a[i] * a[i];

            update(a[i], 1, root[i] = root[i - 1]);
        }

        for (int i = 1; i <= q; i++)
        {
            int l1 = readi(), r1 = readi(), l2 = readi(), r2 = readi();

            i128 x = sum[1][r1] - sum[1][l1 - 1] - (sum[1][r2] - sum[1][l2 - 1]);
            i128 y = sum[2][r1] - sum[2][l1 - 1] - (sum[2][r2] - sum[2][l2 - 1]);

            if (x == 0)
            {
                if (y == 0 && sum[3][r1] - sum[3][l1 - 1] - (sum[3][r2] - sum[3][l2 - 1]) == 0)
                {
                    write("YES");
                }
                else
                {
                    write("NO");
                }
            }
            else
            {
                i128 va = (y + x * x) / 2 / x, vb = (y - x * x) / 2 / x;

                if (va * va * va - vb * vb * vb == sum[3][r1] - sum[3][l1 - 1] - (sum[3][r2] - sum[3][l2 - 1]) && query(1, va, root[r1]) - query(1, va, root[l1 - 1]) == query(1, vb, root[r2]) - query(1, vb, root[l2 - 1]))
                {
                    write("YES");
                }
                else
                {
                    write("NO");
                }
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