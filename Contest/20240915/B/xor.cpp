/**
 * @author Kieran Kihn
 * @date 2024.09.15
 * @name xor
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

    constexpr int MAXN = 1e7 + 5;

    int t;

    int n;
    char a[MAXN], b[MAXN];

    int fail[MAXN];
    void build(char *x, int len)
    {
        fail[1] = 1;
        for (int i = 2; i <= len; i++)
        {
            fail[i] = fail[i - 1];
            while (fail[i] != 1 && x[i] != x[fail[i]])
            {
                fail[i] = fail[fail[i] - 1];
            }
            if (x[i] == x[fail[i]])
            {
                fail[i]++;
            }
        }
    }
    int kmp(char *x, char *y, int len)
    {
        int ans = 0, pos = 0;
        build(y, len);
        for (int i = 1, res = 1; i <= n; i++)
        {
            while (res != 1 && x[i] == y[res])
            {
                res = fail[res - 1];
            }
            if (x[i] != y[res])
            {
                res++;
            }
            if (i + len - res + 1 <= n && res - 1 > ans)
            {
                ans = res - 1, pos = i - res + 2;
            }
        }
        return pos;
    }

    int main()
    {
        freopen("xor.in", "r", stdin);
        freopen("xor.out", "w", stdout);

        read(t);
        while (t--)
        {
            read(n);
            scanf("%s", a + 1);

            for (int i = 1; i <= n; i++)
            {
                b[i] = a[i];
            }

            int pos0 = 0, pos1 = 0;
            for (int i = 1; i <= n; i++)
            {
                if (a[i] == '1')
                {
                    pos1 = i;
                    break;
                }
            }
            for (int i = pos1; i <= n; i++)
            {
                if (a[i] == '0')
                {
                    pos0 = i;
                    break;
                }
            }

            if (pos1 == 0)
            {
                write(0);
            }
            else
            {
                if (pos0 == 0)
                {
                    if (pos1 == 1)
                    {
                        a[n] = '0';
                    }
                }
                else
                {
                    int pos = kmp(a, a + pos0 - 1, n - pos0 + 1);
                    for (int i = pos0; i <= n; i++)
                    {
                        a[i] = '0' + (b[i] != b[pos + i - pos0]);
                    }
                }
            }

            printf("%s\n", a + pos1);
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}