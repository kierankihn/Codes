#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 100 + 5;
    using std::printf;
    using std::scanf;
    int n;
    struct Node
    {
        int cnt, id;
    };
    bool operator<(const Node a, const Node b)
    {
        if (a.cnt == b.cnt)
        {
            return a.id < b.id;
        }
        return a.cnt > b.cnt;
    }
    Node node[MAXN];
    std::string s;
    int main()
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            node[i].id = i;
            std::cin >> s;
            for (int j = 0; j < n; j++)
            {
                if (s[j] == 'o')
                {
                    node[i].cnt++;
                }
            }
        }
        std::sort(node + 1, node + n + 1);
        for (int i = 1; i <= n; i++)
        {
            printf("%d%c", node[i].id, i == n ? '\n' : ' ');
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}