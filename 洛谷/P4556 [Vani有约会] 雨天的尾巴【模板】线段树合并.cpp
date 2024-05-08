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

    struct Node
    {
        int max = 0, maxpos = 0;
        int lson, rson;
    };

    int n, m;
    std::vector<int> e[MAXN];

    int dep[MAXN];
    int fa[MAXN][MAXLOGN];
    void dfs(int u, int father)
    {
        fa[u][0] = father, dep[u] = dep[father] + 1;

        for (int i = 1; (1 << i) < dep[u]; i++)
        {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }

        for (auto v : e[u])
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

    int size = 0;
    int root[MAXN];
    Node node[MAXN << 7];
    void init()
    {
        for (int i = 1; i <= n; i++)
        {
            root[i] = ++size;
        }
    }
    void pushup(int o)
    {
        auto &ls = node[node[o].lson], &rs = node[node[o].rson];
        node[o].max = std::max(ls.max, rs.max), node[o].maxpos = ls.max >= rs.max ? ls.maxpos : rs.maxpos;
        if (node[o].max == 0)
        {
            node[o].maxpos = 0;
        }
    }
    void update(int x, int v, int o, int l = 1, int r = 1e5)
    {
        if (o == 0)
        {
            return;
        }
        if (l == r)
        {
            node[o].max += v, node[o].maxpos = node[o].max != 0 ? l : 0;
            return;
        }

        int mid = (l + r) >> 1;
        if (x <= mid)
        {
            if (node[o].lson == 0)
            {
                node[o].lson = ++size;
            }
            update(x, v, node[o].lson, l, mid);
        }
        if (x > mid)
        {
            if (node[o].rson == 0)
            {
                node[o].rson = ++size;
            }
            update(x, v, node[o].rson, mid + 1, r);
        }

        pushup(o);
    }
    int merge(int a, int b, int l = 1, int r = 1e5)
    {
        if (a == 0)
        {
            return b;
        }
        if (b == 0)
        {
            return a;
        }

        int o = ++size;

        if (l == r)
        {
            node[o].max = node[a].max + node[b].max, node[o].maxpos = std::max(node[a].maxpos, node[b].maxpos);
            return o;
        }

        int mid = (l + r) >> 1;

        int lson = merge(node[a].lson, node[b].lson, l, mid);
        int rson = merge(node[a].rson, node[b].rson, mid + 1, r);

        node[o] = {0, 0, lson, rson}, pushup(o);
        return o;
    }

    int ans[MAXN];
    void solve(int u, int father)
    {
        for (auto v : e[u])
        {
            if (v != father)
            {
                solve(v, u);
                root[u] = merge(root[u], root[v]);
            }
        }

        ans[u] = node[root[u]].maxpos;
    }

    int main()
    {
        read(n, m);
        for (int i = 1; i < n; i++)
        {
            int u = readi(), v = readi();
            e[u].push_back(v), e[v].push_back(u);
        }

        init();
        dfs(1, 0);

        for (int i = 1; i <= m; i++)
        {
            int from = readi(), to = readi(), k = readi(), lca = LCA(from, to);

            update(k, 1, root[from]), update(k, 1, root[to]);
            update(k, -1, root[lca]), update(k, -1, root[fa[lca][0]]);
        }

        solve(1, 0);

        for (int i = 1; i <= n; i++)
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