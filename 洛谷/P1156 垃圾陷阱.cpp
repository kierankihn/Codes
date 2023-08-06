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
    const int MAXG = 100 + 5;
    const int MAXD = 100 + 5;
    const int MAXT = 1000 + 5;
    int d, g;
    int maxh, maxt;
    struct Node
    {
        int t, f, h;
        Node () {}
        Node (int t_, int f_, int h_) : t(t_), f(f_), h(h_) {}
        bool operator<(Node a)
        {
            return t < a.t;
        }
    };
    Node node[MAXG];
    int s = 0;
    int dp[MAXG][MAXD];
    int main()
    {
        using input::read;
        using output::write;
        read(d, g);
        for (int i = 1; i <= g; i++)
        {
            read(node[i].t, node[i].f, node[i].h);
        }
        std::sort(node + 1, node + g + 1);
        dp[0][0] = 10;
        for (int i = 1; i <= g; i++)
        {
            for (int j = 0; j <= d; j++)
            {
                if (j - node[i].h >= 0 && dp[i - 1][j - node[i].h] >= node[i].t)
                {
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][j - node[i].h]);
                }
                if (dp[i - 1][j] >= node[i].t)
                {
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][j] + node[i].f);
                }
            }
        }
        for (int i = 1; i <= g; i++)
        {
            for (int j = 0; j <= d; j++)
            {
                if (dp[i][j] >= node[i].t)
                {
                    maxh = std::max(maxh, j);
                }
                if (maxh >= d)
                {
                    write(node[i].t);
                    return 0;
                }
                maxt = std::max(maxt, dp[i][j]);
            }
        }
        write(maxt);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}