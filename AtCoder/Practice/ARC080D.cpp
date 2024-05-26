#include <bits/stdc++.h>
namespace solution
{
    typedef long long i64;
    const int MAXH = 1e3 + 5;
    const int MAXN = 1e5 + 5;
    int h, w;
    int n;
    int a[MAXN];
    int mp[MAXH][MAXH];
    int main()
    {
        scanf("%d%d", &h, &w);
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= h; i++)
        {
            int st, dif;
            if (i & 1)
            {
                st = 1, dif = 1;
            }
            else
            {
                st = w, dif = -1;
            }
            for (int j = st; 1 <= j && j <= w; j += dif)
            {
                if (a[a[0]] == 0)
                {
                    a[0]++;
                }
                mp[i][j] = a[0], a[a[0]]--;
            }
        }
        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                printf("%d%c", mp[i][j], j == w ? '\n' : ' ');
            }
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}
