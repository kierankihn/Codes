/**
 * @author Kieran Kihn
 * @date 2024.06.11
 * @name CF1932G
 * @link https://codeforces.com/contest/1932/problem/G
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

    constexpr int MAXN = 1e5 + 5;
    constexpr i64 INF  = 0x3f3f3f3f3f3f3f3f;

    i64 exgcd(i64 a, i64 b, i64 &x, i64 &y)
    {
        if (b == 0)
        {
            x = 1, y = 0;
            return a;
        }

        i64 gcd = exgcd(b, a % b, x, y), t = x;
        x = y, y = t - a / b * y;
        return gcd;
    }

    int t;

    int n, m, H;
    i64 l[MAXN], s[MAXN];

    i64 mod(i64 x, i64 MOD)
    {
        x %= MOD;
        return x >= 0 ? x : x + MOD;
    }

    /**
     * la + d * sa = lb + d * sb (mod H)
     * (la - lb) + d * (sa - sb) = k * H
     * d * (sa - sb) + k * (-H) = la - lb
     *
     * la + d * sa(min) <-> d * sa(min) <-> d(min)
     *
     * d >= dist[u](min)
     *
     * x0 <-> x + H / gcd(sa - sb, -H)
     *
     * x + H / gcd(sa - sb, H) >= min
     */
    i64 calc(int a, int b, i64 min)
    {
        i64 x, y, gcd = exgcd(mod(s[a] - s[b], H), H, x, y);

        if ((l[b] - l[a]) % gcd)
        {
            return INF;
        }

        x *= mod(l[b] - l[a], H) / gcd;

        return min + (mod(mod(x, H / gcd) - mod(min, H / gcd), H / gcd));
    }

    std::vector<int> e[MAXN];

    i64 dist[MAXN], vis[MAXN];
    struct Cmp
    {
        bool operator()(const pii &a, const pii &b)
        {
            return a.second > b.second;
        }
    };
    std::priority_queue<pii, std::vector<pii>, Cmp> q;
    i64 dijkstra()
    {
        std::fill(vis, vis + n + 1, 0);
        std::fill(dist, dist + n + 1, INF);

        q.emplace(1, dist[1] = 0);

        while (q.empty() == false)
        {
            i64 u = q.top().first;
            q.pop();

            if (vis[u])
            {
                continue;
            }
            vis[u] = true;

            for (auto v : e[u])
            {
                i64 d = calc(u, v, dist[u]);
                if (d < dist[v])
                {
                    q.emplace(v, dist[v] = d + 1);
                }
            }
        }

        return dist[n];
    }

    int main()
    {
        read(t);
        while (t--)
        {
            read(n, m, H);
            readAll(l + 1, l + n + 1);
            readAll(s + 1, s + n + 1);

            for (int i = 1; i <= n; i++)
            {
                e[i].clear();
            }

            for (int i = 1; i <= m; i++)
            {
                int u = readi(), v = readi();
                e[u].push_back(v), e[v].push_back(u);
            }

            i64 ans = dijkstra();

            write(ans == INF ? -1 : ans);
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}