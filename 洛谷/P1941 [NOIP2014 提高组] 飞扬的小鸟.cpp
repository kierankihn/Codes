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
    const int MAXN = 1e4 + 5;
    const int MAXM = 1e3 + 5;
    const int INF = 0x3f3f3f3f;
    struct Node
    {
        int up, down, x;
    };
    bool operator<(const Node a, const Node b)
    {
        return a.x < b.x;
    }
    int x[MAXN], y[MAXN];
    int sum = 0, ans = INF;
    int n, m, k;
    Node node[MAXN];
    int pipe[MAXN][MAXM];
    int dp[MAXN][MAXM];
    void init()
    {
        std::memset(dp, 0x3f, sizeof(dp));
        for (int i = 1; i <= k; i++)
        {
            for (int j = 0; j <= node[i].down; j++)
            {
                pipe[node[i].x][j] = true;
            }
            for (int j = node[i].up; j <= m; j++)
            {
                pipe[node[i].x][j] = true;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            pipe[i][0] = true;
        }
        for (int i = 1; i <= m; i++)
        {
            dp[0][i] = 0;
        }
    }
    int main()
    {
        read(n, m, k);
        for (int i = 0; i < n; i++)
        {
            read(x[i], y[i]);
        }
        for (int i = 1; i <= k; i++)
        {
            read(node[i].x, node[i].down, node[i].up);
        }
        init();
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (j - x[i - 1] > 0)
                {
                    dp[i][j] = std::min(dp[i - 1][j - x[i - 1]] + 1, dp[i][j]);
                    dp[i][j] = std::min(dp[i][j - x[i - 1]] + 1, dp[i][j]);
                }
                if (j == m)
                {
                    for (int z = m - x[i - 1]; z <= m; z++)
                    {
                        dp[i][j] = std::min(dp[i][j], dp[i][z] + 1);
                        dp[i][j] = std::min(dp[i][j], dp[i - 1][z] + 1);
                    }
                }
            }
            for (int j = 1; j <= m; j++)
            {
                if (j + y[i - 1] <= m)
                {
                    dp[i][j] = std::min(dp[i - 1][j + y[i - 1]], dp[i][j]);
                }
            }
            for (int j = 1; j <= m; j++)
            {
                if (pipe[i][j])
                {
                    dp[i][j] = INF;
                }
                if (dp[i][j] != INF)
                {
                    sum = i;
                }
            }
        }
        for (int i = 1; i <= m; i++)
        {
            if (dp[n][i] != INF)
            {
                sum = n;
            }
            ans = std::min(ans, dp[n][i]);
        }
        if (sum == n)
        {
            write(1), write(ans);
        }
        else
        {
            ans = 0;
            for (int i = 1; i <= k; i++)
            {
                if (node[i].x <= sum)
                {
                    ans++;
                }
            }
            write(0), write(ans);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}