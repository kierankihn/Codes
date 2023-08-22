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
    const int MAXN = 300 + 5;
    const int MAXM = 45000 + 5;
    using input::read;
    using output::write;
    int n, m;
    int w[MAXM];
    int dp[MAXN][MAXN];
    int pie[MAXN][MAXN][MAXN];
    int main()
    {
        read(n, m);
        for (int i = 1; i <= m; i++)
        {
            int l, r;
            read(w[i], l, r);
            for (int j = l; j <= r; j++)
            {
                pie[l][r][j] = w[i];
            }
        }
        for (int len = 1; len <= n; len++)
        {
            for (int l = 1; l + len - 1 <= n; l++)
            {
                int r = l + len - 1;
                for (int k = l; k <= r; k++)
                {
                    if (l > 1)
                    {
                        pie[l - 1][r][k] = std::max(pie[l - 1][r][k], pie[l][r][k]);
                    }
                    if (r < n)
                    {
                        pie[l][r + 1][k] = std::max(pie[l][r + 1][k], pie[l][r][k]);
                    }
                }
            }
        }
        for (int len = 1; len <= n; len++)
        {
            for (int l = 1; l + len - 1 <= n; l++)
            {
                int r = l + len - 1;
                for (int k = l; k <= r; k++)
                {
                    dp[l][r] = std::max(dp[l][r], (k - 1 >= l ? dp[l][k - 1] : 0) + (k + 1 <= r ? dp[k + 1][r] : 0) + pie[l][r][k]);
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