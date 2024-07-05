/**
 * @author Kieran Kihn
 * @date 2024.07.04
 * @name P3320 [SDOI2015] 寻宝游戏
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

    constexpr int MAXN    = 1e5 + 5;
    constexpr int MAXLOGN = 20 + 5;

    int n, q;
    bool a[MAXN];

    std::vector<pii> e[MAXN];

    int dfc = 0;
    i64 dfn[MAXN], dep[MAXN], dis[MAXN], fa[MAXN][MAXLOGN], dfr[MAXN];
    void dfs(int u, int father)
    {
        dep[u] = dep[father] + 1, fa[u][0] = father, dfn[u] = ++dfc, dfr[dfc] = u;
        for (int i = 1; i <= std::__lg(dep[u]); i++)
        {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }

        for (auto v : e[u])
        {
            if (v.first != father)
            {
                dis[v.first] = dis[u] + v.second;
                dfs(v.first, u);
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

    std::set<int> s;

    i64 ans = 0;

    i64 dist(int x, int y)
    {
        return dis[x] + dis[y] - 2 * dis[LCA(x, y)];
    }
    i64 calc(int p1, int p2, int x)
    {
        return dist(p1, x) + dist(p2, x) - dist(p1, p2);
    }

    int main()
    {
        read(n, q);
        for (int i = 1; i < n; i++)
        {
            int u = readi(), v = readi(), w = readi();
            e[u].push_back({v, w}), e[v].push_back({u, w});
        }

        dfs(1, 0);

        for (int i = 1; i <= q; i++)
        {
            int x = readi();

            if (a[x] == 0)
            {
                s.insert(dfn[x]);
            }

            auto itl = s.lower_bound(dfn[x]), itu = s.upper_bound(dfn[x]);

            auto prev = *(itl != s.begin() ? std::prev(itl) : std::prev(s.end()));
            auto next = *(itu != s.end() ? itu : s.begin());

            if (a[x] == 1)
            {
                s.erase(dfn[x]);
            }

            if (a[x] == 0)
            {
                a[x] = 1;
                ans += calc(dfr[prev], dfr[next], x);
            }
            else
            {
                a[x] = 0;
                ans -= calc(dfr[prev], dfr[next], x);
            }

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