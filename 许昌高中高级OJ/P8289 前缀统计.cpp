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
    typedef long long i64;

    const int MAXN = 1e5 + 5;
    const int MAXP = 1e6 + 5;
    const int MAXC = 26;

    int n, q;
    std::string s[MAXN], t;

    int cnt = 1;
    int son[MAXP][MAXC], isend[MAXP];

    void add(std::string x)
    {
        auto u = 1;
        for (auto c : x)
        {
            u = (son[u][c - 'a'] == 0) ? (son[u][c - 'a'] = ++cnt) : (son[u][c - 'a']);
        }
        isend[u]++;
    }
    int query(std::string x)
    {
        auto u = 1, res = 0;
        for (auto c : x)
        {
            res += isend[u = son[u][c - 'a']];
        }
        return res;
    }

    int main()
    {
        read(n, q);
        for (int i = 1; i <= n; i++)
        {
            std::cin >> s[i], add(s[i]);
        }

        for (int i = 1; i <= q; i++)
        {
            std::cin >> t;
            write(query(t));
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}