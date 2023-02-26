#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
int n, t;
int ans = -1;
int timecost[MAXN + 5];
struct Fish
{
    int num;
    int del;
    int cost;
    bool operator<(struct Fish a) const
    {
        return num < a.num;
    }
};
struct Fish fish[MAXN + 5];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> fish[i].num;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> fish[i].del;
    }
    for (int i = 1; i < n; i++)
    {
        cin >> fish[i].cost;
        timecost[i + 1] = timecost[i] + fish[i].cost;
    }
    cin >> t;
    for (int i = 1; i <= n; i++)
    {
        int res = 0;
        int t_ = t - timecost[i];
        priority_queue<struct Fish> dl;
        for (int j = 1; j <= i; j++)
        {
            dl.push(fish[j]);
        }
        while ((t_ > 0) && (!dl.empty()))
        {
            struct Fish tmp = dl.top();
            dl.pop();
            res += tmp.num;
            tmp.num = max(0, tmp.num - tmp.del);
            if (tmp.num > 0)
            {
                dl.push(tmp);
            }
            t_--;
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
    return 0;
}