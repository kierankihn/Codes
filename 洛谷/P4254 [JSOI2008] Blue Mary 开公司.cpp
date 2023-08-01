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
    const int MAXN = 1e5 + 5;
    const int MAXT = 5e4 + 5;
    struct Fuction
    {
        double k, b;
        Fuction() {}
        Fuction(double k_, double b_) : k(k_), b(b_) {}
        double v(int x)
        {
            return k * (x - 1) + b;
        }
    };
    int n;
    int tot;
    Fuction f[MAXN];
    int val[MAXT << 2];
    void update(int o, int l, int r, int id)
    {
        if (l == r)
        {
            if (f[id].v(l) > f[val[o]].v(l))
            {
                val[o] = id;
            }
            return;
        }
        int mid = (l + r) >> 1;
        if (f[id].k > f[val[o]].k)
        {
            if (f[id].v(mid) > f[val[o]].v(mid))
            {
                update(o << 1, l, mid, val[o]);
                val[o] = id;
            }
            else
            {
                update(o << 1 | 1, mid + 1, r, id);
            }
        }
        else
        {
            if (f[id].v(mid) > f[val[o]].v(mid))
            {
                update(o << 1 | 1, mid + 1, r, val[o]);
                val[o] = id;
            }
            else
            {
                update(o << 1, l, mid, id);
            }
        }
    }
    void update(int id)
    {
        update(1, 1, 5e4, id);
    }
    double query(int o, int l, int r, int x)
    {
        if (l == r)
        {
            return f[val[o]].v(x);
        }
        int mid = (l + r) >> 1;
        if (x <= mid)
        {
            return std::max(f[val[o]].v(x), query(o << 1, l, mid, x));
        }
        if (x > mid)
        {
            return std::max(f[val[o]].v(x), query(o << 1 | 1, mid + 1, r, x));
        }
        return 0;
    }
    double query(int x)
    {
        return query(1, 1, 5e4, x);
    }
    int main()
    {
        using input::read;
        using output::write;
        std::cin >> n;
        for (int i = 1; i <= n; i++)
        {
            std::string op;
            std::cin >> op;
            if (op == "Project")
            {
                double s, p;
                std::cin >> s >> p;
                f[++tot] = Fuction(p, s);
                update(tot);
            }
            if (op == "Query")
            {
                double x;
                std::cin >> x;
                std::cout << (int)query(x) / 100 << std::endl;
            }
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}