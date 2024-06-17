/**
 * @author Kieran Kihn
 * @date 2024.06.17
 * @name CF208E
 * @link http://codeforces.com/problemset/problem/208/E
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

    int n, m;
    int ans[MAXN];

    std::vector<int> e[MAXN];

    std::vector<pii> q[MAXN];

    int dep[MAXN], fa[MAXN][MAXLOGN];
    void dfs(int u, int father)
    {
        dep[u] = dep[fa[u][0] = father] + 1;
        for (int i = 1; i <= std::__lg(dep[u]); i++)
        {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }

        for (auto v : e[u])
        {
            dfs(v, u);
        }
    }
    int find(int u, int len)
    {
        for (int i = 0; i <= std::__lg(len); i++)
        {
            if ((1 << i) & len)
            {
                u = fa[u][i];
            }
        }
        return u;
    }

    struct Node
    {
        int sum;
        int lson, rson;
    };

    int size;
    int root[MAXN];
    Node node[MAXN << 6];

    void pushup(int o)
    {
        node[o].sum = node[node[o].lson].sum + node[node[o].rson].sum;
    }
    void update(int x, int v, int &o, int l = 1, int r = n + 1)
    {
        if (o == 0)
        {
            o = ++size;
        }
        if (l == r)
        {
            node[o].sum += v;
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

        pushup(o);
    }
    int query(int ql, int qr, int o, int l = 1, int r = n + 1)
    {
        if (o == 0)
        {
            return 0;
        }
        if (ql <= l && r <= qr)
        {
            return node[o].sum;
        }

        int mid = (l + r) >> 1;
        if (mid >= ql && mid < qr)
        {
            return query(ql, qr, node[o].lson, l, mid) + query(ql, qr, node[o].rson, mid + 1, r);
        }
        if (mid >= ql)
        {
            return query(ql, qr, node[o].lson, l, mid);
        }
        if (mid < qr)
        {
            return query(ql, qr, node[o].rson, mid + 1, r);
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
            return void(node[x].sum += node[o].sum);
        }

        int mid = (l + r) >> 1;

        merge(node[x].lson, node[o].lson, l, mid);
        merge(node[x].rson, node[o].rson, mid + 1, r);

        pushup(x);
    }
    void solve(int u)
    {
        update(dep[u], 1, root[u]);
        for (auto v : e[u])
        {
            solve(v);
            merge(root[u], root[v]);
        }

        for (auto i : q[u])
        {
            ans[i.second] = query(dep[u] + i.first, dep[u] + i.first, root[u]) - 1;
        }
    }

    int main()
    {
        read(n);
        for (int i = 1; i <= n; i++)
        {
            e[readi()].push_back(i);
        }

        dfs(0, 0);

        read(m);
        for (int i = 1; i <= m; i++)
        {
            int u = readi(), p = readi(), father = find(u, p);
            if (father != 0)
            {
                q[father].push_back({p, i});
            }
        }

        solve(0);

        writeAll(ans + 1, ans + m + 1);

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}