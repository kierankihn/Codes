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
    const int MAXN = 30 + 5;
    int n;
    int val[MAXN];
    LL dp[MAXN][MAXN];
    LL ans[MAXN][MAXN];
    LL getSubtreeScore(int l, int r, int mid)
    {
        LL res = 1;
        if (l < mid)
        {
            res = res * dp[l][mid - 1];
        }
        if (mid < r)
        {
            res = res * dp[mid + 1][r];
        }
        res += val[mid];
        return res;
    }
    void print(int l, int r)
    {
        std::cout << ans[l][r] << " ";
        if (l != r)
        {
            if (ans[l][r] != l)
            {
                print(l, ans[l][r] - 1);
            }
            if (ans[l][r] != r)
            {
                print(ans[l][r] + 1, r);
            }
        }
    }
    int main()
    {
        read(n);
        for (int i = 1; i <= n; i++)
        {
            read(val[i]);
            dp[i][i] = val[i];
            ans[i][i] = i;
        }
        for (int len = 2; len <= n; len++)
        {
            for (int l = 1; l + len - 1 <= n; l++)
            {
                int r = l + len - 1;
                for (int mid = l; mid <= r; mid++)
                {
                    int tmp = getSubtreeScore(l, r, mid);
                    if (tmp > dp[l][r])
                    {
                        dp[l][r] = tmp;
                        ans[l][r] = mid;
                    }
                }
            }
        }
        write(dp[1][n]);
        print(1, n);
        std::cout << std::endl;
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}