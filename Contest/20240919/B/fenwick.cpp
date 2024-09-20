/**
 * @author Kieran Kihn
 * @date 2024.09.19
 * @name fenwick
 * @link
 */
#include <bits/stdc++.h>
namespace FIO
{
    constexpr int MB = 1 << 20;
    struct FastIO
    {
        char ib[MB + 100], *p, *q;
        char ob[MB + 100], *r, stk[128];
        int tp;

        FastIO()
        {
            p = q = ib, r = ob, tp = 0;
        }
        ~FastIO()
        {
            fwrite(ob, 1, r - ob, stdout);
        }  // 析构函数，自动flush

        char read_char()  // 读入一个字符，注意会读入空白字符，例如空格换行
        {
            if (p == q)
            {
                p = ib, q = ib + fread(ib, 1, MB, stdin);
                if (p == q)
                    return 0;
            }
            return *p++;
        }
        template <typename T>
        void read_int(T& x)  // 读入一个整型变量，int,long long之类的都能读入
        {
            char c = read_char(), l = 0;
            for (x = 0; !isdigit(c); c = read_char())
                l = c;
            for (; isdigit(c); c = read_char())
                x = x * 10 - '0' + c;
            if (l == '-')
                x = -x;
        }

        void write_char(char c)  // 输出一个字符
        {
            if (r - ob == MB)
                r = ob, fwrite(ob, 1, MB, stdout);
            *r++ = c;
        }
        template <typename T>
        void write_int(T x)  // 输出一个整型变量，int,long long之类的都能输出
        {
            if (x < 0)
                write_char('-'), x = -x;
            do
                stk[++tp] = x % 10 + '0';
            while (x /= 10);
            while (tp)
                write_char(stk[tp--]);
        }
    } IO;
}  // namespace FIO
namespace solution
{
    using namespace FIO;
    typedef long long i64;

    constexpr int MAXN    = 2e6 + 5;
    constexpr int MAXLOGN = 20 + 5;

    int n, m;

    i64 a[MAXN], b[MAXLOGN][MAXN], c[MAXN];

    i64 sum[MAXN], tag[MAXN];

    int lowbit(int x)
    {
        return x & (-x);
    }
    void upd(int xo, i64 v)
    {
        if (xo == 0)
        {
            return;
        }

        int x = xo;
        while (x > 0)
        {
            tag[x] += v, sum[x] += v * a[lowbit(x)], x -= lowbit(x);
        }

        x = xo + lowbit(xo);

        i64 s = 0;
        while (x <= n)
        {
            while (xo > 0 && x - lowbit(x) <= xo - lowbit(xo))
            {
                s += v * a[lowbit(xo)], xo -= lowbit(xo);
            }
            sum[x] += s, x += lowbit(x);
        }
    }
    i64 query(int x)
    {
        if (x == 0)
        {
            return 0;
        }

        int xo  = x;
        i64 res = 0;

        while (x > 0)
        {
            res += sum[x], x -= lowbit(x);
        }

        x = xo + lowbit(xo);
        while (x <= n) 
        {
            res += b[std::__lg(lowbit(x))][xo - x + lowbit(x)] * tag[x], x += lowbit(x);
        }

        return res;
    }

    int main()
    {
        std::freopen("fenwick.in", "r", stdin);
        std::freopen("fenwick.out", "w", stdout);

        IO.read_int(n), IO.read_int(m);

        n = 1 << int(std::ceil(std::log2(n)));
        for (int i = 1; i <= n; i++)
        {
            a[i] = a[i - 1] + lowbit(i);
        }
        c[1] = 1, b[0][1] = 1;
        for (int k = 1; k <= std::__lg(n); k++)
        {
            for (int i = (1 << (k - 1)) + 1; i <= (1 << k); i++)
            {
                for (int j = i - lowbit(i) + 1; j <= i; j++)
                {
                    c[j]++;
                }
            }
            for (int i = 1; i <= (1 << k); i++)
            {
                b[k][i] = b[k][i - 1] + c[i];
            }
        }

        for (int i = 1; i <= m; i++)
        {
            int op;
            IO.read_int(op);
            if (op == 1)
            {
                int l, r, v;
                IO.read_int(l), IO.read_int(r), IO.read_int(v);
                upd(r, v), upd(l - 1, -v);
            }
            if (op == 2)
            {
                int l, r;
                IO.read_int(l), IO.read_int(r);
                IO.write_int(query(r) - query(l - 1)), IO.write_char('\n');
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