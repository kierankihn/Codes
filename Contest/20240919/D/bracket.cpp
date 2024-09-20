/**
 * @author Kieran Kihn
 * @date 2024.09.19
 * @name bracket
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

    constexpr int MAXN = 1e6 + 5;

    int t;

    int n;
    int a[MAXN];
    int b[MAXN], c[MAXN];

    int ans = 0;

    bool calc(int *x)
    {
        int size = x[0];
        std::stack<int> s;
        for (int i = 1; i <= size; i++)
        {
            if (s.empty() || s.top() != x[i])
            {
                s.push(x[i]);
            }
            else
            {
                s.pop();
            }
        }

        return s.empty();
    }

    bool check(int x)
    {
        b[0] = 0, c[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            if (x & (1 << (i - 1)))
            {
                b[++b[0]] = a[i];
            }
            else
            {
                c[++c[0]] = a[i];
            }
        }

        return calc(b) && calc(c);
    }

    int main()
    {
        read(t);
        while (t--)
        {
            ans = -1;

            read(n), n *= 2;
            readAll(a + 1, a + n + 1);

            for (int umask = 0; umask < (1 << n); umask++)
            {
                if (check(umask))
                {
                    ans = umask;
                    break;
                }
            }

            if (ans == -1)
            {
                write(-1);
            }
            else
            {
                for (int i = 1; i <= n; i++)
                {
                    putchar((ans & (1 << (i - 1))) ? '1' : '2');
                }
                putchar('\n');
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