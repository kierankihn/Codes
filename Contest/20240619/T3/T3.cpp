/**
 * @author Kieran Kihn
 * @date 2024.06.19
 * @name T3
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

    constexpr int MAXN = 2e5 + 5;

    int n;
    int a[MAXN];

    i64 ans = 0;

    int pos[MAXN];

    int prev[MAXN], next[MAXN];

    std::stack<int> s;

    void clear(std::stack<int> &x)
    {
        while (x.empty() == false)
        {
            x.pop();
        }
    }

    int main()
    {
        read(n);
        readAll(a + 1, a + n + 1);

        for (int i = 1; i <= n; i++)
        {
            pos[a[i]] = i;
        }

        clear(s);
        for (int i = 1; i <= n; i++)
        {
            while (s.empty() == false && a[s.top()] < a[i])
            {
                s.pop();
            }

            prev[i] = s.empty() ? 0 : s.top();

            s.push(i);
        }
        clear(s);
        for (int i = n; i >= 1; i--)
        {
            while (s.empty() == false && a[s.top()] < a[i])
            {
                s.pop();
            }

            next[i] = s.empty() ? n + 1 : s.top();

            s.push(i);
        }

        for (int i = 1; i <= n; i++)
        {
            if (i - prev[i] - 1 <= next[i] - i - 1)
            {
                for (int j = prev[i] + 1; j < i; j++)
                {
                    if (i < pos[a[i] - a[j]] && pos[a[i] - a[j]] < next[i])
                    {
                        ans++;
                    }
                }
            }
            else
            {
                for (int j = i + 1; j < next[i]; j++)
                {
                    if (prev[i] < pos[a[i] - a[j]] && pos[a[i] - a[j]] < i)
                    {
                        ans++;
                    }
                }
            }
        }

        write(ans);

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}