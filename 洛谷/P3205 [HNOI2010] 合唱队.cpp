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
    const int MOD = 19650827;
    using input::read;
    using output::write;
    int n;
    int h[MAXN];
    int dp[MAXN][MAXN][2];
    int main()
    {
        read(n);
        for (int i = 1; i <= n; i++)
        {
            read(h[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            dp[i][i][0] = 1;
        }
        for (int len = 2; len <= n; len++)
        {
            for (int l = 1; l + len - 1 <= n; l++)
            {
                int r = l + len - 1;
                if (h[l] < h[l + 1])
                {
                    dp[l][r][0] += dp[l + 1][r][0];
                }
                if (h[l] < h[r])
                {
                    dp[l][r][0] += dp[l + 1][r][1];
                }
                if (h[r] > h[r - 1])
                {
                    dp[l][r][1] += dp[l][r - 1][1];
                }
                if (h[r] > h[l])
                {
                    dp[l][r][1] += dp[l][r - 1][0];
                }
                dp[l][r][0] %= MOD, dp[l][r][1] %= MOD;
            }
        }
        write((dp[1][n][0] + dp[1][n][1]) % MOD);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}