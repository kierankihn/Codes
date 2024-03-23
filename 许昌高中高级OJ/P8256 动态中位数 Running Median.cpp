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
}
namespace solution
{
    using namespace IO;
    typedef long long i64;
    const int MAXN = 1e4 + 5;
    int t, id;
    int n;
    int cnt;
    int a[MAXN];
    std::multiset<int> l, r;
    void insert(int x)
    {
        if (l.empty() && r.empty())
        {
            l.insert(x);
        }
        else if (x <= *(--l.end()))
        {
            l.insert(x);
        }
        else
        {
            r.insert(x);
        }
        while (l.size() > r.size() + 1)
        {
            x = *(--l.end());
            l.erase(--l.end()), r.insert(x);
        }
        while (r.size() > l.size())
        {
            x = *r.begin();
            r.erase(r.begin()), l.insert(x);
        }
    }
    int main()
    {
        read(t);
        while (t--)
        {
            l.clear(), r.clear(), cnt = 0;
            read(id, n);
            readAll(a + 1, a + n + 1);
            write(id, (n + 1) / 2);
            for (int i = 1; i <= n; i++)
            {
                insert(a[i]);
                if (i & 1)
                {
                    basic_IO::__write(*(--l.end())), std::putchar(' ');
                    if (++cnt == 10)
                    {
                        cnt = 0, putchar('\n');
                    }
                }
            }
            if (cnt)
            {
                putchar('\n');
            }
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}