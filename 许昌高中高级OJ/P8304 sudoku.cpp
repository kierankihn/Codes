#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    typedef unsigned int UI;
    typedef unsigned long long ULL;
    const int MAXL = 81 + 5;
    char s[MAXL];
    int len = 81;
    int count[1ULL << 9ULL], num[1ULL << 9ULL];
    UI col[10], line[10], grid[10];
    int lowbit(int x)
    {
        return x & (-x);
    }
    int getGridId(int x, int y)
    {
        return x / 3 + y / 3 * 3;
    }
    int getGridId(int point_id)
    {
        int x = point_id % 9, y = point_id / 9;
        return getGridId(x, y);
    }
    int popcount(int x)
    {
        if (!count[x])
        {
            return count[x] = __builtin_popcount(x);
        }
        return count[x];
    }
    bool dfs(int u)
    {
        if (u == 0)
        {
            return true;
        }
        int minpopcount = 10, pos = 0;
        for (int i = 0; i < len; i++)
        {
            if (s[i] != '.')
            {
                continue;
            }
            int val = col[i % 9] & line[i / 9] & grid[getGridId(i)];
            if (!val)
            {
                return false;
            }
            if (popcount(val) < minpopcount)
            {
                minpopcount = popcount(val);
                pos = i;
            }
        }
        int val = col[pos % 9] & line[pos / 9] & grid[getGridId(pos)];
        while (val)
        {
            s[pos] = num[lowbit(val)] + '1';
            col[pos % 9] ^= lowbit(val), line[pos / 9] ^= lowbit(val), grid[getGridId(pos)] ^= lowbit(val);
            if (dfs(u - 1))
            {
                return true;
            }
            col[pos % 9] ^= lowbit(val), line[pos / 9] ^= lowbit(val), grid[getGridId(pos)] ^= lowbit(val);
            s[pos] = '.';
            val -= lowbit(val);
        }
        return false;
    }
    int main()
    {
        for (int i = 0; i < 9; i++)
        {
            num[1 << i] = i;
        }
        while (std::scanf("%s", s))
        {
            if (s[0] == 'e')
            {
                break;
            }
            int root = 0;
            for (int i = 0; i < 9; i++)
            {
                col[i] = line[i] = grid[i] = 511;
            }
            for (int i = 0; i < len; i++)
            {
                if (s[i] != '.')
                {
                    col[i % 9] = col[i % 9] & (~(1 << (s[i] - '1')));
                    line[i / 9] = line[i / 9] & (~(1 << (s[i] - '1')));
                    grid[getGridId(i)] = grid[getGridId(i)] & (~(1 << (s[i] - '1')));
                }
                else
                {
                    root++;
                }
            }
            dfs(root);
            printf("%s\n", s);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}