/**
 * @author Kieran Kihn
 * @date 2024.06.14
 * @name P2421 [NOI2002] 荒岛野人
 * @link https://www.luogu.com.cn/problem/P2421
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

    constexpr int MAXN = 1e2 + 5;
    constexpr int MAXM = 1e6 + 5;

    int n;
    int c[MAXN], p[MAXN], l[MAXN];

    i64 exgcd(i64 a, i64 b, i64 &x, i64 &y)
    {
        if (b == 0)
        {
            return x = 1, y = 0, a;
        }

        i64 x0 = 0, y0 = 0, gcd = exgcd(b, a % b, x0, y0);

        return x = y0, y = x0 - a / b * y0, gcd;
    }

    i64 mod(i64 x, i64 y)
    {
        return x %= y, x < 0 ? x + y : x;
    }

    int main()
    {
        read(n);
        for (int i = 1; i <= n; i++)
        {
            read(c[i], p[i], l[i]), c[i]--;
        }

        for (i64 m = *std::max_element(c + 1, c + n + 1) + 1; m < MAXM; m++)
        {
            bool flag = true;
            for (int i = 1; i <= n; i++)
            {
                for (int j = i + 1; j <= n; j++)
                {
                    i64 x, y, gcd = exgcd(mod(p[j] - p[i], m), m, x, y);

                    if (mod(c[i] - c[j], m) % gcd == 0)
                    {
                        x *= mod(c[i] - c[j], m) / gcd;

                        x = mod(x, m / gcd);

                        if (x <= std::min(l[i], l[j]))
                        {
                            flag = false;
                            break;
                        }
                    }
                }

                if (flag == false)
                {
                    break;
                }
            }

            if (flag)
            {
                write(m);
                break;
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

/**
 * 考虑 (i, j)
 *
 * 对于任意 k \in [0, \min{l_i, l_j}], 均有 (c + p_i * k) mod m != (c + p_j * k) mod m
 *
 * 或者考虑 是否存在 k \in [0, \min{l_i, l_j}], 使得 c_i + p_i * k === c_j + p_j * k (mod m) (1)
 *
 * (1) <=> c_i - c_j + x * (p_i - p_j) == y * m <=> -x * (p_i + p_j) + y * m == c_i - c_j
 */