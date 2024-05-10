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
    typedef double dbi;
    typedef long long i64;

    const int MAXN = 4e5 + 5;

    struct Point
    {
        i64 x, y;
    };
    Point rev(Point x)
    {
        return {-x.x, -x.y};
    }
    bool operator<(const Point a, const Point b)
    {
        return a.x == b.x ? a.y < b.y : a.x < b.x;
    }
    i64 operator*(const Point &x, const Point &y)
    {
        return x.x * y.x + x.y * y.y;
    }
    dbi slope(Point x, Point y)
    {
        return dbi(x.y - y.y) / dbi(x.x - y.x);
    }

    struct Node
    {
        int size = 0;
        std::vector<Point> point[2];
    };

    int n, m;
    std::string s;
    bool is_encode;

    i64 ans = 0;

    void decode(i64 &x)
    {
        x = x ^ (ans & 0x7fffffff);
    }

    Node node[MAXN << 2];
    i64 solve(int o, Point x)
    {
        int id = 0;
        if (x.y < 0)
        {
            id = 1, x = rev(x);
        }

        auto &p = node[o].point[id];

        int l = 0, r = p.size() - 1;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (x * p[mid] < x * p[mid + 1])
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }

        return x * p[l];
    }
    void build(int o)
    {
        for (int id = 0; id < 2; id++)
        {
            node[o].point[id].resize(node[o << 1].point[id].size() + node[o << 1 | 1].point[id].size());
            std::merge(node[o << 1].point[id].begin(), node[o << 1].point[id].end(), node[o << 1 | 1].point[id].begin(), node[o << 1 | 1].point[id].end(), node[o].point[id].begin());

            std::vector<Point> res;

            auto &p = node[o].point[id];
            for (auto it = p.begin(); it != p.end(); it++)
            {
                while (res.size() >= 2 && slope(*it, *res.rbegin()) >= slope(*res.rbegin(), *(res.rbegin() + 1)))
                {
                    res.pop_back();
                }
                res.push_back(*it);
            }

            node[o].point[id] = res;
        }
    }
    void insert(Point v, int x = ++m, int o = 1, int l = 1, int r = n)
    {
        if (l == r)
        {
            node[o].point[0] = {v}, node[o].point[1] = {rev(v)}, node[o].size = 1;
            return;
        }

        int mid = (l + r) >> 1;
        if (x <= mid)
        {
            insert(v, x, o << 1, l, mid);
        }
        else
        {
            insert(v, x, o << 1 | 1, mid + 1, r);
        }

        if (++node[o].size == r - l + 1)
        {
            build(o);
        }
    }
    i64 query(int ql, int qr, Point x, int o = 1, int l = 1, int r = n)
    {
        if (ql <= l && r <= qr)
        {
            return solve(o, x);
        }

        int mid = (l + r) >> 1;
        if (mid >= ql && mid < qr)
        {
            return std::max(query(ql, qr, x, o << 1, l, mid), query(ql, qr, x, o << 1 | 1, mid + 1, r));
        }
        if (mid >= ql)
        {
            return query(ql, qr, x, o << 1, l, mid);
        }
        if (mid < qr)
        {
            return query(ql, qr, x, o << 1 | 1, mid + 1, r);
        }

        return 0;
    }

    int main()
    {
        read(n, s);

        is_encode = s != "E";

        for (int i = 1; i <= n; i++)
        {
            auto op = reads();

            if (op == "A")
            {
                i64 x = readi(), y = readi();

                if (is_encode)
                {
                    decode(x), decode(y);
                }

                insert({x, y});
            }
            if (op == "Q")
            {
                i64 x = readi(), y = readi(), l = readi(), r = readi();

                if (is_encode)
                {
                    decode(x), decode(y), decode(l), decode(r);
                }

                write(ans = query(l, r, {x, y}));
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