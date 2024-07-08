/**
 * @author Kieran Kihn
 * @date 2024.07.08
 * @name P3806 【模板】点分治 1
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

    constexpr int MAXQ = 100 + 5;
    constexpr int MAXN = 1e4 + 5;
    constexpr int MAXV = 1e7 + 5;

    int n, m;
    int q[MAXQ], ans[MAXQ];

    int dist[MAXN];

    std::vector<pii> g[MAXN];
    std::vector<int> e[MAXN], e_d[MAXN];

    bool rem[MAXN];
    void dfs(int u, int fa)
    {
        for (auto v : g[u])
        {
            if (v.first != fa && rem[v.first] == false)
            {
                dist[v.first] = dist[u] + v.second;
                dfs(v.first, u);
            }
        }
    }

    int vis[MAXN];

    int size[MAXN];
    int init(int u, int fa)
    {
        size[u] = 1;
        for (auto v : e[u])
        {
            if (v != fa && vis[v] == false)
            {
                size[u] += init(v, u);
            }
        }
        return size[u];
    }

    int maxsize[MAXN];
    int findroot(int u, int fa, int x)
    {
        maxsize[u] = size[x] - size[u];
        for (auto v : e[u])
        {
            if (v != fa && vis[v] == false)
            {
                maxsize[u] = std::max(maxsize[u], size[v]);
            }
        }

        int res = u;
        for (auto v : e[u])
        {
            if (v != fa && vis[v] == false)
            {
                int now = findroot(v, u, x);
                if (maxsize[now] < maxsize[res])
                {
                    res = now;
                }
            }
        }

        return res;
    }

    int build(int u, int fa)
    {
        init(u, fa);
        vis[u = findroot(u, fa, u)] = true;

        for (auto v : e[u])
        {
            if (vis[v] == false)
            {
                e_d[u].push_back(build(v, u));
            }
        }

        return u;
    }

    bool dis[MAXV];
    vei solve(int u)
    {
        vei p0 = {u}, d;
        std::vector<vei> vp;

        rem[u] = true;
        for (auto v : e_d[u])
        {
            vp.push_back(solve(v));
        }

        dist[u] = 0, dfs(u, 0);

        dis[0] = 1;
        for (auto &p1 : vp)
        {
            for (auto i : p1)
            {
                if (dist[i] <= 1e7)
                {
                    p0.push_back(i), d.push_back(dist[i]);

                    for (int j = 1; j <= m; j++)
                    {
                        if (q[j] - dist[i] >= 0 && dis[q[j] - dist[i]] == true)
                        {
                            ans[j] = true;
                        }
                    }
                }
            }

            for (auto i : p1)
            {
                if (dist[i] <= 1e7)
                {
                    dis[dist[i]] = true;
                }
            }
        }

        for (auto i : d)
        {
            dis[i] = false;
        }

        rem[u] = false;
        return p0;
    }

    int main()
    {
        read(n, m);
        for (int i = 1; i < n; i++)
        {
            int u = readi(), v = readi(), w = readi();
            e[u].push_back(v), e[v].push_back(u);
            g[u].push_back({v, w}), g[v].push_back({u, w});
        }

        readAll(q + 1, q + m + 1);

        init(1, 0);
        solve(build(1, 0));

        for (int i = 1; i <= m; i++)
        {
            write(ans[i] ? "AYE" : "NAY");
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}