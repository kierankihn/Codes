#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
const int INF = 0x3f3f3f3f;
int n;
int v;
int mp[MAXN + 5][MAXN + 5];
int main()
{
    string tmp;
    cin >> n >> v;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> tmp;
            if (tmp == "-")
            {
                mp[i][j] = INF;
            }
            else
            {
                mp[i][j] = stoi(tmp);
            }
        }
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
        if (i == v)
        {
            continue;
        }
        cout << "(" << v << " -> " << i << ") = " << mp[v][i] << endl;
    }
    return 0;
}