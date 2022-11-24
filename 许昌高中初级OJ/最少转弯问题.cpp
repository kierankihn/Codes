#include <bits/stdc++.h>
using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int turn[1005][1005];
int mp[1005][1005];
int que[1000005][3];
int m,n;
int p1,p2;
int q1,q2;
void BFS()
{
	memset(turn,0x7f,sizeof(turn));
	int head,tail;
	head=1;
	tail=1;
	que[head][1]=p1;
	que[head][2]=p2;
	while(head<=tail)
	{
		for(int i=0;i<4;i++)
		{
			int newx=que[head][1]+dx[i];
			int newy=que[head][2]+dy[i];
			while((newx>0&&newx<=m)&&(newy>0&&newy<=n)&&(mp[newx][newy]==0))
			{
				if(turn[que[head][1]][que[head][2]]+1<turn[newx][newy])
				{
					turn[newx][newy]=turn[que[head][1]][que[head][2]]+1;
					tail++;
					mp[newx][newy]=1;
					que[tail][1]=newx;
					que[tail][2]=newy;
				}
			}
		}
		head++;
	}
}
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>mp[i][j];
		}
	}
	cin>>p1>>p2;
	cin>>q1>>q2;
	BFS();
	cout<<turn[q1][q2];
	return 0;
}
