/**
 * @author Kieran Kihn
 * @date 2024.09.27
 * @name money
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
    } // namespace basic_IO
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
} // namespace IO
namespace solution
{

    using namespace IO;
    typedef long long i64;
    typedef std::pair<int, int> pii;
    typedef std::pair<pii, pii> p4i;

    constexpr int MAXN = 3e5 + 5;
    constexpr int INF  = 1e9;

    struct Node
    {
        int ax = INF, ay = INF, bx = INF, by = INF, ans = INF;
    };
    Node operator+(const Node &a, const Node &b)
    {
        return {std::min(a.ax, b.ax), std::min(a.ay, b.ay), std::min(a.bx, b.bx), std::min(a.by, b.by), std::min({a.ans, b.ans, a.ay + b.by, a.bx + b.ax})};
    }

    int n;

    p4i a[MAXN];

    int size = 0, pos[MAXN];
    pii b[MAXN];
    std::map<pii, std::vector<int>> map[3];

    Node node[MAXN << 2];
    void update(int x, int vx, int vy, int vd, int o = 1, int l = 1, int r = n)
    {
        if (l == r)
        {
            if (vd == 0)
            {
                node[o] = {};
            }
            if (vd == 1)
            {
                node[o].ax = vx, node[o].ay = vy;
            }
            if (vd == 2)
            {
                node[o].bx = vx, node[o].by = vy;
            }
            return;
        }

        int mid = (l + r) >> 1;
        if (x <= mid)
        {
            update(x, vx, vy, vd, o << 1, l, mid);
        }
        else
        {
            update(x, vx, vy, vd, o << 1 | 1, mid + 1, r);
        }

        node[o] = node[o << 1] + node[o << 1 | 1];
    }

    int main()
    {
        std::freopen("money.in", "r", stdin);
        std::freopen("money.out", "w", stdout);

        read(n);
        for (int i = 1; i <= n; i++)
        {
            read(a[i].first.first, a[i].first.second, a[i].second.first, a[i].second.second);
            if (a[i].first.first == 1)
            {
                b[++size] = {a[i].first.second == 1 ? a[i].second.first - a[i].second.second : a[i].second.second - a[i].second.first, i};
                map[a[i].first.second][a[i].second].push_back(i);
            }
            else
            {
                pos[i] = map[a[i].first.second][a[i].second].back(), map[a[i].first.second][a[i].second].pop_back();
            }
        }

        std::sort(b + 1, b + size + 1);
        for (int i = 1; i <= size; i++)
        {
            pos[b[i].second] = i;
        }

        for (int i = 1; i <= n; i++)
        {
            if (a[i].first.first == 1)
            {
                update(pos[i], a[i].second.first, a[i].second.second, a[i].first.second);
            }
            else
            {
                update(pos[pos[i]], 0, 0, 0);
            }
            write(node[1].ans == INF ? -1 : node[1].ans);
        }

        return 0;
    }
} // namespace solution
int main()
{
    solution::main();
    return 0;
}