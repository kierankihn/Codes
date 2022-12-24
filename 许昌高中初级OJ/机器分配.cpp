#include <bits/stdc++.h>
using namespace std;
const int MAXM = 15;
const int MAXN = 10;
int n, m;
int gain[MAXN + 5][MAXM + 5];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> gain[i][j];
        }
    }
    
    return 0;
}