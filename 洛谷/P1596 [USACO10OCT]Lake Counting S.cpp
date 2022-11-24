#include <bits/stdc++.h>
using namespace std;
const int MAXN=100;
int a[MAXN+5][MAXN+5];
int idx[MAXN+5][MAXN+5];
int dx[8]={0,0,1,1,1,-1,-1,-1};
int dy[8]={1,-1,0,1,-1,0,1,-1};
int m,n;
void DFS(int x,int y,int cnt)
{
	for(int i=0;i<8;i++)
	{
		int newx=x+dx[i];
		int newy=y+dy[i];
		if((newx>0&&newx<=n)&&(newy>0&&newy<=m)&&(idx[newx][newy]==-1)&&(a[newx][newy]==1))
		{
			idx[newx][newy]=cnt;
			DFS(newx,newy,cnt);
		}
	}
}
int main()
{
	int cnt=0;
	cin>>n>>m;
	memset(idx,-1,sizeof(idx));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char temp;
			cin>>temp;
			if(temp=='W')
			{
				a[i][j]=1;
			}
			else
			{
				a[i][j]=0;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if((a[i][j]==1)&&(idx[i][j]==-1))
			{
				DFS(i,j,++cnt);
			}
		}
	}
	cout<<cnt;
}
