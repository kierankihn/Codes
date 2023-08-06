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
    const int MAXN = 50 + 5;
    const int MAXT = 2500 + 5;
    using input::read;
    using output::write;
    int n, m, t;
    std::string wood[MAXN];
    int dp[MAXN][MAXN][MAXT];
    int block[MAXN][MAXN][MAXN][2];
    int getNumberOfRightBlock(int id, int l, int len, int color)
    {
        if (block[id][l][len][color])
        {
            return block[id][l][len][color];
        }
        int res = 0;
        for (int i = 0; i < len; i++)
        {
            int pos = l + i;
            if (wood[id][pos] == color + '0')
            {
                res++;
            }
        }
        return block[id][l][len][color] = res;
    }
    int main()
    {
        read(n, m, t);
        for (int i = 1; i <= n; i++)
        {
            std::cin >> wood[i];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= t; j++)
            {
                dp[i][0][j] = dp[i - 1][m][j];
            }
            for (int j = 0; j <= m; j++)
            {
                for (int k = 1; k <= t; k++)
                {
                    for (int len = 1; j + len <= m; len++)
                    {
                        dp[i][j + len][k] = std::max(dp[i][j + len][k], dp[i][j][k - 1] + std::max(getNumberOfRightBlock(i, j, len, 0), getNumberOfRightBlock(i, j, len, 1)));
                    }
                }
            }
        }
        write(dp[n][m][t]);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}