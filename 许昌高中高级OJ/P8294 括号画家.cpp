#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e6 + 5;
    int n;
    int ans = 0;
    char str[MAXN];
    bool vis[MAXN];
    std::map<char, char> mp;
    std::stack<std::pair<char, int>> s;
    int main()
    {
        mp[')'] = '(', mp[']'] = '[', mp['}'] = '{';
        scanf("%s", str + 1);
        n = std::strlen(str + 1);
        for (int i = 1; i <= n; i++)
        {
            if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            {
                s.push(std::make_pair(str[i], i));
            }
            if (str[i] == ')' || str[i] == ']' || str[i] == '}')
            {
                if (s.empty() || s.top().first != mp[str[i]])
                {
                    while (!s.empty())
                    {
                        s.pop();
                    }
                }
                else
                {
                    vis[i] = true, vis[s.top().second] = true;
                    s.pop();
                }
            }
        }
        int startpos = 1;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
            {
                ans = std::max(ans, i - startpos + 1);
            }
            else
            {
                startpos = i + 1;
            }
        }
        printf("%d\n", ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}