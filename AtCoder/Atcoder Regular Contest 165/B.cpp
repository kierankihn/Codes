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
    const int MAXN = 2e5 + 5;
    using input::read;
    using output::write;
    int n, k;
    int p[MAXN];
    int c[MAXN];
    std::set<int> s;
    int main()
    {
        read(n, k);
        for (int i = 1; i <= n; i++)
        {
            read(p[i]);
        }
        for (int i = 1; i <= k; i++)
        {
            s.insert(p[i]);
        }
        for (int i = k + 1; i <= n; i++)
        {
            if (p[i - k] > (*s.begin()))
            {
                c[i - k] = -1;
            }
            else
            {
                auto tmp = s.end();
                tmp--;
                if (p[i] >= (*tmp))
                {
                    c[i - k] = 0;
                }
                else
                {
                    c[i - k] = 1;
                }
            }
            s.erase(p[i - k]), s.insert(p[i]);
        }
        int pos = n - k, cnt = 0, max = 0;
        for (int i = n - k; i >= 1; i--)
        {
            cnt += c[i];
            if (cnt >= max)
            {
                max = cnt;
                pos = i;
            }
        }
        std::sort(p + pos + 1, p + pos + k + 1);
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", p[i]);
        }
        printf("\n");
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}