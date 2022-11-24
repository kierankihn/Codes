#include <iostream>
#include <string.h>
using namespace std;
const int MAXN=50;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
int map[MAXN+5][MAXN+5];
int dl[MAXN*MAXN+5][3];
int ans[MAXN*MAXN+5];
int vis[MAXN+5][MAXN+5];
int m,n;    //行列
int p1,p2;  //起始位置
int q1,q2;  //终点 
int res;
void print(int x)
{
	if(x!=1)
	{
		print(ans[x]);
	}
	cout<<dl[x][1]<<" "<<dl[x][2]<<endl;
}
void BFS()
{
	int head=1,tail=1;
	dl[head][1]=p1;
	dl[head][2]=p2;
	vis[p1][p2]=0;
	while(head<=tail)
	{
		if(dl[head][1]==q1 && dl[head][2]==q2)
		{
			res=head;
			return;
		}
		for(int i=0;i<4;i++)
		{
			int newx=dl[head][1]+dx[i];
			int newy=dl[head][2]+dy[i];
			if((newx>0&&newx<=m)&&(newy>0&&newy<=n)&&(vis[newx][newy]==-1)&&(map[newx][newy]==0))
			{
				tail++;
				dl[tail][1]=newx;
				dl[tail][2]=newy;
				ans[tail]=head;
				vis[newx][newy]=vis[dl[head][1]][dl[head][2]]+1;
			}
		}
		head++;
	}
}
int main()
{
	memset(vis,-1,sizeof(vis));
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>map[i][j];
		}
	}
	cin>>p1>>p2;
	cin>>q1>>q2;
	BFS();
	if(vis[q1][q2]==-1)
	{
		cout<<"NO WAY!\n";
	}
	else
	{
		print(res);
	}
}
