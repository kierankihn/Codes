#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
const int MAXN = 105;
bool cell[MAXN][MAXN];
int ans = 0;
int m, n;
void BFS(int x, int y)
{
    ans++;
    int dl[1005][3];
    dl[1][1] = x;
    dl[1][2] = y;
    int head = 0;
    int tail = 1;
    cell[x][y]=0;
    do
    {
        head++;
        for (int i = 0; i < 4; i++)
        {
            int newx, newy;
            newx = dl[head][1] + dx[i];
            newy = dl[head][2] + dy[i];
            if ((newx > 0 && newx <= m) && (newy > 0 && newy <= n) && cell[newx][newy])
            {
                tail++;
                dl[tail][1] = newx;
                dl[tail][2] = newy;
                cell[newx][newy]=0;
            }
        }
    } while (head < tail);
}
int main()
{
    cin >> m >> n;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cell[i][j]=1;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char temp;
            cin >> temp;
            if(temp=='0')
            {
                cell[i][j]=0;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(cell[i][j])
            {
                BFS(i,j);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
