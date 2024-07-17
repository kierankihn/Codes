/**
 * @author Kieran Kihn
 * @date 2024.07.15
 * @name J
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
    int a[MAXN], b[MAXN];

    std::map<int, std::vector<int>> pos;

    i64 ans = 0;

    int sum[MAXN];
    int lowbit(int x)
    {
        return x & (-x);
    }
    int query(int x)
    {
        int res = 0;
        while (x > 0)
        {
            res += sum[x], x -= lowbit(x);
        }
        return res;
    }
    void update(int x, int v)
    {
        while (x <= n)
        {
            sum[x] += v, x += lowbit(x);
        }
    }

    int main()
    {
        read(n);
        for (int i = 1; i <= n; i++)
        {
            a[i] = readi() + i, pos[a[i]].push_back(i);
        }
        for (int i = 1; i <= n; i++)
        {
            b[i] = readi() + i;
        }

        for (auto &i : pos)
        {
            std::sort(i.second.begin(), i.second.end(), std::greater<int>());
        }

        for (int i = 1; i <= n; i++)
        {
            if (pos[b[i]].empty())
            {
                ans = -1;
                break;
            }

            int minpos = pos[b[i]].back();

            ans += minpos + query(minpos) - i;
            update(1, 1), update(minpos, -1), pos[b[i]].pop_back();
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