#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = (1LL << 10LL) + 5;
    int n;
    bool ans[MAXN][MAXN];
    LL qpow(LL a, LL b)
    {
        LL res = 1;
        while (b)
        {
            if (b & 1)
            {
                res = res * a;
            }
            a = a * a;
            b = b >> 1;
        }
        return res;
    }
    void solve(int id, int x = 1, int y = 1)
    {
        if (id == 1)
        {
            ans[x][y] = true;
            return;
        }
        LL len = qpow(3, id - 2);
        solve(id - 1, x, y), solve(id - 1, x + 2 * len, y), solve(id - 1, x + len, y + len), solve(id - 1, x, y + len * 2), solve(id - 1, x + len * 2, y + len * 2);
    }
    void output(int x)
    {
        LL len = qpow(3, x - 1);
        for (int i = 1; i <= len; i++)
        {
            for (int j = 1; j <= len; j++)
            {
                std::putchar(ans[i][j] ? 'X' : ' ');
            }
            std::putchar('\n');
        }
        std::puts("-");
    }
    int main()
    {
        while (true)
        {
            std::memset(ans, false, sizeof(ans));
            scanf("%d", &n);
            if (n == -1)
            {
                break;
            }
            solve(n, 1, 1);
            output(n);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}