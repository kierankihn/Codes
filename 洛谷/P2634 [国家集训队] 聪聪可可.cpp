/**
 * @author Kieran Kihn
 * @date 2024.07.08
 * @name P2634 [国家集训队] 聪聪可可
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
    typedef std::vector<int> vei;
    typedef std::pair<int, int> pii;

    constexpr int MAXN = 2e4 + 5;

    int n;

    i64 ans = 0, sum = 0;

    std::vector<pii> e[MAXN];
    std::vector<int> e_d[MAXN];

    int vis[MAXN];

    int rem[MAXN], dist[MAXN];
    void dfs(int u, int fa)
    {
        for (auto v : e[u])
        {
            if (v.first != fa && rem[v.first] == false)
            {
                dist[v.first] = dist[u] + v.second;
                dfs(v.first, u);
            }
        }
    }

    int size[MAXN], maxsize[MAXN];
    int init(int u, int fa)
    {
        size[u] = 1;
        for (auto v : e[u])
        {
            if (v.first != fa && vis[v.first] == false)
            {
                size[u] += init(v.first, u);
            }
        }
        return size[u];
    }
    int findroot(int u, int fa, int x)
    {
        maxsize[u] = size[x] - size[u];
        for (auto v : e[u])
        {
            if (v.first != fa && vis[v.first] == false)
            {
                maxsize[u] = std::max(maxsize[u], size[v.first]);
            }
        }

        int res = u;
        for (auto v : e[u])
        {
            if (v.first != fa && vis[v.first] == false)
            {
                int now = findroot(v.first, u, x);
                if (maxsize[now] < maxsize[res])
                {
                    res = now;
                }
            }
        }

        return res;
    }

    int build(int u)
    {
        init(u, 0);
        vis[u = findroot(u, 0, u)] = true;

        for (auto v : e[u])
        {
            if (vis[v.first] == false)
            {
                e_d[u].push_back(build(v.first));
            }
        }

        return u;
    }

    vei solve(int u)
    {
        vei p = {u};
        std::vector<vei> vp;

        rem[u] = true;

        int cnt0 = 1, cnt1 = 0, cnt2 = 0;

        for (auto v : e_d[u])
        {
            vp.push_back(solve(v));
        }

        dist[u] = 0, dfs(u, 0);

        for (auto &p0 : vp)
        {
            for (auto i : p0)
            {
                if (dist[i] % 3 == 0)
                {
                    ans += cnt0;
                }
                if (dist[i] % 3 == 1)
                {
                    ans += cnt2;
                }
                if (dist[i] % 3 == 2)
                {
                    ans += cnt1;
                }
            }


            for (auto i : p0)
            {
                p.push_back(i);
                if (dist[i] % 3 == 0)
                {
                    cnt0++;
                }
                if (dist[i] % 3 == 1)
                {
                    cnt1++;
                }
                if (dist[i] % 3 == 2)
                {
                    cnt2++;
                }
            }
        }

        rem[u] = false;

        return p;
    }

    int main()
    {
        read(n);
        for (int i = 1; i < n; i++)
        {
            int u = readi(), v = readi(), w = readi();
            e[u].push_back({v, w}), e[v].push_back({u, w});
        }

        solve(build(1));

        ans = ans * 2 + n, sum = 1LL * n * n;

        for (i64 i = 2; i * i <= sum; i++)
        {
            while (ans % i == 0 && sum % i == 0)
            {
                ans /= i, sum /= i;
            }
        }

        printf("%lld/%lld\n", ans, sum);

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}