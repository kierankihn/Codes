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
    typedef __int128 LL;
    const int MAXN = 700 + 5;
    const int MOD = 1e9 + 7;
    using input::read;
    using output::write;
    std::string str;
    int n;
    LL ans = 0;
    std::stack<int> s;
    LL nxt[MAXN];
    LL idx[MAXN];
    LL dp[MAXN][MAXN][3][3];
    bool checkIsMatch(int x, int y)
    {
        return 0 < (x | y) && (x | y) < 3 && (x != y);
    }
    bool checkIsAdjacent(int x, int y)
    {
        return x != y || (x == 0 && y == 0);
    }
    int main()
    {
        std::getline(std::cin, str);
        n = str.size();
        str = '\0' + str;
        for (int i = 1; i <= n; i++)
        {
            if (str[i] == '(')
            {
                s.push(i);
                idx[i] = ++idx[0];
            }
            else
            {
                nxt[i] = s.top(), nxt[s.top()] = i;
                idx[i] = idx[s.top()];
                s.pop();
            }
        }
        for (int i = 1; i < n; i++)
        {
            if (idx[i] == idx[i + 1])
            {
                dp[i][i + 1][1][0] = dp[i][i + 1][2][0] = dp[i][i + 1][0][1] = dp[i][i + 1][0][2] = 1;
            }
        }
        for (int len = 3; len <= n; len++)
        {
            for (int l = 1; l + len - 1 <= n; l++)
            {
                int r = l + len - 1;
                if (idx[l] == idx[r])
                {
                    for (int i = 0; i <= 2; i++)
                    {
                        for (int j = 0; j <= 2; j++)
                        {
                            if (checkIsMatch(i, j))
                            {
                                for (int p = 0; p <= 2; p++)
                                {
                                    for (int q = 0; q <= 2; q++)
                                    {
                                        if (checkIsAdjacent(i, p) && checkIsAdjacent(q, j))
                                        {
                                            dp[l][r][i][j] += dp[l + 1][r - 1][p][q];
                                            dp[l][r][i][j] %= MOD;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                else
                {
                    if (str[l] == ')' || str[r] == '(')
                    {
                        continue;
                    }
                    for (int i = 0; i <= 2; i++)
                    {
                        for (int j = 0; j <= 2; j++)
                        {
                            for (int p = 0; p <= 2; p++)
                            {
                                for (int q = 0; q <= 2; q++)
                                {
                                    if (checkIsMatch(i, p) && checkIsMatch(q, j))
                                    {
                                        if (nxt[l] + 1 == nxt[r])
                                        {
                                            if (checkIsAdjacent(p, q))
                                            {
                                                dp[l][r][i][j] += dp[l][nxt[l]][i][p] * dp[nxt[r]][r][q][j];
                                                dp[l][r][i][j] %= MOD;
                                            }
                                        }
                                        else
                                        {
                                            for (int a = 0; a <= 2; a++)
                                            {
                                                for (int b = 0; b <= 2; b++)
                                                {
                                                    if (checkIsAdjacent(p, a) && checkIsAdjacent(b, q))
                                                    {
                                                        dp[l][r][i][j] += dp[l][nxt[l]][i][p] * dp[nxt[l] + 1][nxt[r] - 1][a][b] * dp[nxt[r]][r][q][j];
                                                        dp[l][r][i][j] %= MOD;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i <= 2; i++)
        {
            for (int j = 0; j <= 2; j++)
            {
                if (idx[1] != idx[n] || (0 < (i | j) && (i | j) < 3))
                {
                    ans += dp[1][n][i][j];
                    ans %= MOD;
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