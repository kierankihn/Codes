/**
 * @author Kieran Kihn
 * @date 2024.06.21
 * @name T1
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
    typedef std::pair<int, int> pii;

    constexpr int MAXN    = 1e5 + 5;
    constexpr int MAXLOGN = 20 + 5;

    struct Node
    {
        std::set<int> s;
        int lson, rson;
    };

    int n, m;
    int a[MAXN];

    std::vector<int> e[MAXN];
    std::vector<pii> q[MAXN];

    int cnt = 0;
    std::map<std::string, int> map;

    int dep[MAXN];
    void dfs(int u, int fa)
    {
        dep[u] = dep[fa] + 1;

        for (auto v : e[u])
        {
            dfs(v, u);
        }
    }

    int size = 0;
    int root[MAXN];
    Node node[MAXN * 40];
    void update(int x, int v, int &o, int l = 1, int r = n + 1)
    {
        if (o == 0)
        {
            o = ++size;
        }
        if (l == r)
        {
            node[o].s.insert(v);
            return;
        }

        int mid = (l + r) >> 1;
        if (x <= mid)
        {
            update(x, v, node[o].lson, l, mid);
        }
        if (x > mid)
        {
            update(x, v, node[o].rson, mid + 1, r);
        }
    }
    int query(int x, int o, int l = 1, int r = n + 1)
    {
        if (o == 0 || x < l || x > r)
        {
            return 0;
        }
        if (l == r)
        {
            return node[o].s.size();
        }

        int mid = (l + r) >> 1;
        if (x <= mid)
        {
            return query(x, node[o].lson, l, mid);
        }
        if (x > mid)
        {
            return query(x, node[o].rson, mid + 1, r);
        }

        return 0;
    }
    void merge(int &x, int o, int l = 1, int r = n + 1)
    {
        if (x == 0 || o == 0)
        {
            return void(x |= o);
        }
        if (l == r)
        {
            if (node[x].s.size() < node[o].s.size())
            {
                std::swap(o, x);
            }
            for (auto i : node[o].s)
            {
                node[x].s.insert(i);
            }
            return;
        }

        int mid = (l + r) >> 1;
        merge(node[x].lson, node[o].lson, l, mid);
        merge(node[x].rson, node[o].rson, mid + 1, r);
    }

    int ans[MAXN];
    void solve(int u)
    {
        update(dep[u], a[u], root[u]);
        for (auto v : e[u])
        {
            solve(v);
            merge(root[u], root[v]);
        }

        for (auto i : q[u])
        {
            ans[i.second] = query(dep[u] + i.first, root[u]);
        }
    }

    int main()
    {
        read(n);
        for (int i = 1; i <= n; i++)
        {
            auto name = reads();
            if (map[name] == 0)
            {
                map[name] = ++cnt;
            }
            a[i] = map[name], e[readi()].push_back(i);
        }

        dfs(0, 0);

        read(m);
        for (int i = 1; i <= m; i++)
        {
            int v = readi(), k = readi();
            q[v].emplace_back(k, i);
        }

        for (auto u : e[0])
        {
            solve(u);
        }

        for (int i = 1; i <= m; i++)
        {
            write(ans[i]);
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}