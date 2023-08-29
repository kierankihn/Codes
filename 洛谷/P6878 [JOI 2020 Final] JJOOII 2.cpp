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
    const int MAXN = 2e5 + 5;
    const int INF = 0x3f3f3f3f;
    using input::read;
    using output::write;
    int sum[MAXN][4];
    int n, k;
    int ans = INF;
    std::string s;
    int getCharId(char x)
    {
        if (x == 'J')
        {
            return 1;
        }
        if (x == 'O')
        {
            return 2;
        }
        if (x == 'I')
        {
            return 3;
        }
        return 0;
    }
    void getSumArr()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                sum[i][j] = sum[i - 1][j];
            }
            sum[i][getCharId(s[i - 1])]++;
        }
    }
    bool check(int l, int r, int idx)
    {
        return (sum[r][idx] - sum[l - 1][idx] >= k);
    }
    int main()
    {
        read(n, k);
        std::cin >> s;
        getSumArr();
        for (int i = 1; i <= n; i++)
        {
            int l, r, res = i - 1;
            for (int j = 1; j <= 3; j++)
            {
                int start = res + 1, end = n;
                l = start, r = end, res = 0;
                while (l <= r)
                {
                    int mid = (l + r) >> 1;
                    if (check(start, mid, j))
                    {
                        r = mid - 1;
                        res = mid;
                    }
                    else
                    {
                        l = mid + 1;
                    }
                }
                if (res == 0)
                {
                    break;
                }
            }
            if (res != 0)
            {
                ans = std::min(ans, res - i + 1 - k * 3);
            }
        }
        write(ans >= INF ? -1 : ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}
