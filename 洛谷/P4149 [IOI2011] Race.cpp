/**
 * @author Kieran Kihn
 * @date 2024.07.08
 * @name P4149 [IOI2011] Race
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
    typedef std::pair<int, i64> pii;

    constexpr int MAXN = 2e5 + 5;
    constexpr int MAXV = 1e6 + 5;
    constexpr int INF  = 0x3f3f3f3f;

    int n, k;

    i64 ans = INF;

    std::vector<pii> e[MAXN];
    std::vector<int> e_d[MAXN];

    int vis[MAXN];

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

    i64 rem[MAXN], dep[MAXN], dist[MAXN];
    void dfs(int u, int fa)
    {
        for (auto v : e[u])
        {
            if (v.first != fa && rem[v.first] == false)
            {
                dep[v.first] = dep[u] + 1, dist[v.first] = dist[u] + v.second;
                dfs(v.first, u);
            }
        }
    }

    i64 bucket[MAXV];
    vei solve(int u)
    {
        rem[u] = true;

        std::vector<vei> vep;
        for (auto v : e_d[u])
        {
            vep.push_back(solve(v));
        }

        dfs(u, dep[u] = dist[u] = 0);

        vei p = {u}, del;
        for (auto &p0 : vep)
        {
            for (auto i : p0)
            {
                if (k - dist[i] >= 0)
                {
                    ans = std::min(ans, dep[i] + bucket[k - dist[i]]);
                }
            }

            for (auto i : p0)
            {
                p.push_back(i);
                if (dist[i] <= k)
                {
                    del.push_back(dist[i]), bucket[dist[i]] = std::min(bucket[dist[i]], dep[i]);
                }
            }
        }

        rem[u] = false;
        for (auto i : del)
        {
            bucket[i] = INF;
        }

        return p;
    }

    int main()
    {
        std::fill(bucket + 1, bucket + MAXV, INF);

        read(n, k);
        for (int i = 1; i < n; i++)
        {
            int u = readi() + 1, v = readi() + 1, w = readi();
            e[u].push_back({v, w}), e[v].push_back({u, w});
        }

        solve(build(1));

        write(ans == INF ? -1 : ans);

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}