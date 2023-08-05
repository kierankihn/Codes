#include <bits/stdc++.h>
using namespace std;
namespace solution
{
    const int MAXN = 1e6 + 5;
    int n;
    int ans = 0;
    char str[MAXN];
    bool vis[MAXN];
    int maxstartpos, maxendpos, startpos, endpos;
    stack<pair<char, int>> s;
    int main()
    {
        scanf("%s", str + 1);
        n = strlen(str + 1);
        for (int i = 1; i <= n; i++)
        {
            if (str[i] == '(' || str[i] == '[')
            {
                s.push(pair<char, int>(str[i], i));
                continue;
            }
            if (str[i] == ']')
            {
                if (!s.empty() && s.top().first == '[')
                {
                    vis[i] = true, vis[s.top().second] = true;
                    s.pop();
                    continue;
                }
                else
                {
                    while (!s.empty())
                    {
                        s.pop();
                    }
                    continue;
                }
            }
            if (str[i] == ')')
            {
                if (!s.empty() && s.top().first == '(')
                {
                    vis[i] = true, vis[s.top().second] = true;
                    s.pop();
                    continue;
                }
                else
                {
                    while (!s.empty())
                    {
                        s.pop();
                    }
                    continue;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
            {
                endpos = i;
                if (endpos - startpos > maxendpos - maxstartpos)
                {
                    maxendpos = endpos, maxstartpos = startpos;
                }
            }
            else
            {
                startpos = i + 1;
            }
        }
        for (int i = maxstartpos; i <= maxendpos; i++)
        {
            printf("%c", str[i]);
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