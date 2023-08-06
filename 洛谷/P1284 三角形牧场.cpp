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
    const int MAXN = 40 + 5;
    int n;
    int ans = -1;
    int sum;
    int len[MAXN];
    int dp[MAXN * MAXN][MAXN * MAXN];
    bool check(int a, int b, int c)
    {
        return (a + b) > c && (a + c) > b && (b + c) > a;
    }
    double Halen(double a, double b, double c)
    {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
    int main()
    {
        using input::read;
        using output::write;
        read(n);
        for (int i = 1; i <= n; i++)
        {
            read(len[i]);
            sum += len[i];
        }
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = sum / 2; j >= 0; j--)
            {
                for (int k = sum / 2; k >= 0; k--)
                {
                    if (j - len[i] >= 0)
                    {
                        dp[j][k] = dp[j][k] || dp[j - len[i]][k];
                    }
                    if (k - len[i] >= 0)
                    {
                        dp[j][k] = dp[j][k] || dp[j][k - len[i]];
                    }
                }
            }
        }
        for (int i = 1; i <= sum / 2; i++)
        {
            for (int j = 1; j <= sum / 2; j++)
            {
                if (check(i, j, sum - i - j) && dp[i][j])
                {
                    ans = std::max(ans, (int)(Halen(i, j, sum - i - j) * 100));
                }
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