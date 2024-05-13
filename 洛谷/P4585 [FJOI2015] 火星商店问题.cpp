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
    const int MAXTRIE = 4e7 + 5;
    const int INF     = 0x3f3f3f3f;

    int n, m, t;
    int op[MAXN];

    struct TrieNode
    {
        int son[2], time;
    };

    int size = 0;
    TrieNode trie[MAXTRIE];
    void insert(int o, int time, int v)
    {
        for (int i = 20; i >= 1; i--)
        {

            int now = (v >> (i - 1)) & 1;
            if (trie[o].son[now] == 0)
            {
                trie[o].son[now] = ++size;
            }

            o = trie[o].son[now];
            trie[o].time = std::max(trie[o].time, time);
        }
    }
    int find(int o, int time, int v)
    {
        int res = 0;

        for (int i = 20; i >= 1; i--)
        {
            int now = (v >> (i - 1)) & 1;
            if (trie[o].son[now ^ 1] != 0 && trie[trie[o].son[now ^ 1]].time >= time)
            {
                o = trie[o].son[now ^ 1], res = res << 1 | 1;
            }
            else
            {
                o = trie[o].son[now], res = res << 1;
            }
        }

        return res;
    }

    struct Node
    {
        int id;
    };

    Node node[MAXN << 2];
    void build(int o = 1, int l = 1, int r = n)
    {
        node[o].id = ++size;

        if (l == r)
        {
            return;
        }

        int mid = (l + r) >> 1;
        build(o << 1, l, mid), build(o << 1 | 1, mid + 1, r);
    }
    void update(int x, int time, int v, int o = 1, int l = 1, int r = n)
    {
        insert(node[o].id, time, v);

        if (l == r)
        {
            return;
        }

        int mid = (l + r) >> 1;
        if (x <= mid)
        {
            update(x, time, v, o << 1, l, mid);
        }
        else
        {
            update(x, time, v, o << 1 | 1, mid + 1, r);
        }
    }
    int query(int ql, int qr, int time, int v, int o = 1, int l = 1, int r = n)
    {
        if (ql <= l && r <= qr)
        {
            return find(node[o].id, time, v);
        }

        int mid = (l + r) >> 1;
        if (mid >= ql && mid < qr)
        {
            return std::max(query(ql, qr, time, v, o << 1, l, mid), query(ql, qr, time, v, o << 1 | 1, mid + 1, r));
        }
        if (mid >= ql)
        {
            return query(ql, qr, time, v, o << 1, l, mid);
        }
        if (mid < qr)
        {
            return query(ql, qr, time, v, o << 1 | 1, mid + 1, r);
        }

        return -INF;
    }

    int main()
    {
        read(n, m);

        build();

        for (int i = 1; i <= n; i++)
        {
            update(i, INF, readi());
        }

        t = 1;
        for (int i = 1; i <= m; i++)
        {
            op[i] = readi();

            if (op[i] == 0)
            {
                t++;
            }

            if (op[i] == 0)
            {
                int x = readi(), v = readi();
                update(x, t, v);
            }
            if (op[i] == 1)
            {
                int l = readi(), r = readi(), v = readi(), time = readi();
                write(query(l, r, t - time + 1, v));
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