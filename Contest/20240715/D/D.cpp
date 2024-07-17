/**
 * @author Kieran Kihn
 * @date 2024.07.15
 * @name D
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
    typedef std::pair<int, int> pii;
    typedef std::pair<pii, int> p3i;
    typedef std::pair<pii, pii> p4i;

    constexpr int MAXN = 2e5 + 5;

    struct CMPL
    {
        bool operator()(const p3i &a, const p3i &b)
        {
            return a.first.first < b.first.first;
        }
    };
    struct CMPR
    {
        bool operator()(const p3i &a, const p3i &b)
        {
            return a.first.second > b.first.second;
        }
    };

    int n, m;

    i64 ans = 0;

    pii pos = {0, 0};

    p3i ad[MAXN];
    p4i ch[MAXN];

    std::multiset<p3i, CMPL> sl;
    std::multiset<p3i, CMPR> sr;

    int main()
    {
        read(n, m);
        for (int i = 1; i <= n; i++)
        {
            read(ad[i].first.first, ad[i].first.second), ad[i].second = i;

            sl.insert(ad[i]);
        }
        for (int i = 1; i <= m; i++)
        {
            read(ch[i].first.first, ch[i].first.second, ch[i].second.first), ch[i].second.second = i;
        }

        std::sort(ad + 1, ad + n + 1);
        std::sort(ch + 1, ch + m + 1);

        for (int i = 1, j = 1; i <= m; i++)
        {
            while (j <= n && ad[j].first.first <= ch[i].first.first)
            {
                sl.erase(ad[j]), sr.insert(ad[j]), j++;
            }

            int l = ch[i].first.first, r = ch[i].first.second, c = ch[i].second.first;

            if (sl.empty() == false)
            {
                int minl = std::max(l, sl.begin()->first.first);
                if (1LL * c * (r - minl) > ans)
                {
                    ans = 1LL * c * (r - minl), pos = {sl.begin()->second, ch[i].second.second};
                }
            }
            if (sr.empty() == false)
            {
                int maxr = std::min(r, sr.begin()->first.second);
                if (1LL * c * (maxr - l) > ans)
                {
                    ans = 1LL * c * (maxr - l), pos = {sr.begin()->second, ch[i].second.second};
                }
            }
        }

        write(ans);

        if (ans)
        {
            write(pos.first, pos.second);
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}