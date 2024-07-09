/**
 * @author Kieran Kihn
 * @date 2024.07.09
 * @name P4178 Tree
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

    constexpr int MAXN = 4e4 + 5;
    constexpr int MAXV = 2e4 + 5;

    int n, k;

    i64 ans = 0;

    std::vector<pii> e[MAXN];
    std::vector<int> e_d[MAXN];

    int vis[MAXN];

    int size[MAXN], maxsize[MAXN];
    int init(int u, int fa)
    {
        size[u] = 1;
        for (auto v : e[u])
        {
            if (vis[v.first] == false && v.first != fa)
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
            if (vis[v.first] == false && v.first != fa)
            {
                maxsize[u] = std::max(maxsize[u], size[v.first]);
            }
        }

        int res = u;
        for (auto v : e[u])
        {
            if (vis[v.first] == false && v.first != fa)
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
        vis[u = findroot(u, 0, u)] = true;

        init(u, 0);

        for (auto v : e[u])
        {
            if (vis[v.first] == false)
            {
                e_d[u].push_back(build(v.first));
            }
        }

        return u;
    }

    int sum[MAXV];
    int lowbit(int x)
    {
        return x & (-x);
    }
    void update(int x, int v)
    {
        while (x < k)
        {
            sum[x] += v, x += lowbit(x);
        }
    }
    int query(int x)
    {
        int res = x >= 0;
        while (x > 0)
        {
            res += sum[x], x -= lowbit(x);
        }
        return res;
    }

    int rem[MAXN], dist[MAXN];
    void dfs(int u, int fa)
    {
        for (auto v : e[u])
        {
            if (rem[v.first] == false && v.first != fa)
            {
                dist[v.first] = dist[u] + v.second;
                dfs(v.first, u);
            }
        }
    }

    vei solve(int u)
    {
        rem[u] = true;

        std::vector<vei> vp;
        for (auto v : e_d[u])
        {
            vp.push_back(solve(v));
        }

        dist[u] = 0, dfs(u, 0);

        vei p = {u}, del;
        for (auto &p0 : vp)
        {
            for (auto i : p0)
            {
                ans += query(k - dist[i]);
            }
            for (auto i : p0)
            {
                update(dist[i], 1), del.push_back(dist[i]), p.push_back(i);
            }
        }

        for (auto i : del)
        {
            update(i, -1);
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
        read(k);

        init(1, 0);
        solve(build(1));

        write(ans);

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}