/**
 * @author Kieran Kihn
 * @date 2024.07.03
 * @name T7
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

    constexpr int MAXN = 3e5 + 5;

    struct Node
    {
        int gcd;
    };
    Node operator+(const Node &a, const Node &b)
    {
        return {std::__gcd(a.gcd, b.gcd)};
    }

    int n;
    int a[MAXN];

    int max = 0;
    int ans[MAXN];

    Node node[MAXN << 2];
    void build(int o = 1, int l = 1, int r = n)
    {
        if (l == r)
        {
            node[o].gcd = a[l];
            return;
        }

        int mid = (l + r) >> 1;
        build(o << 1, l, mid), build(o << 1 | 1, mid + 1, r);

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

        return {1};
    }

    int maxl[MAXN], maxr[MAXN];
    int findl(int x)
    {
        int l = maxl[x], r = x;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (query(mid, x).gcd != a[x])
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return l;
    }
    int findr(int x)
    {
        int l = x, r = maxr[x];
        while (l < r)
        {
            int mid = std::ceil((l + r) / 2.0);
            if (query(x, mid).gcd != a[x])
            {
                r = mid - 1;
            }
            else
            {
                l = mid;
            }
        }
        return l;
    }


    int son[MAXN][2];

    void build_t()
    {
        a[0] = -1;
        std::stack<int> s({0});

        for (int i = 1; i <= n; i++)
        {
            while (a[s.top()] >= a[i])
            {
                son[i][0] = s.top(), s.pop();
            }
            son[s.top()][1] = i;
            s.push(i);
        }
    }

    std::pair<int, int> dfs(int u)
    {
        if (son[u][0] == 0)
        {
            maxl[u] = u;
        }
        else
        {
            maxl[u] = dfs(son[u][0]).first;
        }
        if (son[u][1] == 0)
        {
            maxr[u] = u;
        }
        else
        {
            maxr[u] = dfs(son[u][1]).second;
        }

        return {maxl[u], maxr[u]};
    }

    int main()
    {
        read(n);
        readAll(a + 1, a + n + 1);

        build();

        build_t();
        dfs(son[0][1]);

        for (int i = 1; i <= n; i++)
        {
            int l = findl(i), r = findr(i);
            if (r - l > max)
            {
                max = r - l, ans[ans[0] = 1] = l;
            }
            else if (r - l == max)
            {
                ans[++ans[0]] = l;
            }
        }

        std::sort(ans + 1, ans + ans[0] + 1);
        ans[0] = std::unique(ans + 1, ans + ans[0] + 1) - ans - 1;

        write(ans[0], max);
        writeAll(ans + 1, ans + ans[0] + 1);


        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}