/**
 * @author Kieran Kihn
 * @date 2024.06.13
 * @name P3966 [TJOI2013] 单词
 * @link https://www.luogu.com.cn/problem/P3966
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
    constexpr int MAXN = 1e6 + 5;

    int n;

    int pos[MAXN];

    int size = 0;
    int e[MAXN][MAXC], val[MAXN], fail[MAXN];

    std::vector<int> faile[MAXN];

    int insert(std::string x)
    {
        int u = 0;

        for (auto c : x)
        {
            int &v = e[u][c - 'a'];
            if (v == 0)
            {
                v = ++size;
            }
            val[u = v]++;
        }

        return u;
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

    i64 sum[MAXN];
    i64 dfs(int u)
    {
        for (auto v : faile[u])
        {
            sum[u] += dfs(v);
        }
        return sum[u] += val[u];
    }

    int main()
    {
        read(n);
        for (int i = 1; i <= n; i++)
        {
            pos[i] = insert(reads());
        }

        build();

        dfs(0);

        for (int i = 1; i <= n; i++)
        {
            write(sum[pos[i]]);
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}