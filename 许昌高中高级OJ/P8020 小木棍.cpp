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
            basic_IO::__write(*i), std::putchar(' ');
        }
        std::putchar('\n');
    }
}  // namespace IO
namespace solution
{
    using namespace IO;
    typedef long long i64;

    const int MAXN = 1e4 + 5;

    int n, sum = 0;
    int a[MAXN], next[MAXN];

    int cnt = 0, size = 0, vis[MAXN];
    bool dfs(int k, int len, int last)
    {
        if (k == cnt + 1)
        {
            return true;
        }
        if (len == size)
        {
            return dfs(k + 1, 0, 0);
        }

        for (int i = last + 1; i <= n; i = (vis[i] ? i + 1 : next[i]))
        {
            if (vis[i])
            {
                continue;
            }
            if (len + a[i] <= size)
            {
                vis[i] = true;
                if (dfs(k, len + a[i], i))
                {
                    return true;
                }
                vis[i] = false;
                if (len == 0 || len + a[i] == size)
                {
                    return false;
                }
            }
        }

        return false;
    }

    int main()
    {
        read(n);
        for (int i = 1; i <= n; i++)
        {
            read(a[i]);
            a[0] = std::max(a[0], a[i]), sum += a[i];
        }
        std::sort(a + 1, a + n + 1, std::greater<int>());
        for (int i = n; i >= 1; i--)
        {
            if (a[i] != a[i + 1])
            {
                next[i] = i + 1;
            }
            else
            {
                next[i] = next[i + 1];
            }
        }

        for (int i = a[0]; i <= sum; i++)
        {
            if (sum % i != 0)
            {
                continue;
            }
            size = i, cnt = sum / size;
            if (dfs(1, 0, 0))
            {
                write(size), std::exit(0);
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