#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e6 + 5;
    int n;
    int cnt = 0;
    char s[MAXN];
    int nxt[MAXN];
    void calcNextArray()
    {
        nxt[1] = 0;
        for (int i = 2, j = 0; i <= n; i++)
        {
            while (j > 0 && s[i] != s[j + 1])
            {
                j = nxt[j];
            }
            if (s[i] == s[j + 1])
            {
                j++;
            }
            nxt[i] = j;
        }
    }
    int main()
    {
        while (scanf("%d", &n) && n != 0)
        {
            scanf("%s", s + 1);
            calcNextArray();
            printf("Test case #%d\n", ++cnt);
            for (int i = 2; i <= n; i++)
            {
                if (i % (i - nxt[i]) == 0 && i / (i - nxt[i]) > 1)
                {
                    printf("%d %d\n", i, i / (i - nxt[i]));
                }
            }
            printf("\n");
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}