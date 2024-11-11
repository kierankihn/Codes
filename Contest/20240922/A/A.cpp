/**
 * @author Kieran Kihn
 * @date 2024.09.22
 * @name A
 * @link
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

    struct Node
    {
        char c;
        int lson, rson;
    };

    int n, id;

    int size, root[MAXN], len[MAXN];
    Node node[MAXN * 40];
    void update(int x, char v, int &o, int l = 1, int r = n)
    {
        size++, node[size] = node[o], o = size;
        if (l == r)
        {
            node[o].c = v;
            return;
        }

        int mid = (l + r) >> 1;
        if (x <= mid)
        {
            update(x, v, node[o].lson, l, mid);
        }
        else
        {
            update(x, v, node[o].rson, mid + 1, r);
        }
    }
    char query(int x, int o, int l = 1, int r = n)
    {
        if (l == r)
        {
            return node[o].c;
        }

        int mid = (l + r) >> 1;
        if (x <= mid)
        {
            return query(x, node[o].lson, l, mid);
        }
        else
        {
            return query(x, node[o].rson, mid + 1, r);
        }
    }


    int main()
    {
        read(n);
        for (int i = 1; i <= n; i++)
        {
            char op[10], c[10];
            scanf("%s", op + 1);

            id++, len[id] = len[id - 1], root[id] = root[id - 1];

            if (op[1] == 'T')
            {
                scanf("%s", c + 1);
                update(++len[id], c[1], root[id]);
            }
            if (op[1] == 'U')
            {
                int x = readi();

                root[id] = root[id - x - 1], len[id] = len[id - x - 1];
            }
            if (op[1] == 'Q')
            {
                printf("%c\n", query(readi(), root[--id]));
            }
        }


        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}