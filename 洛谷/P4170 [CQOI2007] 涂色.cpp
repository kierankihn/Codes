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
    const int MAXN = 50 + 5;
    int n;
    std::string s;
    int dp[MAXN][MAXN];
    int main()
    {
        std::memset(dp, 0x3f, sizeof(dp));
        std::cin >> s;
        n = s.size();
        for (int i = 1; i <= n; i++)
        {
            dp[i][i] = 1;
        }
        for (int len = 2; len <= n; len++)
        {
            for (int l = 1; l + len - 1 <= n; l++)
            {
                int r = l + len - 1;
                if (s[l - 1] == s[r - 1])
                {
                    dp[l][r] = std::min(dp[l][r], dp[l][r - 1]);
                    dp[l][r] = std::min(dp[l][r], dp[l + 1][r]);
                }
                for (int k = l; k < r; k++)
                {
                    dp[l][r] = std::min(dp[l][r], dp[l][k] + dp[k + 1][r]);
                }
            }
        }
        write(dp[1][n]);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}