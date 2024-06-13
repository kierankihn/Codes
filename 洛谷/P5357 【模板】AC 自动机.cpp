/**
 * @author Kieran Kihn
 * @date 2024.06.11
 * @name P5357 【模板】AC 自动机
 * @link https://www.luogu.com.cn/problem/P5357
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

    constexpr int MAXN = 2e5 + 5;
    constexpr int MAXC = 26 + 5;

    int n;
    std::string t;
    std::string s[MAXN];

    int size;
    int e[MAXN][MAXC], is_end[MAXN], fail[MAXN], cnt[MAXN];

    std::vector<int> faile[MAXN];

    void insert(std::string &x)
    {
        int u = 0;
        for (auto c : x)
        {
            int &v = e[u][c - 'a'];
            if (v == 0)
            {
                v = ++size;
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
                faile[0].push_back(e[0][i]);
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
                    q.push(v), faile[e[fail[u]][i]].push_back(v);
                    fail[v] = e[fail[u]][i];
                }
                else
                {
                    e[u][i] = e[fail[u]][i];
                }
            }
        }
    }

    void query(std::string &x)
    {
        int u = 0;
        for (auto c : x)
        {
            cnt[u = e[u][c - 'a']]++;
        }
    }

    int dfs(int u)
    {
        for (auto v : faile[u])
        {
            cnt[u] += dfs(v);
        }
        return cnt[u];
    }

    int find(std::string &x)
    {
        int u = 0;
        for (auto c : x)
        {
            u = e[u][c - 'a'];
        }
        return cnt[u];
    }

    int main()
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr), std::cout.tie(nullptr);

        std::cin >> n;
        for (int i = 1; i <= n; i++)
        {
            std::cin >> s[i];
            insert(s[i]);
        }

        build();

        std::cin >> t;
        query(t);

        dfs(0);

        for (int i = 1; i <= n; i++)
        {
            std::cout << find(s[i]) << std::endl;
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}