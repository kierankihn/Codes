#include <bits/stdc++.h>
namespace IO
{
    namespace basic_IO
    {
        template <typename T>
        void __read(T &x)
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
        template <typename First, typename... Rest>
        void __read(First &first, Rest &...rest)
        {
            __read(first);
            __read(rest...);
        }
        template <typename T>
        void __write(T x)
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
        template <typename First, typename... Rest>
        void __write(First &first, Rest &...rest)
        {
            __write(first), std::putchar(' '), __write(rest...);
        }
    }
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
    void write(First &first, Rest &...rest)
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
    }
}
namespace solution
{
    using namespace IO;
    typedef long long i64;
    typedef std::map<int, int> mii;
    typedef std::pair<std::pair<int, int>, int> piii;
    const int MAXN = 2e5 + 5;
    int n, m;
    int a[MAXN], b[MAXN], c[MAXN];
    mii lang;
    piii ans;
    int main()
    {
        read(n);
        for (int i = 1; i <= n; i++)
        {
            read(a[i]);
            lang[a[i]]++;
        }
        read(m);
        readAll(b + 1, b + m + 1);
        readAll(c + 1, c + m + 1);
        for (int i = 1; i <= m; i++)
        {
            ans = std::max(ans, {{lang[b[i]], lang[c[i]]}, i});
        }
        write(ans.second);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}