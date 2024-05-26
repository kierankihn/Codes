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
    const int MAXN = 1000 + 5;
    int n, k;
    int val[MAXN];
    int main()
    {
        using input::read;
        using output::write;
        read(n, k);
        val[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            int tmp1, tmp2;
            putchar('?'), putchar(' ');
            if (i <= k + 1)
            {
                for (int j = 2; j <= k + 1; j++)
                {
                    write(' ', j), putchar(' ');
                }
            }
            else
            {
                write(' ', i), putchar(' ');
                for (int j = 2; j <= k; j++)
                {
                    write(' ', j), putchar(' ');
                }
            }
            putchar('\n');
            read(tmp1);
            putchar('?'), putchar(' ');
            write(' ', 1), putchar(' ');
            if (i <= k + 1)
            {
                for (int j = 2; j <= k + 1; j++)
                {
                    if (i != j)
                    {
                        write(' ', j), putchar(' ');
                    }
                }
            }
            else
            {
                for (int j = 2; j <= k; j++)
                {
                    write(' ', j), putchar(' ');
                }
            }
            putchar('\n');
            read(tmp2);
            if (tmp1 && tmp2)
            {
                val[i] = 1;
            }
            else
            {
                val[i] = 0;
            }
        }
        putchar('!'), putchar(' ');
        for (int i = 1; i <= n; i++)
        {
            write(' ', val[i]), putchar(' ');
        }
        putchar('\n');
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}