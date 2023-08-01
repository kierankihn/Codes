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
    typedef int LL;
    const int MAXN = 1e5 + 5;
    const int MAXB = 316 + 5;
    LL n, c, m;
    LL a[MAXN];
    LL ton[MAXN];

    LL len, tot, L[MAXB], R[MAXB], pos[MAXN];
    LL cnt[MAXB][MAXN];
    LL res[MAXB][MAXB];
    void init()
    {
        len = std::sqrt(n);
        for (int i = 1; i <= n; i += len)
        {
            L[++tot] = i, R[tot] = std::min(i + len - 1, n);
        }
        for (int i = 1; i <= n; i++)
        {
            pos[i] = std::ceil((double)i / len);
            cnt[pos[i]][a[i]]++;
        }
        for (int i = 1; i <= tot; i++)
        {
            for (int j = 0; j <= c; j++)
            {
                cnt[i][j] += cnt[i - 1][j];
            }
        }
        for (int i = 1; i <= tot; i++)
        {
            for (int j = i; j <= tot; j++)
            {
                res[i][j] = res[i][j - 1];
                for (int k = L[j]; k <= R[j]; k++)
                {
                    ton[a[k]]++;
                    if (!(ton[a[k]] & 1))
                    {
                        res[i][j]++;
                    }
                    else
                    {
                        if (ton[a[k]] >= 3)
                        {
                            res[i][j]--;
                        }
                    }
                }
            }
            std::memset(ton, 0, sizeof(ton));
        }
    }
    LL query(int l, int r)
    {
        int ans = 0;
        if (pos[l] == pos[r] || pos[l] + 1 == pos[r])
        {
            for (int i = l; i <= r; i++)
            {
                ton[a[i]]++;
                if (ton[a[i]] & 1)
                {
                    if (ton[a[i]] >= 3)
                    {
                        ans--;
                    }
                }
                else
                {
                    ans++;
                }
            }
            for (int i = l; i <= r; i++)
            {
                ton[a[i]]--;
            }
            return ans;
        }
        ans = res[pos[l] + 1][pos[r] - 1];
        for (int i = l; i <= R[pos[l]]; i++)
        {
            ton[a[i]]++;
            int tmp = cnt[pos[r] - 1][a[i]] - cnt[pos[l]][a[i]];
            if ((ton[a[i]] + tmp) & 1)
            {
                if ((ton[a[i]] + tmp) >= 3)
                {
                    ans--;
                }
            }
            else
            {
                ans++;
            }
        }
        for (int i = L[pos[r]]; i <= r; i++)
        {
            ton[a[i]]++;
            int tmp = cnt[pos[r] - 1][a[i]] - cnt[pos[l]][a[i]];
            if ((ton[a[i]] + tmp) & 1)
            {
                if ((ton[a[i]] + tmp) >= 3)
                {
                    ans--;
                }
            }
            else
            {
                ans++;
            }
        }
        for (int i = l; i <= R[pos[l]]; i++)
        {
            ton[a[i]]--;
        }
        for (int i = L[pos[r]]; i <= r; i++)
        {
            ton[a[i]]--;
        }
        return ans;
    }
    int main()
    {
        using input::read;
        using output::write;
        LL ans = 0;
        read(n, c, m);
        for (int i = 1; i <= n; i++)
        {
            read(a[i]);
        }
        init();
        for (int i = 1; i <= m; i++)
        {
            int l, r;
            read(l, r);
            l = (l + ans) % n + 1, r = (r + ans) % n + 1;
            if (l > r)
            {
                std::swap(l, r);
            }
            write(ans = query(l, r));
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}