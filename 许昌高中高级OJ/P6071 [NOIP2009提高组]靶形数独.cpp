#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 9 + 5;
    const int MAXC = (1 << 9) + 5;
    const int g[9][9] = {
        {6, 6, 6, 6, 6, 6, 6, 6, 6},
        {6, 7, 7, 7, 7, 7, 7, 7, 6},
        {6, 7, 8, 8, 8, 8, 8, 7, 6},
        {6, 7, 8, 9, 9, 9, 8, 7, 6},
        {6, 7, 8, 9, 10, 9, 8, 7, 6},
        {6, 7, 8, 9, 9, 9, 8, 7, 6},
        {6, 7, 8, 8, 8, 8, 8, 7, 6},
        {6, 7, 7, 7, 7, 7, 7, 7, 6},
        {6, 6, 6, 6, 6, 6, 6, 6, 6},
    };
    int n = 9;
    int ans = 0;
    int root = 0;
    bool flag = false;
    int num[MAXN][MAXN];
    int c[MAXC], log[MAXC];
    int col[MAXN], line[MAXN], grid[MAXN];
    int lowbit(int x)
    {
        return x & (-x);
    }
    int getGridId(int x, int y)
    {
        return x / 3 * 3 + y / 3;
    }
    int popcount(int x)
    {
        if (c[x])
        {
            return c[x];
        }
        return c[x] = __builtin_popcount(x);
    }
    void solve(int u, int now)
    {
        if (u == 0)
        {
            flag = true;
            ans = std::max(ans, now);
            return;
        }
        if (now + u * 10 * 9 < ans)
        {
            return;
        }
        int minpopcount = 10, posx = 0, posy = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (num[i][j] != 0)
                {
                    continue;
                }
                int tmp = line[i] & col[j] & grid[getGridId(i, j)];
                if (tmp == 0)
                {
                    return;
                }
                if (popcount(tmp) < minpopcount)
                {
                    minpopcount = popcount(tmp), posx = i, posy = j;
                }
            }
        }
        int val = line[posx] & col[posy] & grid[getGridId(posx, posy)];
        while (val)
        {
            int v = lowbit(val);
            line[posx] ^= v, col[posy] ^= v, grid[getGridId(posx, posy)] ^= v;
            num[posx][posy] = log[v];
            solve(u - 1, now + log[v] * g[posx][posy]);
            num[posx][posy] = 0;
            line[posx] ^= v, col[posy] ^= v, grid[getGridId(posx, posy)] ^= v;
            val -= lowbit(val);
        }
    }
    int main()
    {
        for (int i = 0; i < n; i++)
        {
            log[1 << i] = i + 1;
            line[i] = col[i] = grid[i] = (1 << 9) - 1;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &num[i][j]);
                if (num[i][j] == 0)
                {
                    root++;
                }
                else
                {
                    ans += num[i][j] * g[i][j];
                    line[i] ^= 1 << (num[i][j] - 1), col[j] ^= 1 << (num[i][j] - 1), grid[getGridId(i, j)] ^= 1 << (num[i][j] - 1);
                }
            }
        }
        solve(root, ans);
        printf("%d\n", flag ? ans : -1);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}