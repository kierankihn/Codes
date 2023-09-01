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
    const int INF = 0x3f3f3f3f;
    using input::read;
    using output::write;
    int t;
    std::string a, b;
    int d;
    int f0, l0, f1, l1;
    int main()
    {
        read(t);
        while (t--)
        {
            std::cin >> a >> b;
            bool flag = true;
            d = INF;
            f0 = f1 = INF, l0 = l1 = -INF;
            for (int i = 0; i < (int)a.size(); i++)
            {
                if (a[i] == '0' && b[i] == '0')
                {
                    f0 = std::min(f0, i), l0 = std::max(l0, i);
                    if (d != INF && f0 < d)
                    {
                        f0 = l0;
                        f1 = INF;
                        d = INF;
                    }
                }
                if (a[i] == '1' && b[i] == '1')
                {
                    f1 = std::min(f1, i), l1 = std::max(l1, i);
                    if (d != INF && f1 < d)
                    {
                        f1 = l1;
                        f0 = INF;
                        d = INF;
                    }
                }
                if (a[i] != b[i])
                {
                    d = std::min(d, i);
                    if (f0 == INF && f1 == INF)
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if (d != INF)
            {
                flag = false;
            }
            if (flag)
            {
                puts("YES");
            }
            else
            {
                puts("NO");
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