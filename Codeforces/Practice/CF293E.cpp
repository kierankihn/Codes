/**
 * @author Kieran Kihn
 * @date 2024.07.09
 * @name CF293E
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

    constexpr int MAXN = 1e5 + 5;

    int n, maxdep, maxdist;

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

    int rem[MAXN];
    i64 dep[MAXN], dist[MAXN];
    void dfs(int u, int fa)
    {
        for (auto v : e[u])
        {
            if (v.first != fa && rem[v.first] == false)
            {
                dist[v.first] = dist[u] + v.second, dep[v.first] = dep[u] + 1;
                dfs(v.first, u);
            }
        }
    }

    i64 sum[MAXN];
    int lowbit(int x)
    {
        return x & (-x);
    }
    void update(int x, i64 v)
    {
        if (x == 0)
        {
            sum[0] += v;
            return;
        }
        while (x <= n)
        {
            sum[x] += v, x += lowbit(x);
        }
    }
    i64 query(int x)
    {
        i64 res = x >= 0 ? sum[0] : 0;
        while (x > 0)
        {
            res += sum[x], x -= lowbit(x);
        }
        return res;
    }

    i64 calc(std::vector<pii> &x)
    {
        i64 res = 0;

        std::sort(x.begin(), x.end());

        std::vector<pii> q;

        for (auto i : x)
        {
            if (maxdist - i.first >= 0 && maxdep - i.second >= 0)
            {
                q.push_back({maxdist - i.first, maxdep - i.second});
            }
            if (i.first * 2 <= maxdist && i.second * 2 <= maxdep)
            {
                res--;
            }
        }

        std::sort(q.begin(), q.end());

        auto it = q.begin();

        for (auto i : x)
        {
            while (it != q.end() && it->first < i.first)
            {
                res += query(it->second), it++;
            }

            update(i.second, 1);
        }
        while (it != q.end())
        {
            res += query(it->second), it++;
        }

        for (auto i : x)
        {
            update(i.second, -1);
        }

        return res / 2;
    }

    vei solve(int u)
    {
        rem[u] = true;

        std::vector<vei> vp;
        for (auto v : e_d[u])
        {
            vp.push_back(solve(v));
        }

        dfs(u, dist[u] = dep[u] = 0);

        vei p = {u};

        std::vector<pii> d = {{0, 0}}, d0;
        for (auto &p0 : vp)
        {
            d0.clear();
            for (auto i : p0)
            {
                p.push_back(i), d.push_back({dist[i], dep[i]}), d0.push_back({dist[i], dep[i]});
            }
            ans -= calc(d0);
        }

        ans += calc(d);

        return rem[u] = false, p;
    }

    int main()
    {
        read(n, maxdep, maxdist);
        for (int i = 1; i < n; i++)
        {
            int u = i + 1, v = readi(), w = readi();
            e[u].push_back({v, w}), e[v].push_back({u, w});
        }

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