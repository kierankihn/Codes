/**
 * @author Kieran Kihn
 * @date 2024.07.01
 * @name P6521 [CEOI2010 day2] pin
 * @link https://www.luogu.com.cn/problem/P6521
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

    constexpr int MAXC = 36 + 5;
    constexpr int MAXN = 5e4 + 5;

    int n, d;

    i64 ans = 0;

    char s[MAXN][MAXC];

    i64 s1[4][MAXC], s2[4][4][MAXC][MAXC], s3[4][4][4][MAXC][MAXC][MAXC];

    int encode(char x)
    {
        if (std::isdigit(x))
        {
            return x - '0';
        }
        return x - 'a' + 10;
    }

    int main()
    {
        read(n, d);

        d = 4 - d;

        for (int i = 1; i <= n; i++)
        {
            read(s[i]);
            for (int j = 0; j < 4; j++)
            {
                s1[j][encode(s[i][j])]++;
                for (int k = j + 1; k < 4; k++)
                {
                    s2[j][k][encode(s[i][j])][encode(s[i][k])]++;
                    for (int p = k + 1; p < 4; p++)
                    {
                        s3[j][k][p][encode(s[i][j])][encode(s[i][k])][encode(s[i][p])]++;
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            i64 sum0 = n - 1, sum1 = 0, sum2 = 0, sum3 = 0;
            for (int j = 0; j < 4; j++)
            {
                sum1 += s1[j][encode(s[i][j])] - 1;
                for (int k = j + 1; k < 4; k++)
                {
                    sum2 += s2[j][k][encode(s[i][j])][encode(s[i][k])] - 1;
                    for (int p = k + 1; p < 4; p++)
                    {
                        sum3 += s3[j][k][p][encode(s[i][j])][encode(s[i][k])][encode(s[i][p])] - 1;
                    }
                }
            }

            if (d == 0)
            {
                ans += sum0 - sum1 + sum2 - sum3;
            }
            if (d == 1)
            {
                ans += sum1 - sum2 * 2 + sum3 * 3;
            }
            if (d == 2)
            {
                ans += sum2 - 3 * sum3;
            }
            if (d == 3)
            {
                ans += sum3;
            }
        }

        write(ans / 2);

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}