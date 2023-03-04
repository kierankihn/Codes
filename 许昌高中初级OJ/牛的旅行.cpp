#include <bits/stdc++.h>
using namespace std;
double INF;
const int MAXN = 150;
int n;
double ans;
int pos[MAXN + 5][3];
int maxpos[MAXN + 5];
double maxlen[MAXN + 5];
double mp[MAXN + 5][MAXN + 5];
vector<set<int>> lzh;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(mp, 127, sizeof(mp));
    INF = mp[0][0];
    ans = INF;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> pos[i][1] >> pos[i][2];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char tmp;
            cin >> tmp;
            if (tmp - '0')
            {
                mp[i][j] = sqrt(pow(abs(pos[i][1] - pos[j][1]), 2) + pow(abs(pos[i][2] - pos[j][2]), 2));
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        mp[i][i] = 0;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        bool isok = false;
        for (unsigned int j = 0; j < lzh.size(); j++)
        {
            if (mp[i][(*lzh[j].begin())] != INF)
            {
                lzh[j].insert(i);
                pos[i][0] = j;
                isok = true;
                break;
            }
        }
        if (!isok)
        {
            set<int> tmp;
            tmp.insert(i);
            lzh.push_back(tmp);
            pos[i][0] = lzh.size() - 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        mp[i][0] = 0;
        for (set<int>::iterator j = lzh[pos[i][0]].begin(); j != lzh[pos[i][0]].end(); j++)
        {
            mp[i][0] = max(mp[i][0], mp[i][*j]);
        }
    }
    for (unsigned int i = 0; i < lzh.size(); i++)
    {
        for (set<int>::iterator j = lzh[i].begin(); j != lzh[i].end(); j++)
        {
            maxlen[i] = max(maxlen[i], mp[*j][0]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (pos[i][0] == pos[j][0])
            {
                continue;
            }
            double tmp = mp[i][0] + mp[j][0] + sqrt(pow(abs(pos[i][1] - pos[j][1]), 2) + pow(abs(pos[i][2] - pos[j][2]), 2));
            tmp = max(tmp, maxlen[pos[i][0]]);
            tmp = max(tmp, maxlen[pos[j][0]]);
            ans = min(ans, tmp);
        }
    }
    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}