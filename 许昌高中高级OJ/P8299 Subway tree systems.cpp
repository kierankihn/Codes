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

    int t;

    std::string solve(std::string x)
    {
        std::string res;
        std::size_t prev = 0;
        int sum0 = 0, sum1 = 0;
        std::vector<std::string> s;

        for (std::size_t i = 0; i != x.size(); i++)
        {
            if (x[i] == '0')
            {
                sum0++;
            }
            if (x[i] == '1')
            {
                sum1++;
            }

            if (sum0 == sum1)
            {
                s.push_back('0' + solve(x.substr(prev + 1, i - prev - 1)) + '1'), prev = i + 1;
            }
        }

        std::sort(s.begin(), s.end());

        for (auto i : s)
        {
            res += i;
        }

        return res;
    }

    int main()
    {
        read(t);
        while (t--)
        {
            std::string a, b;
            read(a, b);
            if (solve(a) == solve(b))
            {
                write("same");
            }
            else
            {
                write("different");
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