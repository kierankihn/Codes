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
    typedef double dbi;
    typedef long long i64;
    typedef std::pair<i64, i64> pii;

    const int MAXN    = 1e5 + 5;
    const int MAXLOGN = 15 + 5;
    const i64 INF     = 1e10 + 5;

    struct Node
    {
        i64 id, h;
    };
    bool operator<(Node a, Node b)
    {
        return a.h < b.h;
    }

    int n, m;
    Node node[MAXN];

    std::set<Node> s;
    i64 next[MAXN][2];
    i64 dist[MAXN][2];

    i64 to[MAXN][2][MAXLOGN];  // 0-A-2, 1-B-1
    i64 dp[MAXN][2][MAXLOGN][2];

    void init()
    {
        s.insert({0, -INF}), s.insert({0, -INF + 1}), s.insert({0, INF}), s.insert({0, INF - 1});
        for (int i = n; i >= 1; i--)
        {
            auto now  = s.insert(node[i]).first;
            auto min1 = s.begin(), min2 = s.begin();

            for (auto it = std::prev(std::prev(now)); it != now; it++)
            {
                if ((std::abs(now->h - it->h) < std::abs(now->h - min1->h)) || (std::abs(now->h - it->h) == std::abs(now->h - min1->h) && it->h < now->h))
                {
                    min2 = min1, min1 = it;
                }
                else if ((std::abs(now->h - it->h) < std::abs(now->h - min2->h)) || (std::abs(now->h - it->h) == std::abs(now->h - min2->h) && it->h < now->h))
                {
                    min2 = it;
                }
            }
            for (auto it = std::next(std::next(now)); it != now; it--)
            {
                if ((std::abs(now->h - it->h) < std::abs(now->h - min1->h)) || (std::abs(now->h - it->h) == std::abs(now->h - min1->h) && it->h < now->h))
                {
                    min2 = min1, min1 = it;
                }
                else if ((std::abs(now->h - it->h) < std::abs(now->h - min2->h)) || (std::abs(now->h - it->h) == std::abs(now->h - min2->h) && it->h < now->h))
                {
                    min2 = it;
                }
            }

            next[i][0] = min1->id, next[i][1] = min2->id;
            dist[i][0] = std::abs(min1->h - now->h), dist[i][1] = std::abs(min2->h - now->h);
            // write(next[i][0], dist[i][0]);
            // write(next[i][1], dist[i][1]);
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                to[i][j][0] = next[i][j ^ 1], to[i][j][1] = next[to[i][j][0]][j];
                dp[i][j][0][j] = dist[i][j ^ 1], dp[i][j][0][j ^ 1] = 0;
                dp[i][j][1][j] = dist[i][j ^ 1], dp[i][j][1][j ^ 1] = dist[to[i][j][0]][j];
            }
        }
        for (int i = 2; i <= std::__lg(n); i++)
        {
            for (int u = 1; u <= n; u++)
            {
                for (int j = 0; j < 2; j++)
                {
                    to[u][j][i]    = to[to[u][j][i - 1]][j][i - 1];
                    dp[u][j][i][0] = dp[to[u][j][i - 1]][j][i - 1][0] + dp[u][j][i - 1][0];
                    dp[u][j][i][1] = dp[to[u][j][i - 1]][j][i - 1][1] + dp[u][j][i - 1][1];
                }
            }
        }
    }

    pii calc(int u, i64 x)
    {
        i64 la = 0, lb = 0;

        for (int i = std::__lg(n); i >= 0; i--)
        {
            if (la + dp[u][0][i][0] + lb + dp[u][0][i][1] <= x && to[u][0][i] != 0)
            {
                la += dp[u][0][i][0], lb += dp[u][0][i][1], u = to[u][0][i];
            }
        }

        return {la, lb};
    }

    void solve1()
    {
        i64 x, id = 0;
        double res = INF;
        read(x);

        for (int u = 1; u <= n; u++)
        {
            auto c = calc(u, x);

            // write(c[0], c[1], c[2]);

            auto now = (c.second == 0 ? INF : c.first * 1.0 / c.second);

            if (now < res)
            {
                res = now, id = u;
            }
        }

        write(id);
    }

    void solve2()
    {
        read(m);
        for (i64 i = 1, s, x; i <= m; i++)
        {
            read(s, x);
            auto c = calc(s, x);
            write(c.first, c.second);
        }
    }

    int main()
    {
        read(n);
        for (int i = 1; i <= n; i++)
        {
            node[i].id = i, read(node[i].h);
        }

        init();

        solve1(), solve2();

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}