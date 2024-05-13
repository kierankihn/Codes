#pragma GCC optimize(3, "Ofast", "inline")
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
    typedef std::pair<int, int> pii;

    const int MAXN    = 5e5 + 5;
    const int MAXLOGA = 31 + 5;

    int n;
    std::map<int, pii> range;

    struct Basis
    {
        int v[MAXLOGA];
        void insert(int x)
        {
            for (int i = 31; i >= 1; i--)
            {
                if (x >> (i - 1) & 1)
                {
                    if (v[i] != 0)
                    {
                        x = x ^ v[i];
                    }
                    else
                    {
                        for (int j = i - 1; j >= 1; j--)
                        {
                            if (x >> (j - 1) & 1)
                            {
                                x = x ^ v[j];
                            }
                        }
                        for (int j = 31; j > i; j--)
                        {
                            if (v[j] >> (i - 1) & 1)
                            {
                                v[j] = v[j] ^ x;
                            }
                        }
                        v[i] = x;
                        break;
                    }
                }
            }
        }
        int max()
        {
            int res = 0;
            for (int i = 31; i >= 1; i--)
            {
                if ((res >> (i - 1) & 1) == 0)
                {
                    res = res ^ v[i];
                }
            }
            return res;
        }
    };
    Basis root;

    struct Node
    {
        std::vector<int> p;
    };
    Node node[MAXN << 2];

    void update(int ql, int qr, int v, int o = 1, int l = 1, int r = n)
    {
        if (ql <= l && r <= qr)
        {
            node[o].p.push_back(v);
            return;
        }

        int mid = (l + r) >> 1;
        if (mid >= ql)
        {
            update(ql, qr, v, o << 1, l, mid);
        }
        if (mid < qr)
        {
            update(ql, qr, v, o << 1 | 1, mid + 1, r);
        }
    }
    void dfs(int o = 1, int l = 1, int r = n, Basis b = root)
    {
        for (auto i : node[o].p)
        {
            b.insert(i);
        }

        if (l == r)
        {
            write(b.max());
            return;
        }

        int mid = (l + r) >> 1;
        dfs(o << 1, l, mid, b), dfs(o << 1 | 1, mid + 1, r, b);
    }

    int main()
    {
        read(n);

        for (int i = 1; i <= n; i++)
        {
            int x = readi();
            if (x > 0)
            {
                range[x] = {i, n};
            }
            else
            {
                range[-x].second = i - 1;
            }
        }

        for (auto i : range)
        {
            update(i.second.first, i.second.second, i.first);
        }

        dfs();

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}