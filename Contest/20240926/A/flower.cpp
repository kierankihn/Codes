/**
 * @author Kieran Kihn
 * @date 2024.09.26
 * @name flower
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
    } // namespace basic_IO
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
} // namespace IO
namespace solution
{
    using namespace IO;
    typedef long long i64;

    constexpr int B    = 1e3;
    constexpr int N    = 1e5;
    constexpr int MAXS = 1e2 + 5;
    constexpr int MAXN = 1e5 + 5;

    int n, q;
    int a[MAXN];

    int s;
    int b[MAXN];
    int max[MAXN][MAXS];
    void build()
    {
        s = (n - 1) / B + 1;
        for (int i = 1; i <= s; i++)
        {
            int l = B * (i - 1) + 1, r = std::min(B * i, n);

            std::fill(b, b + N + 1, 0);
            for (int j = l; j <= r; j++)
            {
                b[a[j]] = a[j];
            }
            for (int j = 1; j <= N; j++)
            {
                b[j] = std::max(b[j], b[j - 1]);
            }
            for (int k = 1; k <= N; k++)
            {
                for (int jl = 0, jr = k - 1; jl <= N; jl += k, jr += k)
                {
                    max[k][i] = std::max(max[k][i], b[std::min(jr, N)] % k);
                }
            }
        }
    }
    int solve(int l, int r, int k)
    {
        int lid = (l - 1) / B + 1, rid = (r - 1) / B + 1;

        int res = 0;
        for (int i = l; i <= std::min(B * lid, r); i++)
        {
            res = std::max(res, a[i] % k);
        }
        for (int i = std::max(l, B * (rid - 1) + 1); i <= r; i++)
        {
            res = std::max(res, a[i] % k);
        }

        for (int i = lid + 1; i < rid; i++)
        {
            res = std::max(res, max[k][i]);
        }

        return res;
    }

    int main()
    {
        std::freopen("flower.in", "r", stdin);
        std::freopen("flower.out", "w", stdout);

        read(n, q);
        readAll(a + 1, a + n + 1);

        build();

        for (int i = 1; i <= q; i++)
        {
            int l = readi(), r = readi(), k = readi();

            write(solve(l, r, k));
        }

        return 0;
    }
} // namespace solution
int main()
{
    solution::main();
    return 0;
}