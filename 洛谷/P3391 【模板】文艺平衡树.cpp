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
namespace splay
{
    typedef long long LL;
    const int MAXN = 1e5 + 5;
    const int INF = 0x3f3f3f3f;
    enum SON
    {
        LSON = 0,
        RSON = 1
    };
    SON operator^(SON a, int b)
    {
        return (SON)(((int)a) ^ b);
    }
    struct Splay
    {
        LL val;
        LL cnt;
        LL size;
        bool rev;
        int fa;
        int son[2];
    };
    Splay splay[MAXN];
    int root = 0;
    int tot = 0;
    bool operator==(Splay a, Splay b)
    {
        return (a.val == b.val)  && (a.cnt == b.cnt) && (a.size == b.size) && (a.rev == b.rev) && (a.fa == b.fa) && (a.son[LSON] == b.son[LSON]) && (a.son[RSON] == b.son[RSON]);
    }
    bool operator!=(Splay a, Splay b)
    {
        return !(a == b);
    }
    SON check(int x)
    {
        return splay[splay[x].fa].son[LSON] == x ? LSON : RSON;
    }
    void pushup(int x)
    {
        splay[x].size = splay[splay[x].son[LSON]].size + splay[splay[x].son[RSON]].size + 1;
    }
    void pushdown(int x)
    {
        splay[splay[x].son[LSON]].rev ^= splay[x].rev;
        splay[splay[x].son[RSON]].rev ^= splay[x].rev;
        if (splay[x].rev)
        {
            std::swap(splay[x].son[LSON], splay[x].son[RSON]);
        }
        splay[x].rev = false;
    }
    void connect(int a, int b, SON s)
    {
        splay[b].son[s] = a, splay[a].fa = b;
    }
    void rotate(int x)
    {
        int father = splay[x].fa, grandfather = splay[father].fa;
        SON checkfather = check(father), checkx = check(x);
        connect(splay[x].son[checkx ^ 1], father, checkx);
        connect(father, x, checkx ^ 1);
        connect(x, grandfather, checkfather);
        pushup(father), pushup(x);
    }
    void SPlay(int x, int y)
    {
        while (splay[x].fa != y)
        {
            int father = splay[x].fa, grandfather = splay[father].fa;
            if (grandfather != y)
            {
                if (check(x) ^ check(father))
                {
                    rotate(x);
                }
                else
                {
                    rotate(father);
                }
            }
            rotate(x);
        }
        if (y == 0)
        {
            root = x;
        }
    }
    void insert(int v)
    {
        int u = root, father = 0;
        while (u)
        {
            father = u;
            u = v <= splay[u].val ? splay[u].son[LSON] : splay[u].son[RSON];
        }
        u = ++tot;
        if (father)
        {
            splay[father].son[v <= splay[father].val ? LSON : RSON] = u;
        }
        splay[u].val = v;
        splay[u].fa = father;
        splay[u].size = 1;
        SPlay(u, 0);
    }
    void init()
    {
        insert(-INF), insert(INF);
    }
    int queryKth(int k)
    {
        int u = root;
        while (true)
        {
            pushdown(u);
            if (splay[splay[u].son[LSON]].size >= k)
            {
                u = splay[u].son[LSON];
                continue;
            }
            else if (splay[splay[u].son[LSON]].size + 1 == k)
            {
                return u;
            }
            else
            {
                k -= splay[splay[u].son[LSON]].size + 1;
                u = splay[u].son[RSON];
            }
        }
    }
    void solve(int l, int r)
    {
        l = queryKth(l), r = queryKth(r + 2);
        SPlay(l, 0), SPlay(r, l);
        splay[splay[splay[root].son[RSON]].son[LSON]].rev ^= 1;
    }
    void dfs(int u)
    {
        pushdown(u);
        if (splay[u].son[LSON])
        {
            dfs(splay[u].son[LSON]);
        }
        if (-INF < splay[u].val && splay[u].val < INF)
        {
            output::write(' ', splay[u].val), std::putchar(' ');
        }
        if (splay[u].son[RSON])
        {
            dfs(splay[u].son[RSON]);
        }
    }
}
namespace solution
{
    typedef long long LL;
    using input::read;
    using output::write;
    using namespace splay;
    LL n, m;
    int main()
    {
        read(n, m);
        init();
        for (int i = 1; i <= n; i++)
        {
            insert(i);
        }
        for (int i = 1; i <= m; i++)
        {
            int l, r;
            read(l, r);
            solve(l, r);
        }
        dfs(root);
        std::putchar('\n');
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}