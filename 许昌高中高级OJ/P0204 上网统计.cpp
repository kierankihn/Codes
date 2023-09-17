#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e3 + 5;
    int n, m;
    int tot = 0;
    std::string name[MAXN];
    std::map<std::string, int> mp;
    std::vector<std::string> s[MAXN];
    int main()
    {
        std::scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
        {
            std::string user_name, user_web;
            std::cin >> user_name >> user_web;
            if (mp[user_name] == 0)
            {
                mp[user_name] = ++tot;
                name[tot] = user_name;
            }
            s[mp[user_name]].push_back(user_web);
        }
        for (int i = 1; i <= tot; i++)
        {
            std::cout << name[i] << " ";
            for (auto &user_web : s[i])
            {
                std::cout << user_web << " ";
            }
            std::cout << std::endl;
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}