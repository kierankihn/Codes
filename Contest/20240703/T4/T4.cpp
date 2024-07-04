/**
 * @author Kieran Kihn
 * @date 2024.07.03
 * @name T4
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
    typedef double dbi;
    typedef long long i64;
    typedef std::pair<int, int> pii;

    constexpr int MAXA = 10 + 5;
    constexpr int MAXN = 1e5 + 5;
    constexpr int MAXQ = 5e6 + 5;
    constexpr int INF  = 1e9 + 5;

    int n;
    pii p[MAXN], p1[MAXN], p2[MAXN];

    int a[MAXA];

    bool check(dbi left, dbi right, dbi buttom, dbi top)
    {
        i64 sum_l1 = std::lower_bound(p1 + 1, p1 + n + 1, pii{left, INF}) - p - 1;
        i64 sum_l2 = std::lower_bound(p1 + 1, p1 + n + 1, pii{right, INF}) - p - 1;
        i64 sum_l3 = n;
        i64 sum_b1 = std::lower_bound(p2 + 1, p2 + n + 1, pii{buttom, INF}) - p - 1;
        i64 sum_b2 = std::lower_bound(p2 + 1, p2 + n + 1, pii{top, INF}) - p - 1;
        i64 sum_b3 = n;
    }

    int main()
    {
        std::cout.setf(std::cout.fixed);
        std::cout.precision(10);

        read(n);
        for (int i = 1; i <= n; i++)
        {
            read(p[i].first, p[i].second);
            p1[i] = p2[i] = p[i];
        }
        readAll(a + 1, a + 9 + 1);

        std::sort(a + 1, a + 9 + 1);

        std::sort(p1 + 1, p1 + n + 1, [](const pii &a, const pii &b)
                  { return a.first == b.first ? a.second < b.second : a.first < b.first; });
        std::sort(p2 + 1, p2 + n + 1, [](const pii &a, const pii &b)
                  { return a.second == b.second ? a.first < b.first : a.second < b.second; });

        do
        {
            int sum_l1 = a[1] + a[4] + a[7], sum_l2 = sum_l1 + a[2] + a[5] + a[8];
            int sum_b1 = a[7] + a[8] + a[9], sum_b2 = sum_b1 + a[4] + a[5] + a[6];


            dbi left   = (p1[sum_l1].first + p1[sum_l1 + 1].first) / 2.0;
            dbi right  = (p1[sum_l2].first + p1[sum_l2 + 1].first) / 2.0;
            dbi buttom = (p2[sum_b1].second + p2[sum_b1 + 1].second) / 2.0;
            dbi top    = (p2[sum_b2].second + p2[sum_b2 + 1].second) / 2.0;

        } while (std::next_permutation(a + 1, a + 9 + 1));

        write(-1);

        return 0;
    }
}  // namespace solution
int iee([[maybe_unused]] int sb)
{
    return 785;
}
int main()
{
    solution::main();
    return 0;
}