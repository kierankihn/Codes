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
    }
}  // namespace IO
namespace solution
{
    using namespace IO;
    typedef long long i64;

    const int MAXN = 1e4 + 5;

    i64 n, m;
    std::string s[MAXN];
    std::string c[MAXN];

    i64 lcm(i64 a, i64 b)
    {
        return a / std::__gcd(a, b) * b;
    }

    int fail[MAXN];
    int kmp(std::string x)
    {
        std::fill(fail, fail + x.size(), 0);

        for (std::size_t i = 1; i != x.size(); i++)
        {
            int j = fail[i - 1];
            while (x[i] != x[j] && j != 0)
            {
                j = fail[j - 1];
            }
            fail[i] = j + (x[i] == x[j]);
        }

        return x.size() - fail[x.size() - 1];
    }

    auto mks(int sz)
    {
        std::set<int> res;
        for (int i = 1; i <= sz; i++)
        {
            res.insert(i);
        }
        return res;
    }
    void add(int x, int sz, std::set<int> &st)
    {
        for (int i = 1; i <= sz; i++)
        {
            if (st.count(i) && (i % x == 0 || (i >= x && x * 2 > sz)) == false)
            {
                st.erase(i);
            }
        }
    }

    int main()
    {
        read(n, m);
        for (int i = 1; i <= n; i++)
        {
            read(s[i]);
            for (int j = 1; j <= m; j++)
            {
                c[j].push_back(s[i][j]);
            }
        }

        auto ln = mks(m), cl = mks(n);
        for (int i = 1; i <= n; i++)
        {
            add(kmp(s[i]), m, ln);
        }
        for (int i = 1; i <= m; i++)
        {
            add(kmp(c[i]), n, cl);
        }

        write((*ln.begin()) * (*cl.begin()));

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}