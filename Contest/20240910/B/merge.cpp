/**
 * @author Kieran Kihn
 * @date 2024.09.10
 * @name merge
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

    constexpr int MAXC = 26 + 5;
    constexpr int MAXN = 5e5 + 5;

    struct Node
    {
        i64 min, max;
        int lson, rson;
    };
    Node operator+(const Node &a, const Node &b)
    {
        return {std::min(a.min, b.min), std::max(a.max, b.max), 0, 0};
    }

    int n, q;
    i64 a[MAXN];

    char s[MAXN];

    std::vector<int> p[MAXC];

    i64 sum[MAXC][MAXN];

    int size, root[MAXC];
    Node node[MAXN << 2];
    void pushup(int o)
    {
        node[o].min = std::min(node[node[o].lson].min, node[node[o].rson].min);
        node[o].max = std::max(node[node[o].lson].max, node[node[o].rson].max);
    }
    void build(i64 *v, int &o, int l, int r)
    {
        if (o == 0)
        {
            o = ++size;
        }
        if (l == r)
        {
            node[o] = {v[l], v[l], 0, 0};
            return;
        }

        int mid = (l + r) >> 1;
        build(v, node[o].lson, l, mid), build(v, node[o].rson, mid + 1, r);

        pushup(o);
    }
    Node query(int ql, int qr, int o, int l, int r)
    {
        if (o == 0 || (ql <= l && r <= qr))
        {
            return node[o];
        }

        int mid = (l + r) >> 1;

        if (qr <= mid)
        {
            return query(ql, qr, node[o].lson, l, mid);
        }
        if (ql > mid)
        {
            return query(ql, qr, node[o].rson, mid + 1, r);
        }

        return query(ql, qr, node[o].lson, l, mid) + query(ql, qr, node[o].rson, mid + 1, r);
    }

    int main()
    {
        // freopen("merge.in", "r", stdin);
        // freopen("merge.out", "w", stdout);

        scanf("%s", s + 1), n = std::strlen(s + 1);
        for (int i = 1; i <= n; i++)
        {
            a[i] = 1 << (s[i] - 'a');

            p[s[i] - 'a' + 1].push_back(i);

            sum[0][i] = sum[0][i - 1] + a[i], sum[s[i] - 'a' + 1][++sum[s[i] - 'a' + 1][0]] = sum[0][i] % a[i];
        }

        for (int i = 1; i <= 26; i++)
        {
            if (sum[i][0] != 0)
            {
                build(sum[i], root[i], 1, sum[i][0]);
            }
        }

        read(q);
        for (int i = 1; i <= q; i++)
        {
            bool ans = true;

            int l = readi(), r = readi();
            for (int j = 1; j <= 26; j++)
            {
                int lid = std::lower_bound(p[j].begin(), p[j].end(), l) - p[j].begin() + 1, rid = std::upper_bound(p[j].begin(), p[j].end(), r) - p[j].begin();

                if (p[j].empty() == false && lid <= rid)
                {
                    auto res = query(lid, rid, root[j], 1, sum[j][0]);

                    ans &= res.min == res.max;

                    if (res.min != res.max)
                    {
                        write(j);
                    }
                }
            }

            ans &= sum[0][l - 1] % (1 << 26) == sum[0][r] % (1 << 26);

            if (ans)
            {
                write("Yes");
            }
            else
            {
                write("No");
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