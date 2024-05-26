#include <bits/stdc++.h>
namespace solution
{
    typedef long long i64;
    int n, k;
    void del(std::vector<int> &x)
    {
        if (x.back() == 1)
        {
            x.pop_back();
            return;
        }
        if (x.size() == n)
        {
            x.back()--;
        }
        else
        {
            x.back()--;
            while (x.size() != n)
            {
                x.push_back(k);
            }
        }
    }
    void move(std::vector<int> &x, int step)
    {
        while (step)
        {
            del(x);
            step--;
        }
    }
    int main()
    {
        scanf("%d%d", &k, &n);
        std::vector<int> ans;
        if (k & 1)
        {
            for (int i = 1; i <= n; i++)
            {
                ans.push_back((k + 1) / 2);
            }
            move(ans, n / 2);
        }
        else
        {
            ans.push_back(k / 2);
            for (int i = 1; i < n; i++)
            {
                ans.push_back(k);
            }
        }
        for (auto i : ans)
        {
            printf("%d ", i);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}