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
    const int MAXN = 200 + 5;
    const int INF = 0x3f3f3f3f;
    using input::read;
    using output::write;
    int dp[MAXN][MAXN][MAXN][2];
    int n, m;
    int ans = 0;
    int pos[MAXN];
    int time[MAXN];
    int main()
    {
        std::memset(dp, 0x3f, sizeof(dp));
        read(n, m);
        for (int i = 1; i <= n; i++)
        {
            read(pos[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            read(time[i]);
        }
        pos[n + 1] = m;
        if (pos[1] <= time[1])
        {
            dp[1][0][1][0] = pos[1];
        }
        else
        {
            dp[1][0][0][0] = pos[1];
        }
        if (m - pos[n] <= time[n])
        {
            dp[0][1][1][1] = m - pos[n];
        }
        else
        {
            dp[0][1][0][1] = m - pos[n];
        }
        for (int len = 0; len < n; len++)
        {
            for (int l = 0; l <= n; l++)
            {
                for (int r = 0; l + r <= n; r++)
                {
                    int tmp = 0;
                    // write(l, r, len, dp[l][r][len][0], dp[l][r][len][1]);
                    if (dp[l][r][len][0] < INF || dp[l][r][len][1] < INF)
                    {
                        ans = std::max(ans, len);
                    }
                    tmp = (dp[l][r][len][0] + pos[l + 1] - pos[l] <= time[l + 1]) ? 1 : 0;
                    dp[l + 1][r][len + tmp][0] = std::min(dp[l + 1][r][len + tmp][0], dp[l][r][len][0] + pos[l + 1] - pos[l]);
                    tmp = (dp[l][r][len][1] + m + pos[l + 1] - pos[n - r + 1] <= time[l + 1]) ? 1 : 0;
                    dp[l + 1][r][len + tmp][0] = std::min(dp[l + 1][r][len + tmp][0], dp[l][r][len][1] + m + pos[l + 1] - pos[n - r + 1]);
                    tmp = (dp[l][r][len][1] + pos[n - r + 1] - pos[n - r] <= time[n - r]) ? 1 : 0;
                    dp[l][r + 1][len + tmp][1] = std::min(dp[l][r + 1][len + tmp][1], dp[l][r][len][1] + pos[n - r + 1] - pos[n - r]);
                    tmp = (dp[l][r][len][0] + m + pos[l] - pos[n - r] <= time[n - r]) ? 1 : 0;
                    dp[l][r + 1][len + tmp][1] = std::min(dp[l][r + 1][len + tmp][1], dp[l][r][len][0] + m + pos[l] - pos[n - r]);
                }
            }
        }
        for (int l = 0; l <= n; l++)
        {
            int r = n - l;
            if (dp[l][r][n][0] < INF || dp[l][r][n][1] < INF)
            {
                ans = std::max(ans, n);
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