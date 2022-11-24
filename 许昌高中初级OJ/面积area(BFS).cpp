#define _STL_MAP_H 1
#include <bits/stdc++.h>
//解决思路：在周围加一圈0之后，求外围0的连通块 
using namespace std;
const int MAXN=10;
int map[MAXN+5][MAXN+5];
int ans=0;
int num1=0;
bool vis[MAXN+5][MAXN+5];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
void BFS()
{
	int que[(MAXN+2)*(MAXN+2)+5][3];
	int head;
	int tail;
	head=tail=1;
	que[head][1]=0;
	que[head][2]=0;
	vis[0][0]=true;
	ans++;
	while(head<=tail)
	{
		for(int i=0;i<4;i++)
		{
			int newx=que[head][1]+dx[i];
			int newy=que[head][2]+dy[i];
			if((newx>=0&&newx<=MAXN+1)&&(newy>=0&&newy<=MAXN+1)&&(vis[newx][newy]==false)&&(map[newx][newy]==0))
			{
				ans++;
				tail++;
				que[tail][1]=newx;
				que[tail][2]=newy;
				vis[newx][newy]=true;
			}
		}
		head++;
	}
}
int main()
{
	for(int i=1;i<=MAXN;i++)
	{
		for(int j=1;j<=MAXN;j++)
		{
			cin>>map[i][j];
			if(map[i][j]==1)
			{
				num1++;
			}
		}
	}
	BFS();
	int res=(MAXN+2)*(MAXN+2)-ans-num1;
	cout<<res<<endl;
	return 0;
}
