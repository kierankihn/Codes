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
    int n;
    std::vector<int> num;
    LL s[MAXN];
    LL ans[MAXN];
    LL lowbit(int x)
    {
        return x & (-x);
    }
    LL query(int x)
    {
        LL res = 0;
        while (x)
        {
            res = std::max(res, s[x]), x -= lowbit(x);
        }
        return res;
    }
    void update(int x, LL v)
    {
        while (x <= n)
        {
            s[x] = std::max(s[x], v), x += lowbit(x);
        }
    }
    int main()
    {
        using input::read;
        using output::write;
        read(n);
        for (int i = 1; i <= n; i++)
        {
            int pos;
            read(pos);
            num.insert(num.begin() + pos, i);
        }
        for (int i = 0; i < n; i++)
        {
            int tmp = num[i];
            ans[tmp] = query(tmp) + 1;
            update(tmp, ans[tmp]);
        }
        for (int i = 1; i <= n; i++)
        {
            ans[i] = std::max(ans[i - 1], ans[i]);
            write(ans[i]);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}