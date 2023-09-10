#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXGROUP = 13 + 5;
    const int MAXN = 4 + 5;
    int n = 4;
    int group = 13;
    int now;
    int ans = 0;
    std::deque<int> card[MAXGROUP];
    int cnt[MAXGROUP];
    void read(char &x)
    {
        do
        {
            x = getchar();
        } while ((!std::isdigit(x)) && (!std::islower(x)) && (!std::isupper(x)));
    }
    void input()
    {
        for (int i = 1; i <= group; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                char tmp;
                read(tmp);
                if (tmp == 'A')
                {
                    card[i].push_back(1);
                }
                else if (tmp == 'J')
                {
                    card[i].push_back(11);
                }
                else if (tmp == 'Q')
                {
                    card[i].push_back(12);
                }
                else if (tmp == 'K')
                {
                    card[i].push_back(13);
                }
                else if (tmp == '0')
                {
                    card[i].push_back(10);
                }
                else
                {
                    card[i].push_back(tmp - '0');
                }
            }
        }
    }
    int main()
    {
        input();
        for (int i = 1; i <= n; i++)
        {
            now = card[13].front();
            card[13].pop_front();
            while (now != 13)
            {
                int newcard = card[now].back();
                card[now].pop_back();
                card[now].push_front(now);
                cnt[now]++;
                now = newcard;
            }
        }
        for (int i = 1; i <= group; i++)
        {
            if (cnt[i] == 4)
            {
                ans++;
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