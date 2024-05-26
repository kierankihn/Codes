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

    int n, m;
    std::set<int> e[MAXN];

    std::set<int> p[MAXN];

    int dep[MAXN];

    void bfs()
    {
        std::set<int> remain;
        for (int i = 1; i <= n; i++)
        {
            remain.insert(i);
        }

        std::queue<int> q;
        q.push(1), dep[1] = 0, remain.erase(1);

        while (q.empty() == false)
        {
            auto u = q.front();
            q.pop();

            p[dep[u]].insert(u);

            if (u == n)
            {
                return;
            }

            for (auto it = remain.begin(); it != remain.end();)
            {
                int v = *it;
                if (e[u].count(v) == false)
                {
                    dep[v] = dep[u] + 1, q.push(v), remain.erase(it++);
                }
                else
                {
                    it++;
                }
            }
        }
    }

    int dp[MAXN], sum[MAXN];
    void solve()
    {
        sum[0] = 1;
        for (int i = 1; i <= dep[n]; i++)
        {
            for (auto u : p[i])
            {
                dp[u] = sum[i - 1];
                for (auto v : e[u])
                {
                    if (p[i - 1].count(v))
                    {
                        dp[u] = (dp[u] - dp[v] + MOD) % MOD;
                    }
                }
                sum[i] = (sum[i] + dp[u]) % MOD;
            }
        }
    }

    int main()
    {
        read(n, m);
        for (int i = 1; i <= m; i++)
        {
            int u = readi(), v = readi();

            e[u].insert(v), e[v].insert(u);
        }

        bfs(), solve();

        write(dep[n] == 0 ? -1 : dp[n]);

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}