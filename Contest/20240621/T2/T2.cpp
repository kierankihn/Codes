/**
 * @author Kieran Kihn
 * @date 2024.06.21
 * @name https://www.luogu.com.cn/problem/CF1895E
 * @link CF1895E
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
    typedef std::pair<int, int> pii;

    constexpr int MAXN = 3e5 + 5;

    int t;

    int n, m;
    pii a[MAXN], b[MAXN];

    int maxa[MAXN], maxb[MAXN];

    std::vector<int> e[MAXN * 2];

    int vis[MAXN * 2], ans[MAXN * 2];

    int dfs(int u)  // 0: a, 1: b, 2: p
    {
        vis[u] = 2;

        if (e[u].size() == 0)
        {
            return ans[u] = u > n;
        }
        if (vis[e[u][0]] == 2)
        {
            return ans[u] = ans[e[u][0]];
        }
        if (vis[e[u][0]] == 1)
        {
            return ans[u] = 2;
        }

        return vis[u] = 1, ans[u] = dfs(e[u][0]), vis[u] = 2, ans[u];
    }

    int ansa, ansb, ansp;

    void init()
    {
        ansa = ansb = ansp = 0;

        std::fill(vis, vis + n + m + 4, 0);
        std::fill(ans, ans + n + m + 4, 0);
        std::fill(maxa, maxa + n + 4, 0);
        std::fill(maxb, maxb + m + 4, 0);
        for (int i = 1; i <= n + m; i++)
        {
            e[i].clear();
        }
    }

    int main()
    {
        read(t);
        while (t--)
        {
            read(n);
            for (int i = 1; i <= n; i++)
            {
                read(a[i].first);
            }
            for (int i = 1; i <= n; i++)
            {
                read(a[i].second);
            }
            read(m);
            for (int i = 1; i <= m; i++)
            {
                read(b[i].first);
            }
            for (int i = 1; i <= m; i++)
            {
                read(b[i].second);
            }

            init();
            std::sort(a + 1, a + n + 1), std::sort(b + 1, b + m + 1);
            for (int i = n; i >= 1; i--)
            {
                if (a[i].second > a[maxa[i + 1]].second)
                {
                    maxa[i] = i;
                }
                else
                {
                    maxa[i] = maxa[i + 1];
                }
            }
            for (int i = m; i >= 1; i--)
            {
                if (b[i].second > b[maxb[i + 1]].second)
                {
                    maxb[i] = i;
                }
                else
                {
                    maxb[i] = maxb[i + 1];
                }
            }

            for (int i = 1; i <= n; i++)
            {
                int next = std::lower_bound(b + 1, b + m + 1, pii{a[i].second + 1, 0}) - b;
                if (next != m + 1)
                {
                    e[i] = {maxb[next] + n};
                }
                else
                {
                    e[i] = {};
                }
            }
            for (int i = 1; i <= m; i++)
            {
                int next = std::lower_bound(a + 1, a + n + 1, pii{b[i].second + 1, 0}) - a;
                if (next != n + 1)
                {
                    e[i + n] = {maxa[next]};
                }
                else
                {
                    e[i + n] = {};
                }
            }

            for (int i = 1; i <= n; i++)
            {
                if (vis[i] == 0)
                {
                    dfs(i);
                }
                if (ans[i] == 0)
                {
                    ansa++;
                }
                if (ans[i] == 1)
                {
                    ansb++;
                }
                if (ans[i] == 2)
                {
                    ansp++;
                }
            }

            write(ansa, ansp, ansb);
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}