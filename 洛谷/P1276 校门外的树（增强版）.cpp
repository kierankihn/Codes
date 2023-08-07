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
    using input::read;
    using output::write;
    const int MAXN = 1e4 + 5;
    int n, m;
    int tree[MAXN];
    int sum;
    int ans;
    int main()
    {
        read(n, m);
        for (int i = 0; i <= n; i++)
        {
            tree[i] = 1;
        }
        for (int i = 1; i <= m; i++)
        {
            int l, r, op;
            read(op, l, r);
            if (op == 0)
            {
                for (int j = l; j <= r; j++)
                {
                    if (tree[j] == 2)
                    {
                        ans++;
                    }
                    tree[j] = 0;
                }
            }
            if (op == 1)
            {
                for (int j = l; j <= r; j++)
                {
                    if (tree[j] == 0)
                    {
                        tree[j] = 2;
                    }
                }
            }
        }
        for (int i = 0; i <= n; i++)
        {
            if (tree[i] == 2)
            {
                sum++;
            }
        }
        write(sum), write(ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}