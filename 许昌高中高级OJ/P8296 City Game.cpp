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
    }
}  // namespace IO
namespace solution
{
    using namespace IO;
    typedef char chr;
    typedef long long i64;
    typedef std::pair<int, int> pii;

    const int MAXN = 1e3 + 5;

    int n, m;
    chr a[MAXN][MAXN];
    int max[MAXN][MAXN];

    int ans = 0;

    chr readChar()
    {
        chr res = getchar();
        while (std::islower(res) == false && std::isupper(res) == false)
        {
            res = getchar();
        }
        return res;
    }

    int main()
    {
        read(n, m);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                a[i][j] = readChar();
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j] == 'F')
                {
                    max[i][j] = max[i - 1][j] + 1;
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            std::stack<pii> s;
            for (int j = 1; j <= m + 1; j++)
            {
                int len = 0;
                while (s.empty() == false && s.top().first > max[i][j])
                {
                    len += s.top().second;
                    ans = std::max(ans, s.top().first * len);
                    s.pop();
                }
                s.push({max[i][j], ++len});
            }
        }

        write(ans * 3);

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}