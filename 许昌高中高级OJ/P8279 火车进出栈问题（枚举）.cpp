#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 20 + 5;
    int n;
    int cnt = 0;
    int a[MAXN];
    bool check()
    {
        int now = 0;
        std::stack<int> s;
        for (int i = 1; i <= n; i++)
        {
            while (now <= n && (s.empty() || a[i] > s.top()))
            {
                s.push(++now);
            }
            if (s.empty() || a[i] < s.top() || now > n)
            {
                return false;
            }
            if (a[i] == s.top())
            {
                s.pop();
            }
        }
        return true;
    }
    int main()
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            a[i] = i;
        }
        while (cnt < 20)
        {
            if (check())
            {
                for (int i = 1; i <= n; i++)
                {
                    printf("%d", a[i]);
                }
                printf("\n");
                cnt++;
            }
            if (!std::next_permutation(a + 1, a + n + 1))
            {
                break;
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