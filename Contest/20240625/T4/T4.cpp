/**
 * @author Kieran Kihn
 * @date 2024.06.25
 * @name T4
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
    typedef std::pair<i64, int> pii;

    constexpr int MAXN = 1e6 + 5;

    i64 n, m, h;

    i64 a[MAXN], b[MAXN];

    i64 sum[MAXN];
    bool used[MAXN];

    std::priority_queue<pii> q1;
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> q2;

    int cnt = 0;
    int ans[MAXN];

    int main()
    {
        read(n, m, h);
        for (int i = 1; i <= n; i++)
        {
            read(a[i], b[i]);
        }

        for (int i = 1; i <= n; i++)
        {
            if (used[b[i]])
            {
                q2.push({sum[b[i]] += a[i], b[i]});
            }
            else
            {
                h -= a[i];
                q1.push({sum[b[i]] += a[i], b[i]});

                while (true)
                {
                    while (q1.empty() == false && sum[q1.top().second] != q1.top().first)
                    {
                        q1.pop();
                    }
                    while (q2.empty() == false && sum[q2.top().second] != q2.top().first)
                    {
                        q2.pop();
                    }

                    if (q1.empty() || q2.empty() || q2.top().first >= q1.top().first)
                    {
                        break;
                    }

                    auto prev = q2.top(), next = q1.top();
                    h -= prev.first, h += next.first;
                    used[prev.second] = false, used[next.second] = true;

                    q1.pop(), q1.push(prev);
                    q2.pop(), q2.push(next);
                }

                while (h <= 0)
                {
                    while (q1.empty() == false && sum[q1.top().second] != q1.top().first)
                    {
                        q1.pop();
                    }

                    ans[cnt++] = i - 1;
                    h += q1.top().first, used[q1.top().second] = true;

                    q2.push(q1.top()), q1.pop();
                }
            }
        }

        for (int i = cnt; i <= m; i++)
        {
            ans[i] = n;
        }

        writeAll(ans, ans + m + 1);

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}