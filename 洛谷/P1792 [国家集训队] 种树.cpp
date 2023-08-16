#include <bits/stdc++.h>
namespace input
{
    template <typename T>
    void read(T &x)
    {
        T res = 0, s = 1;
        char ch;
        while ((ch = getchar()) < '0' || ch > '9')
            if (ch == '-')
                s = -1;
        while (ch >= '0' && ch <= '9')
            res = res * 10 + ch - '0', ch = getchar();
        x = res * s;
    }
    template <typename First, typename... Rest>
    void read(First &first, Rest &...rest)
    {
        read(first);
        read(rest...);
    }
}
namespace output
{
    void write()
    {
        putchar('\n');
    }
    void write(char ch)
    {
        putchar(ch);
    }
    template <typename T>
    void write(char delimiter, T x)
    {
        if (x < 0)
            putchar('-'), x = -x;
        if (x > 9)
            write(delimiter, x / 10);
        putchar((x % 10) + '0');
    }
    template <typename First, typename... Rest>
    void write(char delimiter, First &first, Rest &...rest)
    {
        write(delimiter, first);
        putchar(delimiter);
        if (sizeof...(rest) >= 1)
        {
            write(delimiter, rest...);
        }
    }
    template <typename First, typename... Rest>
    void write(char delimiter, char linedelimiter, First &first, Rest &...rest)
    {
        write(delimiter, first);
        putchar(delimiter);
        if (sizeof...(rest) >= 1)
        {
            write(delimiter, rest...);
        }
        putchar(linedelimiter);
    }
    template <typename... T>
    void write(T... t)
    {
        write(' ', '\n', t...);
    }
}
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e6 + 5;
    int n, k;
    int tot = 0;
    LL ans = 0;
    bool vis[MAXN];
    struct Node
    {
        int id;
        LL val;
        int l, r;
        Node() {}
        Node(int id_, int val_, int l_, int r_) : id(id_), val(val_), l(l_), r(r_) {}
    };
    Node node[MAXN];
    struct Cmp
    {
        bool operator()(int a, int b)
        {
            return node[a].val < node[b].val;
        }
    };
    std::priority_queue<int, std::vector<int>, Cmp> q;
    int main()
    {
        using input::read;
        using output::write;
        read(n, k);
        tot = n;
        for (int i = 1; i <= n; i++)
        {
            node[i].id = i, node[i].l = i - 1, node[i].r = i + 1;
            read(node[i].val);
            q.push(i);
        }
        node[1].l = n, node[n].r = 1;
        if (k > n / 2)
        {
            std::cout << "Error!" << std::endl;
            return 0;
        }
        while (k--)
        {
            Node u = node[q.top()];
            q.pop();
            while (vis[u.id])
            {
                u = node[q.top()];
                q.pop();
            }
            vis[u.id] = true, vis[u.l] = vis[u.r] = true;
            ans += u.val;
            tot++;
            node[tot].id = tot;
            node[tot].val = node[u.l].val + node[u.r].val - u.val;
            node[tot].l = node[u.l].l, node[tot].r = node[u.r].r;
            node[node[tot].l].r = tot, node[node[tot].r].l = tot;
            q.push(tot);
        }
        write(ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}