/**
 * @author Kieran Kihn
 * @date 2024.06.12
 * @name P2322 [HNOI2006] 最短母串问题
 * @link https://www.luogu.com.cn/problem/P2322
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
    typedef std::pair<int, int> pii;

    constexpr int MAXN  = 12 + 5;
    constexpr int MAX2N = (1 << 12) + 5;

    int n;
    std::string s[MAXN];

    bool is_substr[MAXN];

    int max[MAXN][MAXN];

    int dp[MAX2N][MAXN];
    std::string t[MAX2N][MAXN];

    int get(std::string a, std::string b)
    {
        for (int i = std::min(a.size(), b.size()); i >= 1; i--)
        {
            bool check = true;
            for (int j = i - 1, k = a.size() - 1, cnt = 1; cnt <= i; j--, k--, cnt++)
            {
                if (b[j] != a[k])
                {
                    check = false;
                    break;
                }
            }
            if (check)
            {
                return b.size() - i;
            }
        }

        return b.size();
    }

    int main()
    {
        std::memset(dp, 0x3f, sizeof(dp));

        read(n);
        readAll(s + 1, s + n + 1);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j || is_substr[j] == true)
                {
                    continue;
                }
                is_substr[i] |= s[j].find(s[i]) != std::string::npos;
            }
        }

        int size = 0;
        for (int i = 1; i <= n; i++)
        {
            if (is_substr[i] == false)
            {
                s[++size] = s[i];
            }
        }
        n = size;

        std::sort(s + 1, s + n + 1);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                max[i][j] = get(s[i], s[j]);
            }
        }

        for (int i = 1; i <= n; i++)
        {
            dp[1 << (i - 1)][i] = s[i].size();
            t[1 << (i - 1)][i]  = s[i];
        }

        for (int i = 0; i < (1 << n); i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if ((i & (1 << (j - 1))) == 0)
                {
                    continue;
                }
                for (int k = 1; k <= n; k++)
                {
                    if (i & (1 << (k - 1)))
                    {
                        continue;
                    }
                    if (dp[i][j] + max[j][k] < dp[i | (1 << (k - 1))][k])
                    {
                        dp[i | (1 << (k - 1))][k] = dp[i][j] + max[j][k];
                        t[i | (1 << (k - 1))][k]  = t[i][j] + s[k].substr(s[k].size() - max[j][k]);
                    }
                    else if (dp[i][j] + max[j][k] == dp[i | (1 << (k - 1))][k])
                    {
                        t[i | (1 << (k - 1))][k] = std::min(t[i | (1 << (k - 1))][k], t[i][j] + s[k].substr(s[k].size() - max[j][k]));
                    }
                }
            }
        }

        int minpos = 0;
        std::string ans;
        for (int i = 1; i <= n; i++)
        {
            if (dp[(1 << n) - 1][i] < dp[(1 << n) - 1][minpos])
            {
                minpos = i, ans = t[(1 << n) - 1][i];
            }
            else if (dp[(1 << n) - 1][i] == dp[(1 << n) - 1][minpos])
            {
                ans = std::min(ans, t[(1 << n) - 1][i]);
            }
        }

        write(ans);

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}