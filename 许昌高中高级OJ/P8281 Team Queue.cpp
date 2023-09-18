#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXT = 1000 + 5;
    const int MAXN = 1e6 + 5;
    const int MAXLEN = 100 + 5;
    int t;
    int cnt = 0;
    std::queue<int> q[MAXT];
    int team[MAXN];
    int main()
    {
        while (scanf("%d", &t))
        {
            if (t == 0)
            {
                break;
            }
            char op[MAXLEN];
            for (int i = 1; i <= t; i++)
            {
                int n;
                scanf("%d", &n);
                for (int j = 1; j <= n; j++)
                {
                    int id;
                    scanf("%d", &id);
                    team[id] = i;
                }
            }
            printf("Scenario #%d\n", ++cnt);
            while (scanf("%s", op + 1) && op[1] != 'S')
            {
                if (op[1] == 'D')
                {
                    if (q[0].empty())
                    {
                        continue;
                    }
                    int nowq = q[0].front();
                    printf("%d\n", q[nowq].front());
                    q[nowq].pop();
                    if (q[nowq].empty())
                    {
                        q[0].pop();
                    }
                }
                if (op[1] == 'E')
                {
                    int x;
                    scanf("%d", &x);
                    if (q[team[x]].empty())
                    {
                        q[0].push(team[x]);
                    }
                    q[team[x]].push(x);
                }
            }
            for (auto &i : q)
            {
                while (!i.empty())
                {
                    i.pop();
                }
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