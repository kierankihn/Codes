/**
 * @author Kieran Kihn
 * @date 2024.06.14
 * @name P4052 [JSOI2007] 文本生成器
 * @link https://www.luogu.com.cn/problem/P4052
 */
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
    }  // namespace basic_IO
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
}  // namespace IO
namespace solution
{
    using namespace IO;
    typedef long long i64;

    constexpr int MAXC = 26 + 5;
    constexpr int MAXN = 6e3 + 5;
    constexpr int MAXM = 1e2 + 5;
    constexpr int MOD  = 1e4 + 7;

    i64 qpow(i64 a, i64 b, i64 c)
    {
        i64 res = 1;
        while (b)
        {
            if (b & 1)
            {
                res = res * a % c;
            }
            a = a * a % c, b >>= 1;
        }
        return res;
    }

    int n, m;

    int size = 0;
    int e[MAXN][MAXC], is_end[MAXN], dep[MAXN];
    void insert(std::string x)
    {
        int u = 0;
        for (auto c : x)
        {
            int &v = e[u][c - 'A'];
            if (v == 0)
            {
                dep[v = ++size] = dep[u] + 1;
            }
            u = v;
        }
        is_end[u] = true;
    }

    int fail[MAXN];
    std::vector<int> faile[MAXN];
    void build()
    {
        std::queue<int> q;
        for (int i = 0; i < 26; i++)
        {
            if (e[0][i] != 0)
            {
                q.push(e[0][i]);
            }
        }

        for (int u = 0; q.empty() == false; q.pop())
        {
            u = q.front();

            for (int i = 0; i < 26; i++)
            {
                int &v = e[u][i];
                if (v != 0)
                {
                    q.push(v);
                    fail[v] = e[fail[u]][i];
                }
                else
                {
                    e[u][i] = e[fail[u]][i];
                }
            }
        }

        for (int i = 1; i <= size; i++)
        {
            faile[fail[i]].push_back(i);
        }
    }

    int p[MAXN];
    void dfs(int u, int flag)
    {
        flag |= is_end[u], p[u] = flag;
        for (auto v : faile[u])
        {
            dfs(v, flag);
        }
    }

    i64 ans = 0;

    i64 dp[MAXM][MAXN];

    int main()
    {
        read(n, m);
        for (int i = 1; i <= n; i++)
        {
            insert(reads());
        }

        build();

        dfs(0, 0);

        dp[0][0] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int u = 0; u <= size; u++)
            {
                for (int j = 0; j < 26; j++)
                {
                    int &v = e[u][j];

                    if (p[v] == 0)
                    {
                        dp[i + 1][v] = (dp[i + 1][v] + dp[i][u]) % MOD;
                    }
                }
            }
        }

        for (int i = 0; i <= size; i++)
        {
            ans = (ans + dp[m][i]) % MOD;
        }

        ans = (qpow(26, m, MOD) - ans + MOD) % MOD;

        write(ans);

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}