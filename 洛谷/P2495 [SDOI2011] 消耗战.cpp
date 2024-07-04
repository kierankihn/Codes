/**
 * @author Kieran Kihn
 * @date 2024.07.04
 * @name P2495 [SDOI2011] 消耗战
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
    typedef std::pair<int, i64> pii;

    constexpr int MAXN    = 5e5 + 5;
    constexpr int MAXLOGN = 20 + 5;
    constexpr i64 INF     = 1e18;

    int n, q;
    bool a[MAXN];

    i64 min[MAXN];

    std::vector<pii> eo[MAXN];
    std::vector<int> ek[MAXN];

    int dfn_tot = 0;
    int dfn[MAXN], dep[MAXN], fa[MAXN][MAXLOGN];
    void dfs(int u, int father, i64 dist)
    {
        dfn[u] = ++dfn_tot, dep[u] = dep[father] + 1, fa[u][0] = father, min[u] = std::min(min[father], dist);
        for (int i = 1; i <= std::__lg(dep[u]); i++)
        {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }

        for (auto e : eo[u])
        {
            if (e.first != father)
            {
                dfs(e.first, u, e.second);
            }
        }
    }
    int LCA(int x, int y)
    {
        if (dep[x] < dep[y])
        {
            std::swap(x, y);
        }

        while (dep[x] > dep[y])
        {
            x = fa[x][std::__lg(dep[x] - dep[y])];
        }
        if (x == y)
        {
            return x;
        }

        for (int i = std::__lg(dep[x]); i >= 0; i--)
        {
            if (fa[x][i] != fa[y][i])
            {
                x = fa[x][i], y = fa[y][i];
            }
        }

        return fa[x][0];
    }

    int k;
    int p[MAXN];

    void build()
    {
        std::deque<int> s({1});

        std::sort(p + 1, p + k + 1, [](const int &a, const int &b)
                  { return dfn[a] < dfn[b]; });

        for (int i = 1; i <= k; i++)
        {
            if (p[i] != 1)
            {
                int lca = LCA(p[i], s[0]);
                if (lca != s[0])
                {
                    while (dfn[lca] < dfn[s[1]])
                    {
                        ek[s[1]].push_back(s[0]), s.pop_front();
                    }

                    ek[lca].push_back(s[0]), s.pop_front();
                    if (lca != s[0])
                    {
                        s.push_front(lca);
                    }
                }
                s.push_front(p[i]);
            }
        }

        for (int i = 1; i < s.size(); i++)
        {
            ek[s[i]].push_back(s[i - 1]);
        }
    }

    i64 dp[MAXN];
    i64 solve(int u)
    {
        if (a[u])
        {
            return dp[u] = min[u];
        }

        i64 sum = 0;
        for (auto v : ek[u])
        {
            sum += solve(v);
        }

        return dp[u] = std::min(min[u], sum);
    }

    void clear(int u)
    {
        for (auto v : ek[u])
        {
            clear(v);
        }

        dp[u] = a[u] = 0, ek[u].clear();
    }

    int main()
    {
        read(n);
        for (int i = 1; i < n; i++)
        {
            int u = readi(), v = readi(), w = readi();
            eo[u].push_back({v, w}), eo[v].push_back({u, w});
        }

        dfs(1, 0, min[0] = INF);

        read(q);
        for (int i = 1; i <= q; i++)
        {
            read(k);
            for (int j = 1; j <= k; j++)
            {
                a[p[j] = readi()] = true;
            }

            build();

            write(solve(1));

            clear(1);
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}