#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 2e6 + 5;
    int n;
    int cnt = 0;
    int p[MAXN];
    char input[MAXN], s[MAXN];
    int main()
    {
        while (scanf("%s", input + 1))
        {
            cnt++;
            if (input[1] == 'E')
            {
                break;
            }
            n = std::strlen(input + 1);
            for (int i = 1; i <= n; i++)
            {
                s[i * 2] = input[i];
                s[i * 2 - 1] = s[i * 2 + 1] = '#';
            }
            n = n * 2 + 1;
            int pos = 1, ans = 1, max = 1;
            p[1] = 1;
            for (int i = 1; i <= n; i++)
            {
                if (i > max)
                {
                    p[i] = 1;
                }
                else
                {
                    p[i] = std::min(p[pos * 2 - i], max - i);
                }
                while (s[i - p[i]] == s[i + p[i]] && 1 <= i - p[i] && i + p[i] <= n)
                {
                    p[i]++;
                }
                if (max < p[i] + i)
                {
                    max = p[i] + i, pos = i;
                }
                ans = std::max(ans, p[i] - 1);
            }
            printf("Case %d: %d\n", cnt, ans);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}