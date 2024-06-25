/**
 * @author Kieran Kihn
 * @date 2024.06.24
 * @name T4
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
    constexpr int MOD  = 998244353;

    int n;
    std::vector<int> e[MAXN];

    int res, dep[MAXN];
    void dfs(int u, int father)
    {
        dep[u] = dep[father] + 1;
        if (dep[u] > dep[res])
        {
            res = u;
        }

        for (auto v : e[u])
        {
            if (v != father)
            {
                dfs(v, u);
            }
        }
    }

    std::vector<int> route;
    bool findroute(int u, int father, int end)
    {
        if (u == end)
        {
            route.push_back(u);
            return true;
        }

        for (auto v : e[u])
        {
            if (v != father)
            {
                if (findroute(v, u, end))
                {
                    route.push_back(u);
                    return true;
                }
            }
        }

        return false;
    }

    int tot = 0;
    void dfstot(int u, int father, int len)
    {
        dep[u] = dep[father] + 1;
        if (dep[u] == len)
        {
            tot++;
        }

        for (auto v : e[u])
        {
            if (v != father)
            {
                dfstot(v, u, len);
            }
        }
    }

    int main()
    {
        read(n);
        for (int i = 1; i < n; i++)
        {
            int u = readi(), v = readi();
            e[u].push_back(v), e[v].push_back(u);
        }

        int p1 = (dfs(1, 0), res), p2 = (dfs(res, 0), res);

        findroute(p1, 0, p2);
        while (route.size() > dep[p2] / 2 + 1)
        {
            route.pop_back();
        }

        if (dep[p2] & 1)
        {
            i64 ans = 1;
            int mid = route.back();
            for (auto v : e[mid])
            {
                ans = ans * (tot = 0, dfstot(v, mid, dep[p2]), tot + 1) % MOD;
            }

            for (auto v : e[mid])
            {
                ans = ans - (tot = 0, dfstot(v, mid, dep[p2]), tot), ans %= MOD, ans += MOD, ans %= MOD;
            }
            ans = (ans - 1 + MOD) % MOD;

            write(ans);
        }
        else
        {
            i64 ans = 1;
            int m1 = route.back(), m2 = (route.pop_back(), route.back()), len = dep[p2];
            int t1 = (tot = 0, dep[m2] = std::min(dep[m1], dep[m2]), dfstot(m1, m2, len), tot);
            int t2 = (tot = 0, dep[m1] = std::min(dep[m1], dep[m2]), dfstot(m2, m1, len), tot);

            ans = ((1LL * (t1 + 1) * (t2 + 1) - t1 - t2 - 1) % MOD + MOD) % MOD;

            write(ans);
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}