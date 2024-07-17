/**
 * @author Kieran Kihn
 * @date 2024.07.16
 * @name C
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

    constexpr int MAXN = 1e3 + 5;

    int n;
    int a[MAXN];

    int ans[MAXN];

    int cnt1 = 0, cnt2 = 0;
    std::vector<int> bucket[MAXN];

    int main()
    {
        read(n);
        for (int i = 1; i <= 2 * n; i++)
        {
            bucket[a[i] = readi()].push_back(i);
        }

        for (int i = 10; i < 100; i++)
        {
            if (bucket[i].size() == 1)
            {
                if (cnt1 <= cnt2)
                {
                    cnt1++;
                    ans[bucket[i].front()] = 1;
                }
                else
                {
                    cnt2++;
                    ans[bucket[i].front()] = 2;
                }
            }
            if (bucket[i].size() >= 2)
            {
                cnt1++, cnt2++;
                ans[bucket[i][0]] = 1;
                ans[bucket[i][1]] = 2;
            }
        }

        write(1LL * cnt1 * cnt2);

        for (int i = 1; i <= 2 * n; i++)
        {
            if (ans[i] == 0)
            {
                if (cnt1 < n)
                {
                    cnt1++;
                    ans[i] = 1;
                }
                else
                {
                    ans[i] = 2;
                }
            }
        }

        writeAll(ans + 1, ans + 2 * n + 1);

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}