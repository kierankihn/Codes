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
    const int MAXN = 1e3 + 5;
    const int MAXV = 6e3 + 5;
    int n;
    int ans = INF;
    int sum = 0;
    int minval = INF;
    int s1[MAXN], s2[MAXN];
    int dp[MAXN][MAXV];
    int main()
    {
        memset(dp, 0x3f, sizeof(dp));
        read(n);
        for (int i = 1; i <= n; i++)
        {
            read(s1[i], s2[i]);
            sum += s1[i] + s2[i];
        }
        dp[1][s1[1]] = 0, dp[1][s2[1]] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = i; j <= 6 * i; j++)
            {
                if (j - s1[i] >= 0)
                {
                    dp[i][j] = std::min(dp[i][j], dp[i - 1][j - s1[i]]);
                }
                if (j - s2[i] >= 0)
                {
                    dp[i][j] = std::min(dp[i][j], dp[i - 1][j - s2[i]] + 1);
                }
            }
        }
        for (int i = n; i <= 6 * n; i++)
        {
            if (dp[n][i] < INF && std::abs(sum - i - i) < minval)
            {
                minval = std::abs(sum - i - i);
                ans = dp[n][i];
            }
            if (dp[n][i] < INF && std::abs(sum - i - i) == minval)
            {
                ans = std::min(ans, dp[n][i]);
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