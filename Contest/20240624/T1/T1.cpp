/**
 * @author Kieran Kihn
 * @date 2024.06.24
 * @name T1
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

    int n, q;

    int a[MAXN], b[MAXN];

    int suma[MAXN], sumb[MAXN];

    bool check[MAXN];

    void init()
    {
        std::set<int> seta, setb;

        std::set<int> xa, xb;

        for (int i = 1, j = 1; i <= n && j <= n; i++, j++)
        {
            while (seta.count(a[i]))
            {
                suma[i] = suma[i - 1], i++;
            }
            if (i > n)
            {
                break;
            }
            seta.insert(a[i]), suma[i] = suma[i - 1] + 1;
            if (xb.count(a[i]))
            {
                xb.erase(a[i]);
            }
            else
            {
                xa.insert(a[i]);
            }

            while (setb.count(b[j]))
            {
                sumb[j] = sumb[j - 1], j++;
            }
            if (j > n)
            {
                break;
            }
            setb.insert(b[j]), sumb[j] = sumb[j - 1] + 1;
            if (xa.count(b[j]))
            {
                xa.erase(b[j]);
            }
            else
            {
                xb.insert(b[j]);
            }

            if (suma[i] == sumb[j])
            {
                if (xa.empty() && xb.empty())
                {
                    check[suma[i]] = true;
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (suma[i] == 0)
            {
                seta.insert(a[i]), suma[i] = seta.size();
            }
            if (sumb[i] == 0)
            {
                setb.insert(b[i]), sumb[i] = setb.size();
            }
        }
    }

    int main()
    {
        read(n);
        readAll(a + 1, a + n + 1);
        readAll(b + 1, b + n + 1);

        init();

        read(q);
        for (int i = 1; i <= q; i++)
        {
            int x = readi(), y = readi();
            write((suma[x] == sumb[y] && check[suma[x]]) ? "Yes" : "No");
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}