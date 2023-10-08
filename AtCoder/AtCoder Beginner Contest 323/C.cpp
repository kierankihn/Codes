#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 100 + 5;
    using std::printf;
    using std::scanf;
    int n, m;
    int cnt = 0;
    int pro[MAXN];
    int score[MAXN];
    char s[MAXN][MAXN];
    std::pair<int, int> p[MAXN];
    int main()
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
        {
            scanf("%d", &pro[i]);
            p[i].first = pro[i], p[i].second = i;
        }
        std::sort(p + 1, p + n + 1);
        std::reverse(p + 1, p + n + 1);
        for (int i = 1; i <= n; i++)
        {
            scanf("%s", s[i] + 1);
            for (int j = 1; j <= m; j++)
            {
                if (s[i][j] == 'o')
                {
                    score[i] += pro[j];
                }
            }
            score[i] += i;
            if (score[i] > score[0])
            {
                score[0] = score[i], cnt = 1;
            }
            else if (score[i] == score[0])
            {
                cnt++;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            int res = 0;
            if (score[i] == score[0] && cnt == 1)
            {
                printf("%d\n", 0);
                continue;
            }
            for (auto &now : p)
            {
                if (s[i][now.second] == 'x')
                {
                    res++;
                    score[i] += now.first;
                }
                if (score[i] > score[0])
                {
                    break;
                }
            }
            printf("%d\n", res);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}