#include <bits/stdc++.h>
namespace IO
{
    namespace basic_IO
    {
        template <typename T>
        void __read(T &x)
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
        template <typename First, typename... Rest>
        void __read(First &first, Rest &...rest)
        {
            __read(first);
            __read(rest...);
        }
        template <typename T>
        void __write(T x)
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
            basic_IO::__write(*i);
        }
    }
}  // namespace IO
namespace solution
{
    using namespace IO;
    typedef long long i64;

    const int MAXN = 1e3 + 5;
    const int INF  = 0x3f3f3f3f;

    int n;
    int a[MAXN];
    int min[MAXN];

    std::queue<int> a1, a2, a3;
    std::stack<int> s1, s2;

    std::vector<int> e[MAXN];

    int color[MAXN];
    std::queue<int> q;
    bool bfs(int x)
    {
        color[x] = 1, q.push(x);
        while (q.empty() == false)
        {
            auto u = q.front();
            q.pop();

            for (auto v : e[u])
            {
                if (color[v] == 0)
                {
                    color[v] = 3 - color[u], q.push(v);
                }
                else if (color[u] + color[v] != 3)
                {
                    return false;
                }
            }
        }
        return true;
    }

    int main()
    {
        read(n);
        readAll(a + 1, a + n + 1);

        min[n + 1] = INF;
        for (int i = n; i >= 1; i--)
        {
            min[i] = std::min(min[i + 1], a[i]);
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (min[j + 1] < a[i] && a[i] < a[j])
                {
                    e[i].push_back(j), e[j].push_back(i);
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (color[i] == 0)
            {
                if (bfs(i) == false)
                {
                    write(0), exit(0);
                }
            }
            if (color[i] == 1)
            {
                a1.push(a[i]);
            }
            else
            {
                a2.push(a[i]);
            }
            a3.push(a[i]);
        }

        int now = 1;
        for (int i = 1; i <= n * 2; i++)
        {
            if ((a1.empty() == false && a1.front() == a3.front()) && ((s1.empty() == false && a1.front() < s1.top()) || (s1.empty() == true)))
            {
                s1.push(a1.front()), a1.pop(), a3.pop();
                putchar('a'), putchar(' ');
                continue;
            }
            if (s1.empty() == false && s1.top() == now)
            {
                s1.pop(), now++;
                putchar('b'), putchar(' ');
                continue;
            }
            if ((a2.empty() == false && a2.front() == a3.front()) && ((s2.empty() == false && a2.front() < s2.top()) || (s2.empty() == true)))
            {
                s2.push(a2.front()), a2.pop(), a3.pop();
                putchar('c'), putchar(' ');
                continue;
            }
            if (s2.empty() == false && s2.top() == now)
            {
                s2.pop(), now++;
                putchar('d'), putchar(' ');
                continue;
            }
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