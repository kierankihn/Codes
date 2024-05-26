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
    const int MOD = 998244353;
    using input::read;
    using output::write;
    int lena, lenb;
    int ans = 0;
    char a[MAXN], b[MAXN];
    int dp[MAXN][MAXN][2][4];
    void add(int &a, int b)
    {
        a += b;
        a -= (a >= MOD ? MOD : 0);
    }
    int main()
    {
        std::cin >> (a + 1) >> (b + 1);
        lena = strlen(a + 1), lenb = strlen(b + 1);
        for (int i = 0; i <= lena; i++)
        {
            for (int j = 0; j <= lenb; j++)
            {
                if (i < lena)
                {
                    add(dp[i + 1][j][0][1], 1);
                }
                if (j < lenb)
                {
                    add(dp[i][j + 1][1][2], 1);
                }
                for (int k = 0; k <= 3; k++)
                {
                    if (i < lena)
                    {
                        if (a[i + 1] != b[j])
                        {
                            add(dp[i + 1][j][0][k | 1], dp[i][j][1][k]);
                        }
                        if (a[i + 1] != a[i])
                        {
                            add(dp[i + 1][j][0][k | 1], dp[i][j][0][k]);
                        }
                    }
                    if (j < lenb)
                    {
                        if (b[j + 1] != a[i])
                        {
                            add(dp[i][j + 1][1][k | 2], dp[i][j][0][k]);
                        }
                        if (b[j + 1] != b[j])
                        {
                            add(dp[i][j + 1][1][k | 2], dp[i][j][1][k]);
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= lena; i++)
        {
            for (int j = 1; j <= lenb; j++)
            {
                add(ans, dp[i][j][0][3]), add(ans, dp[i][j][1][3]);
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