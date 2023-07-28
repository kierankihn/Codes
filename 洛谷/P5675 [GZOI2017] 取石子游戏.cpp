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
    const int MAXV = 256 + 5;
    const int LZH = 1e9 + 7;
    LL ans = 0;
    int n;
    int nums[MAXN];
    int dp[MAXN][MAXV];
    int main()
    {
        using input::read;
        using output::write;
        read(n);
        for (int i = 1; i <= n; i++)
        {
            read(nums[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            std::memset(dp, 0, sizeof(dp));
            dp[0][0] = 1;
            for (int j = 1; j <= n; j++)
            {
                for (int k = 0; k < 256; k++)
                {
                    if (i == j)
                    {
                        dp[j][k] = dp[j - 1][k];
                    }
                    else
                    {
                        dp[j][k] = dp[j - 1][k] + dp[j - 1][k ^ nums[j]];
                    }
                    dp[j][k] %= LZH;
                }
            }
            for (int j = nums[i]; j < 256; j++)
            {
                ans += dp[n][j];
                ans %= LZH;
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