#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 5 + 5;
    const int INF = 0x3f3f3f3f;
    int t;
    int n = 5;
    int mp[MAXN][MAXN];
    bool mark[MAXN][MAXN];
    void read(int &x)
    {
        char tmp = std::getchar();
        while ((tmp != '0') && (tmp != '1'))
        {
            tmp = std::getchar();
        }
        x = tmp - '0';
    }
    void input()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                read(mp[i][j]);
            }
        }
    }
    void click(int x, int y)
    {
        mark[x][y] = !mark[x][y], mark[x - 1][y] = !mark[x - 1][y], mark[x + 1][y] = !mark[x + 1][y], mark[x][y - 1] = !mark[x][y - 1], mark[x][y + 1] = !mark[x][y + 1];
    }
    int main()
    {
        std::cin >> t;
        while (t--)
        {
            input();
            int ans = INF;
            for (int k = 0; k <= (1 << n) - 1; k++)
            {
                int res = 0;
                for (int i = 1; i <= n; i++)
                {
                    for (int j = 1; j <= n; j++)
                    {
                        mark[i][j] = mp[i][j];
                    }
                }
                for (int i = 1; i <= 5; i++)
                {
                    if (k & (1 << (i - 1)))
                    {
                        click(1, i);
                        res++;
                    }
                }
                for (int i = 1; i < n; i++)
                {
                    for (int j = 1; j <= n; j++)
                    {
                        if (mark[i][j] == 0)
                        {
                            click(i + 1, j);
                            res++;
                        }
                    }
                }
                bool flag = true;
                for (int i = 1; i <= n; i++)
                {
                    if (mark[n][i] == false)
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag == true)
                {
                    ans = std::min(ans, res);
                }
            }
            printf("%d\n", (ans <= 6 ? ans : -1));
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}