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
    const int MAXN = 5e6 + 5;
    const LL MOD = 1e8 + 7;
    using input::read;
    using output::write;
    int n;
    LL ans = 1;
    LL prime[MAXN];
    LL cnt[MAXN];
    bool notprime[MAXN];
    void getPrime()
    {
        for (int i = 2; i <= n; i++)
        {
            if (!notprime[i])
            {
                prime[++prime[0]] = i;
            }
            for (int j = 1; j <= prime[0] && i * prime[j] <= n; j++)
            {
                notprime[i * prime[j]] = true;
                if (i % prime[j] == 0)
                {
                    break;
                }
            }
        }
    }
    LL qpow(LL a, LL b, LL c)
    {
        LL res = 1;
        while (b)
        {
            if (b & 1)
            {
                res = res * a;
                res = res % c;
            }
            b >>= 1;
            a = a * a % c;
        }
        return res;
    }
    int main()
    {
        read(n);
        getPrime();
        for (int i = n; i >= 2; i--)
        {
            cnt[i]++;
            if (!notprime[i])
            {
                continue;
            }
            for (int j = 1; j <= prime[0] && prime[j] < i; j++)
            {
                if (i % prime[j] == 0)
                {
                    cnt[i / prime[j]] += cnt[i];
                    cnt[prime[j]] += cnt[i];
                    break;
                }
            }
        }
        for (int i = 2; i <= n; i++)
        {
            if (notprime[i])
            {
                continue;
            }
            if (cnt[i] % 2 == 1)
            {
                cnt[i]--;
            }
            ans = ans * qpow(i, cnt[i], MOD) % MOD;
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