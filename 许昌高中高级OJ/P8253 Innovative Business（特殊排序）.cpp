#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1000 + 5;
    int n;
    bool cmp[MAXN][MAXN];
    void input()
    {
        int l = 1, r = 1, i = 1, j = 1;
        std::string s;
        std::cin >> s;
        while (s.find('[', l) != std::string::npos)
        {
            l = s.find('[', l);
            r = s.find(']', l);
            std::string nums = s.substr(l, r - l + 1);
            int numl = 1, numr = nums.find(',', numl + 1);
            while (true)
            {
                cmp[i][j] = std::stoi(nums.substr(numl, numr - numl + 1)), j++;
                if (nums.find(' ', numl) == std::string::npos)
                {
                    break;
                }
                numl = nums.find(' ', numl), numr = nums.find(',', numl + 1);
            }
            i++;
        }
        n = i - 1;
    }
    bool compare(int a, int b)
    {
        return cmp[a][b];
    }
    int main()
    {
        input();
        std::vector<int> ans;
        for (int i = 1; i <= n; i++)
        {
            ans.push_back(i);
        }
        std::stable_sort(ans.begin(), ans.end(), compare);
        for (auto &i : ans)
        {
            printf("%d ", i);
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