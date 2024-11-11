#ifndef LOCAL
#pragma GCC optimize("Ofast")
#endif
#include <bits/stdc++.h>
namespace IO
{
    namespace basic_IO
    {
        template <typename T>
        typename std::enable_if<std::is_integral<T>::value>::type __read(T &x)
        {
            char ch;
            T res = 0, f = 1;
            while (std::isdigit(ch = getchar()) == false)
            {
                f = (ch != '-');
            }
            do
            {
                res = res * 10 + (ch - '0');
            } while (std::isdigit(ch = getchar()) == true);
            x = res * (f ? 1 : -1);
        }
        template <typename T>
        typename std::enable_if<!std::is_integral<T>::value>::type __read(T &x)
        {
            std::cin >> x;
        }
        template <typename First, typename... Rest>
        void __read(First &first, Rest &...rest)
        {
            __read(first);
            __read(rest...);
        }
        template <typename T>
        typename std::enable_if<std::is_integral<T>::value>::type __write(T x)
        {
            if (x < 0)
            {
                std::putchar('-'), __write(-x);
                return;
            }
            if (x >= 10)
            {
                __write(x / 10);
            }
            std::putchar(x % 10 + '0');
        }
        template <typename T>
        typename std::enable_if<!std::is_integral<T>::value>::type __write(T x)
        {
            std::cout << x;
        }
        template <typename First, typename... Rest>
        void __write(First first, Rest... rest)
        {
            __write(first), std::putchar(' '), __write(rest...);
        }
    } // namespace basic_IO
    template <typename First, typename... Rest>
    void read(First &first, Rest &...rest)
    {
        basic_IO::__read(first, rest...);
    }
    template <typename T>
    void readAll(T *begin, T *end)
    {
        for (T *i = begin; i != end; i++)
        {
            basic_IO::__read(*i);
        }
    }
    long long readi()
    {
        long long res;
        read(res);
        return res;
    }
    std::string reads()
    {
        std::string res;
        read(res);
        return res;
    }
    template <typename First, typename... Rest>
    void write(First first, Rest... rest)
    {
        basic_IO::__write(first, rest...), std::putchar('\n');
    }
    template <typename T>
    void writeAll(T *begin, T *end)
    {
        for (T *i = begin; i != end; i++)
        {
            basic_IO::__write(*i), std::putchar(' ');
        }
        std::putchar('\n');
    }
} // namespace IO
namespace solution
{
    using namespace IO;
    typedef long long i64;
    typedef std::bitset<175> bit;

    constexpr int MAXN = 2e5 + 5;
    constexpr int MAXV = 2e2 + 5;
    constexpr int MAXA = 1e6 + 5;
    constexpr int MOD  = 998244353;

    int t;

    int n;
    int a[MAXN];

    bit b[MAXA];

    i64 ans = 1;

    std::vector<int> g[MAXN];
    int prime[MAXA], notprime[MAXA], id[MAXA];
    void init()
    {
        n = 1e6;
        for (int i = 2; i <= n; i++)
        {
            if (notprime[i] == false)
            {
                prime[++prime[0]] = i, id[i] = prime[0], notprime[i] = i;

                if (i <= 1000)
                {
                    b[i][id[i]] = 1;
                }
            }
            for (int j = 1; j <= prime[0] && i * prime[j] <= n; j++)
            {
                notprime[i * prime[j]] = std::max(notprime[i], prime[j]), b[i * prime[j]] = b[i];
                if (prime[j] <= 1000)
                {
                    b[i * prime[j]][j] = 1;
                }
                if (i % prime[j] == 0)
                {
                    break;
                }
            }
        }
    }

    bit p[MAXV];
    void clear()
    {
        for (auto &i : p)
        {
            i = 0;
        }
    }
    bool insert(bit x)
    {
        for (int i = 170; i >= 1; i--)
        {
            if (x[i] == 1)
            {
                if (p[i] == 0)
                {
                    p[i] = x;
                    return true;
                }
                else
                {
                    x ^= p[i];
                }
            }
        }
        return false;
    }

    int main()
    {
#ifdef LOCAL
        std::freopen("B.in", "r", stdin);
        std::freopen("B.out", "w", stdout);
#endif

        init();

        read(t);
        while (t--)
        {
            ans = 1;

            read(n);
            readAll(a + 1, a + n + 1);

            for (int i = 1; i <= n; i++)
            {
                g[notprime[a[i]] > 1000 ? id[notprime[a[i]]] : 0].push_back(i);
            }

            clear();
            for (auto j : g[0])
            {
                ans *= insert(b[a[j]]) ? 1 : 2, ans = ans >= MOD ? ans - MOD : ans;
            }
            g[0].clear();

            for (int i = 1; i <= prime[0]; i++)
            {
                if (g[i].size())
                {
                    for (int j = 1; j < g[i].size(); j++)
                    {
                        ans *= insert(b[a[g[i][j]]] ^ b[a[g[i][0]]]) ? 1 : 2, ans = ans >= MOD ? ans - MOD : ans;
                    }
                    g[i].clear();
                }
            }

            write((ans - 1 + MOD) % MOD);
        }

        return 0;
    }
} // namespace solution
int main()
{
    solution::main();
    return 0;
}