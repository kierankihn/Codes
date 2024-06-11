/**
 * @author Kieran Kihn
 * @date 2024.06.11
 * @name P3121 [USACO15FEB] Censoring G
 * @link https://www.luogu.com.cn/problem/P3121
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

    constexpr int MAXN = 1e5 + 5;
    constexpr int MAXC = 26 + 5;

    int n;

    std::string t;

    int size;
    int e[MAXN][MAXC], is_end[MAXN], fail[MAXN];

    void insert(std::string x)
    {
        int u = 0;
        for (auto c : x)
        {
            u = e[u][c - 'a'] == 0 ? (e[u][c - 'a'] = ++size) : (e[u][c - 'a']);
        }
        is_end[u] = x.size();
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

        while (q.empty() == false)
        {
            int u = q.front();
            q.pop();

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

    int pos = 0;
    int a[MAXN], b[MAXN];
    void solve(std::string s)
    {
        int u = 0;
        for (auto c : s)
        {
            pos++;
            a[pos] = c - 'a';
            b[pos] = u = e[u][c - 'a'];

            if (is_end[u])
            {
                u = b[pos = pos - is_end[u]];
            }
        }
    }

    int main()
    {
        read(t, n);
        for (int i = 1; i <= n; i++)
        {
            insert(reads());
        }

        build();

        solve(t);

        for (int i = 1; i <= pos; i++)
        {
            putchar(a[i] + 'a');
        }
        putchar('\n');

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}