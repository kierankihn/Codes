#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1000 + 5;
    int t;
    int n;
    std::string s;
    bool check(std::string s)
    {
        int cnt0 = 0, cnt1 = 0;
        for (auto &c : s)
        {
            if (c == '0')
            {
                cnt0++;
            }
            if (c == '1')
            {
                cnt1++;
            }
        }
        return cnt0 == cnt1;
    }
    int main()
    {
        std::cin >> t;
        while (t--)
        {
            std::cin >> n;
            std::cin >> s;
            if (check(s) == false)
            {
                std::cout << -1 << std::endl;
            }
            else
            {
                std::vector<int> ans;
                size_t p = 0, q = s.size() - 1;
                while (p < q)
                {
                    if (s[p] == s[q])
                    {
                        if (s[p] == '1')
                        {
                            s.insert(p, "01"), ans.push_back(p);
                        }
                        else
                        {
                            s.insert(q + 1, "01"), ans.push_back(q + 1);
                        }
                        q += 2;
                    }
                    p++, q--;
                }
                std::cout << ans.size() << std::endl;
                for (auto &i : ans)
                {
                    std::cout << i << " ";
                }
                std::cout << std::endl;
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