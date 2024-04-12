#include <bits/stdc++.h>
namespace IO
{
    namespace basic_IO
    {
        template <typename T>
        void __read(T &x)
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
        template <typename First, typename... Rest>
        void __read(First &first, Rest &...rest)
        {
            __read(first);
            __read(rest...);
        }
        template <typename T>
        void __write(T x)
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
            basic_IO::__write(*i);
        }
    }
}  // namespace IO
namespace solution
{
    using namespace IO;
    typedef long long i64;
    const i64 INF = 1e13;

    int n;
    i64 ans = 0, cnt = 0;

    struct App
    {
        i64 t, m, p, pos;
        i64 endpos()
        {
            return pos + m;
        }
        i64 endtime()
        {
            return t + p;
        }
    };
    std::set<i64> tm;
    std::queue<App> q;        // 等待队列
    std::vector<App> memory;  // 内存条

    auto check(App x)
    {
        if (x.m <= memory.front().pos)  // 判断能否插入最前边
        {
            return memory.begin();
        }
        else
        {
            for (auto prev = memory.begin(), next = ++memory.begin(); next != memory.end(); prev++, next++)
            {
                if (x.m <= next->pos - prev->endpos())
                {
                    return next;
                }
            }
        }

        return memory.end();
    }

    // 插入内存
    void push(App x)
    {
        auto it = check(x);

        if (it != memory.end())
        {
            x.pos = (it == memory.begin() ? 0 : (it - 1)->endpos());
            // write(x.pos, x.endpos(), x.t, x.endtime());
            memory.insert(it, x), tm.insert(x.endtime());
        }
        else
        {
            q.push(x), cnt++;
        }
    }

    // 释放内存
    void pull(i64 time)
    {
        for (size_t i = 0; i < memory.size(); i++)
        {
            if (memory[i].endtime() <= time)
            {
                memory.erase(memory.begin() + i--);
            }
        }

        while (!q.empty())
        {
            auto it = check(q.front());
            if (it != memory.end())
            {
                q.front().t = time, q.front().pos = (it == memory.begin() ? 0 : (it - 1)->endpos());
                memory.insert(it, q.front()), tm.insert(q.front().endtime());
                q.pop();
            }
            else
            {
                break;
            }
        }
    }

    int main()
    {
        read(n);
        memory.push_back({0, 1, INF, n});

        i64 t, m, p;
        while (read(t, m, p), t != 0 || m != 0 || p != 0)
        {
            while (tm.empty() == false && *tm.begin() <= t)
            {
                ans = std::max(ans, *tm.begin());
                pull(*tm.begin()), tm.erase(tm.begin());
            }

            push({t, m, p});
        }

        while (tm.empty() == false)
        {
            ans = std::max(ans, *tm.begin());
            pull(*tm.begin()), tm.erase(tm.begin());
        }

        write(ans), write(cnt);
        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}