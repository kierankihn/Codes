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
    long long reads()
    {
        long long res;
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

    const int MAXN = 1e5 + 5;

    struct Node
    {
        bool road[3][3], right[3], down;
        Node()
        {
        }
        Node(int r11, int r12, int r21, int r22, int right1, int right2, int _down)
        {
            road[1][1] = r11;
            road[1][2] = r12;
            road[2][1] = r21;
            road[2][2] = r22;
            right[1] = right1, right[2] = right2;
            down = _down;
        }
    };
    Node operator+(const Node a, const Node b)
    {
        return {
            (a.road[1][1] && a.right[1] && b.road[1][1]) || (a.road[1][2] && a.right[2] && b.road[2][1]),
            (a.road[1][1] && a.right[1] && b.road[1][2]) || (a.road[1][2] && a.right[2] && b.road[2][2]),
            (a.road[2][1] && a.right[1] && b.road[1][1]) || (a.road[2][2] && a.right[2] && b.road[2][1]),
            (a.road[2][1] && a.right[1] && b.road[1][2]) || (a.road[2][2] && a.right[2] && b.road[2][2]),
            b.right[1],
            b.right[2],
            a.down || b.down};
    }

    int n;

    Node node[MAXN << 2];
    void build(int o = 1, int l = 1, int r = n)
    {
        if (l == r)
        {
            node[o] = {1, 0, 0, 1, 0, 0, 0};
            return;
        }

        int mid = (l + r) >> 1;
        build(o << 1, l, mid), build(o << 1 | 1, mid + 1, r);

        node[o] = node[o << 1] + node[o << 1 | 1];
    }
    void updatev(int x, int v, int o = 1, int l = 1, int r = n)
    {
        if (l == r)
        {
            node[o].road[1][2] = node[o].road[2][1] = node[o].down = v;
            return;
        }

        int mid = (l + r) >> 1;
        if (x <= mid)
        {
            updatev(x, v, o << 1, l, mid);
        }
        if (x > mid)
        {
            updatev(x, v, o << 1 | 1, mid + 1, r);
        }

        node[o] = node[o << 1] + node[o << 1 | 1];
    }
    void updateh(int x, int y, int v, int o = 1, int l = 1, int r = n)
    {
        if (l == r)
        {
            node[o].right[y] = v;
            return;
        }

        int mid = (l + r) >> 1;
        if (x <= mid)
        {
            updateh(x, y, v, o << 1, l, mid);
        }
        if (x > mid)
        {
            updateh(x, y, v, o << 1 | 1, mid + 1, r);
        }

        node[o] = node[o << 1] + node[o << 1 | 1];
    }
    Node query(int ql, int qr, int o = 1, int l = 1, int r = n)
    {
        if (ql <= l && r <= qr)
        {
            return node[o];
        }

        int mid = (l + r) >> 1;
        if (mid >= ql && mid < qr)
        {
            return query(ql, qr, o << 1, l, mid) + query(ql, qr, o << 1 | 1, mid + 1, r);
        }
        if (mid >= ql)
        {
            return query(ql, qr, o << 1, l, mid);
        }
        if (mid < qr)
        {
            return query(ql, qr, o << 1 | 1, mid + 1, r);
        }

        return {0, 0, 0, 0, 0, 0, 0};
    }
    int findleft(int x, int o = 1, int l = 1, int r = n)
    {
        if (node[o].down == false)
        {
            return -1;
        }
        if (l == r)
        {
            return l;
        }

        int mid = (l + r) >> 1;
        if (x <= mid)
        {
            return findleft(x, o << 1, l, mid);
        }

        auto right = node[o << 1 | 1].down ? findleft(x, o << 1 | 1, mid + 1, r) : -1;
        if (right != -1)
        {
            return right;
        }
        else
        {
            return findleft(x, o << 1, l, mid);
        }
    }
    int findright(int x, int o = 1, int l = 1, int r = n)
    {
        if (node[o].down == false)
        {
            return -1;
        }
        if (l == r)
        {
            return l;
        }

        int mid = (l + r) >> 1;
        if (x > mid)
        {
            return findright(x, o << 1 | 1, mid + 1, r);
        }

        auto left = node[o << 1].down ? findright(x, o << 1, l, mid) : -1;
        if (left != -1)
        {
            return left;
        }
        else
        {
            return findright(x, o << 1 | 1, mid + 1, r);
        }
    }

    int main()
    {
        read(n);

        build();

        while (true)
        {
            std::string op;
            std::pair<int, int> a, b;

            read(op);
            if (op == "Exit")
            {
                break;
            }

            read(a.second, a.first, b.second, b.first);
            if (a > b)
            {
                std::swap(a, b);
            }

            if (op == "Open")
            {
                if (a.first == b.first)
                {
                    updatev(a.first, 1);
                }
                if (a.second == b.second)
                {
                    updateh(a.first, a.second, 1);
                }
            }
            if (op == "Close")
            {
                if (a.first == b.first)
                {
                    updatev(a.first, 0);
                }
                if (a.second == b.second)
                {
                    updateh(a.first, a.second, 0);
                }
            }

            if (op == "Ask")
            {
                auto res = query(a.first, b.first);

                if (res.road[a.second][b.second])
                {
                    write("Y");
                    continue;
                }
                else
                {
                    int l = findleft(a.first), r = findright(b.first);
                    bool left = false, right = false;

                    if (l != -1)
                    {
                        auto left_res = query(l, a.first);
                        if (left_res.road[1][1] && left_res.road[2][2])
                        {
                            left = true;
                        }
                    }
                    if (r != -1)
                    {
                        auto right_res = query(b.first, r);
                        if (right_res.road[1][1] && right_res.road[2][2])
                        {
                            right = true;
                        }
                    }

                    if (left && res.road[3 - a.second][b.second])
                    {
                        write("Y");
                        continue;
                    }
                    if (right && res.road[a.second][3 - b.second])
                    {
                        write("Y");
                        continue;
                    }
                    if (left && right && res.road[3 - a.second][3 - b.second])
                    {
                        write("Y");
                        continue;
                    }
                }
                write("N");
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