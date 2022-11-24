#include <iostream>
#include <string.h>
using namespace std;
const int MAXN=1005;
bool map[MAXN][MAXN];
int m;
int p1,q1; //代表起始位置的坐标 
int p2,q2; //代表目标位置的坐标 
int dl[1000005][3];  //BFS队列 
int idx[MAXN][MAXN]; //到达该位置最少需要几步， -1代表无法到达 
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
void init()
{
	ios::sync_with_stdio(false);
	cin>>m;
	memset(map,0,sizeof(map));
	memset(idx,-1,sizeof(idx));
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char temp;
			cin>>temp;
			if(temp=='0')
			{
				map[i][j]=1;
			}
		}
	}
	cin>>p1>>q1>>p2>>q2;
	return;
}

void BFS()
{
	int head=1,tail=1;
	dl[head][1]=p1;
	dl[head][2]=q1;
	idx[p1][q1]=0;
	while(head<=tail)
	{
		if((dl[head][1]==p2)&&(dl[head][2]==q2))
		{
			break;
		}
		for(int i=0;i<4;i++)
		{
			int newx=dl[head][1]+dx[i];
			int newy=dl[head][2]+dy[i];
			if((newx>0&&newx<=m)&&(newy>0&&newy<=m)&&(idx[newx][newy]==-1)&&(map[newx][newy]==1))
			{
				tail++;
				dl[tail][1]=newx;
				dl[tail][2]=newy;
				idx[newx][newy]=idx[dl[head][1]][dl[head][2]]+1;
			}
		}
		head++;
	}
}
int main()
{
	init();
	BFS();
	cout<<idx[p2][q2];
	return 0;
}
