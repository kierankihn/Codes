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
    const int MAXN = 400 + 5;
    const int MAXV = 800000 + 5;
    const int DELTA = 400000;
    const int INF = 0x3f3f3f3f;
    int n;
    int ans = 0;
    int maxs = 0, mins = 0;
    int s[MAXN], f[MAXN];
    int dp[2][MAXV];
    int now = 1, pre = 0;
    int main()
    {
        using input::read;
        using output::write;
        std::memset(dp, 0x80, sizeof(dp));
        dp[0][DELTA] = 0;
        read(n);
        for (int i = 1; i <= n; i++)
        {
            read(s[i], f[i]);
            maxs += std::max(s[i], 0), mins += std::min(0, s[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = maxs; j >= mins; j--)
            {
                dp[now][j + DELTA] = std::max(dp[now][j + DELTA], dp[pre][j + DELTA]);
                dp[now][j + DELTA] = std::max(dp[now][j + DELTA], dp[pre][j + DELTA - s[i]] + f[i]);
            }
            std::swap(now, pre);
        }
        for (int i = 0; i <= maxs; i++)
        {
            if (dp[pre][i + DELTA] >= 0)
            {
                ans = std::max(ans, dp[pre][i + DELTA] + i);
            }
        }
        write(ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}