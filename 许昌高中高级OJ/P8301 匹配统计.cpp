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
            basic_IO::__write(*i);
        }
        putchar('\n');
    }
}  // namespace IO
namespace solution
{
    using namespace IO;
    typedef long long i64;

    const int MAXN = 2e5 + 5;

    int n, m, q;
    int ans[MAXN];
    std::string a, b;

    int fail[MAXN], cmp[MAXN];
    void kmp(std::string a, std::string b)
    {
        for (std::size_t i = 1; i != b.size(); i++)
        {
            int j = fail[i - 1];
            while (j != 0 && b[i] != b[j])
            {
                j = fail[j - 1];
            }
            fail[i] = j + (b[i] == b[j]);
        }

        ans[cmp[0] = (a[0] == b[0])]++;
        for (std::size_t i = 1; i != a.size(); i++)
        {
            int j = cmp[i - 1];
            while (j != 0 && a[i] != b[j])
            {
                j = fail[j - 1];
            }
            ans[cmp[i] = (j + (a[i] == b[j]))]++;
        }

        for (std::size_t i = b.size(); i >= 1; i--)
        {
            ans[fail[i - 1]] += ans[i];
        }
    }

    int main()
    {
        read(n, m, q, a, b);

        kmp(a, b);

        for (int i = 1; i <= q; i++)
        {
            int x;
            read(x), write(ans[x] - ans[x + 1]);
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}