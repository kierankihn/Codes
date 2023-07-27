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
// namespace splay
// {
//     typedef long long LL;
//     #define ls(x) node[node[x].son[LSON]]
//     #define rs(x) node[node[x].son[RSON]]
//     enum SON
//     {
//         LSON = 0,
//         RSON = 1
//     };
//     SON operator^(SON a, int b)
//     {
//         if (b)
//         {
//             return a == LSON ? RSON : LSON;
//         }
//         return a;
//     }
//     struct Node
//     {
//         LL val;
//         bool rev;
//         LL size, cnt;
//         int fa, son[2];
//     };
//     bool operator==(const Node a, const Node b)
//     {
//         return a.val == b.val;
//     }
//     bool operator!=(const Node a, const Node b)
//     {
//         return !(a == b);
//     }
//     class Splay
//     {
//     private:
//         static const int MAXN = 8e4 + 5;
//         static const int INF = 0x3f3f3f3f;
//         int root, tot;
//         Node node[MAXN];
//         void connect(int x, int fa, SON s);
//         void pushup(int x);
//         void pushdown(int x);
//         SON check(int x);
//         void rotate(int x);
//         void splay(int x, int fa);

//     public:
//         void init();
//         void insert(int v);
//         void reverse(int l, int r);
//         int queryKth(int k);
//         int queryRank(int v);
//     };
//     void Splay::init()
//     {
//         root = tot = 0;
//         this->insert(INF);
//         this->insert(-INF);
//     }
//     void Splay::connect(int x, int fa, SON s)
//     {
//         node[x].fa = fa;
//         node[fa].son[s] = x;
//     }
//     void Splay::pushup(int x)
//     {
//         node[x].size = ls(x).size + rs(x).size + node[x].cnt;
//     }
//     void Splay::pushdown(int x)
//     {
//         if (node[x].rev)
//         {
//             ls(x).rev ^= node[x].rev, rs(x).rev ^= node[x].rev;
//             std::swap(node[x].son[LSON], node[x].son[RSON]);
//             node[x].rev = false;
//         }
//     }
//     SON Splay::check(int x)
//     {
//         return x == ls(node[x].fa).son[LSON] ? LSON : RSON;
//     }
//     void Splay::rotate(int x)
//     {
//         int father = node[x].fa, grandfather = node[father].fa;
//         SON checkx = check(x), checkfather = check(father);
//         connect(node[x].son[checkx ^ 1], father, checkx);
//         connect(father, x, checkx ^ 1);
//         connect(x, grandfather, checkfather);
//         pushup(father), pushup(x);
//     }
//     void Splay::splay(int x, int fa)
//     {
//         while (node[x].fa != fa)
//         {
//             int father = node[x].fa, grandfather = node[father].fa;
//             if (grandfather)
//             {
//                 if (check(x) ^ check(grandfather))
//                 {
//                     rotate(x);
//                 }
//                 else
//                 {
//                     rotate(father);
//                 }
//             }
//             rotate(x);
//         }
//         if (fa == 0)
//         {
//             root = x;
//         }
//     }
//     void Splay::insert(int v)
//     {
//         int u = root, father = 0;
//         while (u)
//         {
//             father = u;
//             u = (node[u].val <= v) ? node[u].son[LSON] : node[u].son[RSON];
//         }
//         u = ++tot;
//         if (father)
//         {
//             node[father].son[(v <= node[father].val) ? LSON : RSON] = u;
//         }
//         node[u].val = v, node[u].cnt = 1, node[u].fa = father, node[u].val = v, node[u].size = 1;
//         this->splay(u, 0);
//     }
//     void Splay::reverse(int l, int r)
//     {
//         l = queryKth(l), r = queryKth(r + 2);
//         this->splay(l, 0), this->splay(r, l);
//         node[node[node[l].son[RSON]].son[LSON]].rev ^= true;
//     }
//     int Splay::queryKth(int k)
//     {
//         int u = root;
//         while (true)
//         {
//             pushdown(u);
//             if (node[node[u].son[LSON]].size >= k)
//             {
//                 k = node[u].son[LSON];
//             }
//             else if (node[node[u].son[LSON]].size < k && k <= node[node[u].son[LSON]].size + node[u].cnt)
//             {
//                 return u;
//             }
//             else
//             {
//                 k -= node[node[u].son[LSON]].size + node[u].cnt;
//                 u = node[u].son[RSON];
//             }
//         }
//     }
//     int Splay::queryRank(int v)
//     {
//         splay(v + 2, 0);
//         return node[node[root].son[LSON]].size;
//     }
// }
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
        return (a.val == b.val) && (a.cnt == b.cnt) && (a.size == b.size) && (a.rev == b.rev) && (a.fa == b.fa) && (a.son[LSON] == b.son[LSON]) && (a.son[RSON] == b.son[RSON]);
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
        std::stack<int> s;
        int u = x;
        while (u != y)
        {
            s.push(u);
            u = splay[u].fa;
        }
        while (!s.empty())
        {
            pushdown(s.top());
            s.pop();
        }
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
    int queryRank(int v)
    {
        SPlay(v + 2, 0);
        return splay[splay[root].son[LSON]].size;
    }
    void reverse(int l, int r)
    {
        // output::write(l, r);
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
    const int MAXN = 8e4 + 5;
    int n, m;
    int v[MAXN];
    std::map<int, int> r;
    int main()
    {
        using input::read;
        using output::write;
        read(n, m);
        splay::init();
        for (int i = 1; i <= n; i++)
        {
            int val;
            read(val);
            splay::insert(i);
            v[i] = val;
            r[val] = i;
        }
        for (int i = 1; i <= m; i++)
        {
            std::string op;
            std::cin >> op;
            if (op == "Top")
            {
                int x;
                read(x);
                int tmp = splay::queryRank(r[x]);
                splay::reverse(1, tmp);
                splay::reverse(2, tmp);
            }
            if (op == "Bottom")
            {
                int x;
                read(x);
                int tmp = splay::queryRank(r[x]);
                splay::reverse(tmp, n);
                splay::reverse(tmp, n - 1);
            }
            if (op == "Insert")
            {
                int x, t;
                read(x, t);
                int tmp = splay::queryRank(r[x]);
                splay::reverse(std::min(tmp, tmp + t), std::max(tmp, tmp + t));
            }
            if (op == "Ask")
            {
                int x;
                read(x);
                write(splay::queryRank(r[x]) - 1);
            }
            if (op == "Query")
            {
                int x;
                read(x);
                write(v[splay::queryKth(x + 1) - 2]);
            }
            // splay::dfs(splay::root), std::putchar('\n');
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}