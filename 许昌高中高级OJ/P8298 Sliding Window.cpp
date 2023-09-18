#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e6 + 5;
    int n, m;
    int val[MAXN];
    std::priority_queue<std::pair<int, int>> qmax;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> qmin;
    int main()
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &val[i]);
            if (i < m)
            {
                qmax.push(std::make_pair(val[i], i));
                qmin.push(std::make_pair(val[i], i));
            }
        }
        for (int i = m; i <= n; i++)
        {
            qmin.push(std::make_pair(val[i], i));
            auto min = qmin.top();
            while (!qmin.empty() && min.second <= i - m)
            {
                qmin.pop();
                min = qmin.top();
            }
            printf("%d ", min.first);
        }
        printf("\n");
        for (int i = m; i <= n; i++)
        {
            qmax.push(std::make_pair(val[i], i));
            auto max = qmax.top();
            while (!qmax.empty() && max.second <= i - m)
            {
                qmax.pop();
                max = qmax.top();
            }
            printf("%d ", max.first);
        }
        printf("\n");
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}