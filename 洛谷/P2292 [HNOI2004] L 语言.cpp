/**
 * @author Kieran Kihn
 * @date 2024.06.11
 * @name P2292 [HNOI2004] L 语言
 * @link https://www.luogu.com.cn/problem/P2292
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

    constexpr int MAXN = 2e6 + 5;
    constexpr int MAXC = 26 + 5;

    int n, m;

    int size = 0;
    int e[MAXN][MAXC], is_end[MAXN], dep[MAXN], fail[MAXN], match[MAXN];

    void insert(std::string &x)
    {
        int u = 0;
        for (auto c : x)
        {
            auto &v = e[u][c - 'a'];

            if (v == 0)
            {
                v = ++size, dep[v] = dep[u] + 1;
            }

            u = v;
        }
        is_end[u] = true;
    }
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

            match[u] = match[fail[u]] | (is_end[u] << dep[u]);

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
    }

    int solve(std::string &x)
    {
        int u = 0, dp = 1, ans = 0, i = 0;
        for (auto c : x)
        {
            i++, u = e[u][c - 'a'], dp <<= 1;

            if (dp & match[u])
            {
                dp |= 1, ans = i;
            }
        }

        return ans;
    }

    int main()
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr), std::cout.tie(nullptr);

        std::cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            std::string s;
            std::cin >> s;
            insert(s);
        }

        build();

        for (int i = 1; i <= m; i++)
        {
            std::string s;
            std::cin >> s;
            write(solve(s));
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}