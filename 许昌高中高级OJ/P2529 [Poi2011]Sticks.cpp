#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e6 + 5;
    int n;
    struct Node
    {
        int color, len;
    };
    bool operator<(const Node a, const Node b)
    {
        return a.len < b.len;
    }
    int tot = 0;
    int s1 = 0, s2 = 0, s3 = 0;
    Node node[MAXN];
    void output(int a, int b, int c)
    {
        printf("%d %d %d %d %d %d\n", node[a].color, node[a].len, node[b].color, node[b].len, node[c].color, node[c].len);
    }
    int main()
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            int k;
            scanf("%d", &k);
            for (int j = 1; j <= k; j++)
            {
                scanf("%d", &node[++tot].len);
                node[tot].color = i;
            }
        }
        std::sort(node + 1, node + tot + 1);
        for (int i = 1; i <= tot; i++)
        {
            if (node[i].color == node[s1].color)
            {
                if (node[s2].len + node[s3].len > node[i].len)
                {
                    output(s2, s3, i);
                    return 0;
                }
                s1 = i;
            }
            else if (node[i].color == node[s2].color)
            {
                if (node[s1].len + node[s3].len > node[i].len)
                {
                    output(i, s1, s3);
                    return 0;
                }
                s2 = s1, s1 = i;
            }
            else
            {
                if (node[s1].len + node[s2].len > node[i].len)
                {
                    output(i, s1, s2);
                    return 0;
                }
                s3 = s2, s2 = s1, s1 = i;
            }
        }
        puts("NIE");
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}