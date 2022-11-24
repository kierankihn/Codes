#include <bits/stdc++.h>
using namespace std;
int cell[105][105];
int m,n;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
int idx[105][105]={};
int cnt=0;
void DFS(int x,int y,int id)
{
    if(x<=0||x>m||y<=0||y>n)
    {
        return;
    }
    if(idx[x][y]>0)
    {
        return;
    }
    if(cell[x][y]==0)
    {
        return;
    }
    idx[x][y]=id;
    for(int i=0;i<4;i++)
    {
        if((cell[x+dx[i]]!=0) && (cell[y+dy[i]]!=0))
        {
            DFS(x+dx[i],y+dy[i],id);
            // cout<<x+dx[i]<<" "<<y+dy[i]<<endl;
        }
    }
}
int main()
{
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            char temp;
            cin>>temp;
            cell[i][j]=temp-'0';
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(idx[i][j]==0 && cell[i][j]!=0)
            {
                DFS(i,j,++cnt);
            }
        }
    }
    cout<<cnt<<endl;
}
