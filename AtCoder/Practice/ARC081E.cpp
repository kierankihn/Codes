#include <bits/stdc++.h>
namespace solution
{
    typedef char chr;
    typedef bool bol;
    typedef double dbi;
    typedef long long i64;
    typedef std::pair<int, char> pic;
    const int MAXN = 2e5 + 5;
    const int MAXCHR = 'z' + 5;
    const int INF = 0x3f3f3f3f;
    int n;
    chr a[MAXN];
    int pre[MAXN], next[MAXN][MAXCHR];
    pic bfs()
    {
        std::fill(pre, pre + MAXN, -1);
        std::queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int i = 'a'; i <= 'z'; i++)
            {
                if (next[u + 1][i] == 0)
                {
                    return {u, i};
                }
                if (pre[next[u + 1][i]] == -1)
                {
                    q.push(next[u + 1][i]);
                    pre[next[u + 1][i]] = u;
                }
            }
        }
        return {INF, '?'};
    }
    std::string solve(pic x)
    {
        std::string res;
        res.push_back(x.second);
        int u = x.first;
        while (u != 0)
        {
            res.push_back(a[u]), u = pre[u];
        }
        return res.assign(res.rbegin(), res.rend());
    }
    int main()
    {
        scanf("%s", a + 1);
        n = std::strlen(a + 1);
        for (int i = n; i >= 0; i--)
        {
            for (int j = 'a'; j <= 'z'; j++)
            {
                next[i][j] = next[i + 1][j];
            }
            next[i][(int)a[i]] = i;
        }
        std::cout << solve(bfs()) << std::endl;
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}