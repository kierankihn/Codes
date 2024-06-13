/**
 * @author Kieran Kihn
 * @date 2024.06.13
 * @name P2414 [NOI2011] 阿狸的打字机
 * @link https://www.luogu.com.cn/problem/P2414
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

    constexpr int MAXC = 26 + 5;
    constexpr int MAXN = 2e5 + 5;

    int n, q;

    std::string s;

    p3i qs[MAXN];

    int size = 0;
    int e[MAXN][MAXC], is_end[MAXN], pos[MAXN], fa[MAXN];
    void input()
    {
        int id = 0, u = 0;
        for (auto c : s)
        {
            if (std::islower(c))
            {
                int &v = e[u][c - 'a'];
                if (v == 0)
                {
                    fa[v = ++size] = u;
                }
                u = v;
            }
            else
            {
                if (c == 'B')
                {
                    u = fa[u];
                }
                if (c == 'P')
                {
                    id++, is_end[u] = id, pos[id] = u;
                }
            }
        }
    }

    int fail[MAXN];
    std::vector<int> faile[MAXN];
    void build()
    {
        std::queue<int> q;
        for (int i = 0; i < 26; i++)
        {
            if (e[0][i] != 0)
            {
                q.push(e[0][i]);
            }
        }

        while (q.empty() == false)
        {
            auto u = q.front();
            q.pop();

            for (int i = 0; i < 26; i++)
            {
                int &v = e[u][i];
                if (v != 0)
                {
                    q.push(v);
                    fail[v] = e[fail[u]][i];
                }
                else
                {
                    e[u][i] = e[fail[u]][i];
                }
            }
        }

        for (int i = 1; i <= size; i++)
        {
            faile[fail[i]].push_back(i);
        }
    }

    int cnt = 0;
    int dfn[MAXN], sz[MAXN];
    void dfs(int u)
    {
        dfn[u] = ++cnt, sz[u] = 1;
        for (auto v : faile[u])
        {
            dfs(v);
            sz[u] += sz[v];
        }
    }

    int sum[MAXN];
    int lowbit(int x)
    {
        return x & (-x);
    }
    void update(int x, int v)
    {
        while (x <= cnt)
        {
            sum[x] += v, x += lowbit(x);
        }
    }
    int query(int x)
    {
        int res = 0;
        while (x > 0)
        {
            res += sum[x], x -= lowbit(x);
        }
        return res;
    }

    int ans[MAXN];
    void solve()
    {
        int i = 1, u = 0, id = 0;

        for (auto c : s)
        {
            if (std::islower(c))
            {
                u = e[u][c - 'a'];
                update(dfn[u], 1);
            }
            else
            {
                if (c == 'B')
                {
                    update(dfn[u], -1);
                    u = fa[u];
                }
                if (c == 'P')
                {
                    id++;
                    while (qs[i].first.first == id)
                    {
                        int qu = pos[qs[i].first.second];

                        ans[qs[i].second] = query(dfn[qu] + sz[qu] - 1) - query(dfn[qu] - 1);

                        i++;
                    }
                }
            }
        }
    }

    int main()
    {
        read(s), n = s.size();

        input();
        build();
        dfs(0);

        read(q);
        for (int i = 1; i <= q; i++)
        {
            read(qs[i].first.second, qs[i].first.first), qs[i].second = i;
        }

        std::sort(qs + 1, qs + q + 1);

        solve();

        for (int i = 1; i <= q; i++)
        {
            write(ans[i]);
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}