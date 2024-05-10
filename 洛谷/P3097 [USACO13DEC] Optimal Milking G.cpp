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

    const int MAXN = 4e4 + 5;

    struct Node
    {
        int max[2][2];
        Node()
        {
        }
        Node(int max00, int max01, int max10, int max11)
        {
            max[0][0] = max00;
            max[0][1] = max01;
            max[1][0] = max10;
            max[1][1] = max11;
        }
    };
    Node operator+(const Node a, const Node b)
    {
        return {
            std::max({a.max[0][0] + b.max[0][0], a.max[0][0] + b.max[1][0], a.max[0][1] + b.max[0][0]}),
            std::max({a.max[0][0] + b.max[0][1], a.max[0][0] + b.max[1][1], a.max[0][1] + b.max[0][1]}),
            std::max({a.max[1][0] + b.max[0][0], a.max[1][0] + b.max[1][0], a.max[1][1] + b.max[0][0]}),
            std::max({a.max[1][0] + b.max[0][1], a.max[1][0] + b.max[1][1], a.max[1][1] + b.max[0][1]})};
    }

    int n, m;
    int a[MAXN];

    i64 ans = 0;

    Node node[MAXN << 2];
    void build(int o = 1, int l = 1, int r = n)
    {
        if (l == r)
        {
            node[o] = {0, 0, 0, a[l]};
            return;
        }

        int mid = (l + r) >> 1;
        build(o << 1, l, mid), build(o << 1 | 1, mid + 1, r);

        node[o] = node[o << 1] + node[o << 1 | 1];
    }
    void update(int x, int v, int o = 1, int l = 1, int r = n)
    {
        if (l == r)
        {
            node[o] = {0, 0, 0, a[l] = v};
            return;
        }

        int mid = (l + r) >> 1;
        if (x <= mid)
        {
            update(x, v, o << 1, l, mid);
        }
        else
        {
            update(x, v, o << 1 | 1, mid + 1, r);
        }

        node[o] = node[o << 1] + node[o << 1 | 1];
    }

    int main()
    {
        read(n, m);
        readAll(a + 1, a + n + 1);

        build();

        for (int i = 1; i <= m; i++)
        {
            int x = readi(), v = readi();
            update(x, v);
            ans += std::max({node[1].max[0][0], node[1].max[0][1], node[1].max[1][0], node[1].max[1][1]});
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