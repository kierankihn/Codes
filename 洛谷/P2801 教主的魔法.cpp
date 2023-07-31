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
    LL n, m;
    LL a[MAXN];
    LL len, tot;
    LL val[MAXN], tag[MAXN], pos[MAXN], L[MAXN], R[MAXN];
    void copyBlock(int id)
    {
        for (int i = L[id]; i <= R[id]; i++)
        {
            val[i] = a[i];
        }
        std::sort(val + L[id], val + R[id] + 1);
    }
    void init()
    {
        len = std::sqrt(n);
        for (int i = 1; i <= n; i += len)
        {
            L[++tot] = i, R[tot] = std::min(i + len - 1, n);
            for (int j = L[tot]; j <= R[tot]; j++)
            {
                pos[j] = tot;
            }
        }
        for (int i = 1; i <= tot; i++)
        {
            copyBlock(i);
        }
    }
    void update(int l, int r, int v)
    {
        if (pos[l] == pos[r])
        {
            for (int i = l; i <= r; i++)
            {
                a[i] += v;
            }
            copyBlock(pos[l]);
            return;
        }
        for (int i = l; i <= R[pos[l]]; i++)
        {
            a[i] += v;
        }
        for (int i = L[pos[r]]; i <= r; i++)
        {
            a[i] += v;
        }
        copyBlock(pos[l]), copyBlock(pos[r]);
        for (int i = pos[l] + 1; i < pos[r]; i++)
        {
            tag[i] += v;
        }
    }
    int query(int l, int r, int v)
    {
        int res = 0;
        if (pos[l] == pos[r])
        {
            for (int i = l; i <= r; i++)
            {
                if (tag[pos[l]] + a[i] >= v)
                {
                    res++;
                }
            }
            return res;
        }
        for (int i = l; i <= R[pos[l]]; i++)
        {
            if (a[i] + tag[pos[l]] >= v)
            {
                res++;
            }
        }
        for (int i = L[pos[r]]; i <= r; i++)
        {
            if (a[i] + tag[pos[r]] >= v)
            {
                res++;
            }
        }
        for (int i = pos[l] + 1; i < pos[r]; i++)
        {
            int ql = L[i], qr = R[i];
            while (ql <= qr)
            {
                int mid = (ql + qr) >> 1;
                if (val[mid] + tag[i] < v)
                {
                    ql = mid + 1;
                }
                else
                {
                    qr = mid - 1;
                }
            }
            res += R[i] - ql + 1;
        }
        return res;
    }
    int main()
    {
        using input::read;
        using output::write;
        read(n, m);
        for (int i = 1; i <= n; i++)
        {
            read(a[i]);
        }
        init();
        for (int i = 1; i <= m; i++)
        {
            std::string op;
            std::cin >> op;
            if (op == "M")
            {
                int l, r, v;
                read(l, r, v);
                update(l, r, v);
            }
            if (op == "A")
            {
                int l, r, v;
                read(l, r, v);
                write(query(l, r, v));
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