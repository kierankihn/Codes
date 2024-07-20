/**
 * @author Kieran Kihn
 * @date 2024.07.04
 * @name CF613D
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

    constexpr int MAXN    = 1e5 + 5;
    constexpr int MAXLOGN = 20 + 5;

    int n, q;

    std::vector<int> eo[MAXN], ek[MAXN];

    int a[MAXN];

    int dfn_tot = 0;
    int dfn[MAXN], dep[MAXN], fa[MAXN][MAXLOGN];
    void dfs(int u, int father)
    {
        dep[u] = dep[father] + 1, fa[u][0] = father, dfn[u] = ++dfn_tot;
        for (int i = 1; i <= std::__lg(dep[u]); i++)
        {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }

        for (auto v : eo[u])
        {
            if (v != father)
            {
                dfs(v, u);
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

    bool check(int u, int father)
    {
        if (a[u] && a[father] && dep[u] == dep[father] + 1)
        {
            return false;
        }
        for (auto v : ek[u])
        {
            if (check(v, u) == false)
            {
                return false;
            }
        }
        return true;
    }

    int size = 0;
    int p[MAXN];
    void build()
    {
        std::sort(p + 1, p + size + 1, [](const int &a, const int &b)
                  { return dfn[a] < dfn[b]; });

        std::deque<int> s({1});

        for (int i = 1; i <= size; i++)
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
                    if (dfn[lca] != dfn[s[0]])
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

    int dp[MAXN], link[MAXN];
    int solve(int u)
    {
        int sum = 0;
        for (auto v : ek[u])
        {
            dp[u] += solve(v), sum += link[v];
        }

        if (a[u])
        {
            dp[u] += sum, link[u] = true;
        }
        else
        {
            if (sum > 1)
            {
                dp[u]++;
            }
            else
            {
                link[u] = bool(sum);
            }
        }

        return dp[u];
    }

    void clear(int u)
    {
        for (auto v : ek[u])
        {
            clear(v);
        }

        dp[u] = link[u] = a[u] = 0;
        ek[u].clear();
    }

    int main()
    {
        read(n);
        for (int i = 1; i < n; i++)
        {
            int u = readi(), v = readi();
            eo[u].push_back(v), eo[v].push_back(u);
        }

        dfs(1, 0);

        read(q);
        for (int i = 1; i <= q; i++)
        {
            read(size);
            for (int j = 1; j <= size; j++)
            {
                a[p[j] = readi()] = true;
            }

            build();

            if (check(1, 0) == false)
            {
                write(-1);
            }
            else
            {
                write(solve(1));
            }

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