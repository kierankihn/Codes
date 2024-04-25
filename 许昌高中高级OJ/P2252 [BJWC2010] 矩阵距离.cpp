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

    const int MAXN = 1e3 + 5;
    const int dx[] = {1, -1, 0, 0};
    const int dy[] = {0, 0, 1, -1};

    struct Node
    {
        int x, y;
    };

    int n, m;
    int a[MAXN][MAXN], b[MAXN][MAXN];

    void bfs()
    {
        std::queue<Node> q;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j] == 1)
                {
                    b[i][j] = 0, q.push({i, j});
                }
            }
        }

        while (q.empty() == false)
        {
            auto u = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                Node v = {u.x + dx[i], u.y + dy[i]};
                if (1 <= v.x && v.x <= n && 1 <= v.y && v.y <= m && b[v.x][v.y] == -1)
                {
                    b[v.x][v.y] = b[u.x][u.y] + 1;
                    q.push(v);
                }
            }
        }
    }

    int main()
    {
        std::memset(b, -1, sizeof(b));

        read(n, m);
        for (int i = 1; i <= n; i++)
        {
            std::string s;
            read(s);
            for (int j = 1; j <= m; j++)
            {
                a[i][j] = s[j - 1] - '0';
            }
        }

        bfs();

        for (int i = 1; i <= n; i++)
        {
            writeAll(b[i] + 1, b[i] + m + 1);
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}