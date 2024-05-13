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

    const int MAXN    = 1e5 + 5;
    const int MAXLOGN = 20 + 5;
    const int INF     = 0x3f3f3f3f;

    struct Node
    {
        int min = INF;
    };
    Node operator+(const Node a, const Node b)
    {
        return {std::min(a.min, b.min)};
    }

    int n, m;
    int w[MAXN];

    int root = 1;
    int size = 0;
    int id[MAXN], start[MAXN], end[MAXN];
    std::vector<int> e[MAXN];

    int dep[MAXN];
    int fa[MAXN][MAXLOGN];
    void dfs(int u = root, int father = 0)
    {
        id[u] = start[u] = ++size;
        fa[u][0] = father, dep[u] = dep[father] + 1;
        for (int i = 1; (1 << i) < dep[u]; i++)
        {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
        for (auto v : e[u])
        {
            dfs(v, u);
        }
        end[u] = size;
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
    int subtree(int x, int y)
    {
        while (dep[y] > dep[x] + 1)
        {
            y = fa[y][std::__lg(dep[y] - dep[x] - 1)];
        }
        return y;
    }

    int a[MAXN];
    Node node[MAXN << 2];
    void build(int o = 1, int l = 1, int r = n)
    {
        if (l == r)
        {
            node[o] = {a[l]};
            return;
        }

        int mid = (l + r) >> 1;
        build(o << 1, l, mid), build(o << 1 | 1, mid + 1, r);

        node[o] = node[o << 1] + node[o << 1 | 1];
    }
    void update(int x, int v, int o = 1, int l = 1, int r = n)
    {
        if (l == r)
        {
            node[o] = {a[l] = v};
            return;
        }

        int mid = (l + r) >> 1;
        if (x <= mid)
        {
            update(x, v, o << 1, l, mid);
        }
        if (x > mid)
        {
            update(x, v, o << 1 | 1, mid + 1, r);
        }

        node[o] = node[o << 1] + node[o << 1 | 1];
    }
    int query(int ql, int qr, int o = 1, int l = 1, int r = n)
    {
        if (ql > qr)
        {
            return INF;
        }
        if (ql <= l && r <= qr)
        {
            return node[o].min;
        }

        int mid = (l + r) >> 1;
        if (mid >= ql && mid < qr)
        {
            return std::min(query(ql, qr, o << 1, l, mid), query(ql, qr, o << 1 | 1, mid + 1, r));
        }
        if (mid >= ql)
        {
            return query(ql, qr, o << 1, l, mid);
        }
        if (mid < qr)
        {
            return query(ql, qr, o << 1 | 1, mid + 1, r);
        }

        return INF;
    }

    int main()
    {
        read(n, m);
        for (int i = 1; i <= n; i++)
        {
            e[readi()].push_back(i), w[i] = readi();
        }

        dfs();

        for (int i = 1; i <= n; i++)
        {
            a[id[i]] = w[i];
        }

        build();

        for (int i = 1; i <= m; i++)
        {
            auto op = reads();
            if (op == "E")
            {
                root = readi();
            }
            if (op == "V")
            {
                int x = readi(), v = readi();
                update(id[x], v);
            }
            if (op == "Q")
            {
                int x = readi(), lca = LCA(x, root);

                if (root == x)
                {
                    write(query(1, n));
                }
                else
                {
                    if (lca == x)
                    {
                        int root_subtree = subtree(x, root);
                        write(std::min(query(1, start[root_subtree] - 1), query(end[root_subtree] + 1, n)));
                    }
                    else
                    {
                        write(query(start[x], end[x]));
                    }
                }
            }
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}