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

        constexpr int MAXN = 5e5 + 5;
        constexpr int MOD  = 998244353;

        i64 qpow(i64 a, i64 b, i64 c)
        {
            i64 res = 1;
            while (b)
            {
                if (b & 1)
                {
                    res = res * a % c;
                }
                a = a * a % c, b = b >> 1;
            }
            return res;
        }

        i64 C(i64 x, i64 y)  // x! / (y! * (x - y)!)
        {
            y = std::max(y, x - y);

            i64 res = 1;
            for (i64 i = y + 1; i <= x; i++)
            {
                res = res * i % MOD;
            }
            for (i64 i = 1; i <= x - y; i++)
            {
                res = res * qpow(i, MOD - 2, MOD) % MOD;
            }

            return res;
        }

        int t;
        int n, c;
        i64 v[MAXN];
        int lson[MAXN], rson[MAXN];

        int size;
        i64 a[MAXN];
        void dfs(int u)
        {
            if (lson[u] != -1)
            {
                dfs(lson[u]);
            }
            a[++size] = v[u];
            if (rson[u] != -1)
            {
                dfs(rson[u]);
            }
        }

        i64 ans = 1;

        int main()
        {
            read(t);
            while (t--)
            {
                read(n, c);
                for (int i = 1; i <= n; i++)
                {
                    read(lson[i], rson[i], v[i]);
                }

                size = 0, dfs(1);

                a[0] = 1, a[n + 1] = c, ans = 1;

                int prev = 0;
                for (int i = 1; i <= n + 1; i++)
                {
                    if (a[i] != -1)
                    {
                        int l = prev, r = i;
                        ans = (ans * C(a[r] - a[l] + r - l - 1, r - l - 1)) % MOD, prev = i;
                    }
                }

                write(ans);
            }

            return 0;
        }
    }  // namespace solution
    int main()
    {
        solution::main();
        return 0;
    }

    /**
     * 在区间 (l, r) 中，填入数字 [a[l], a[r]], 满足单调不减
     * 设区间长度为 len = r - l - 1，数字值域大小为 size = a[r] - a[l] + 1
     * 答案为与 (l, r) 中填入 [a[l], a[r] + len - 1] 满足严格递增答案相同
     * C(a[r] - a[l] + r - l - 1, r - l - 1) <=> C(a[r] - a[l] - r - l - 1, a[r] - a[l])
     */