#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
const int MAXN=50;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
int map[MAXN+5][MAXN+5];
int m,n;    //行列
int p1,p2;  //起始位置
int q1,q2;  //终点
vector< vector<int> > ans;
bool DFS(int x,int y)
{
	if((x==q1)&&(y==q2))
	{
		return true;
	}
	if(x<=0||x>m||y<=0||y>n)
	{
		return false;
	}
	for(int i=0;i<4;i++)
	{
		if(DFS(x+dx[i],y+dy[i]))
		{
			vector<int> temp;
			temp.push_back(x+dx[i]);
			temp.push_back(y+dy[i]);
			ans.push_back(temp);
			return true;
		}
	}
	return false;
}
int main()
{
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
	DFS(p1,p2);
	if(ans.empty())
	{
		cout<<"NO WAY!\n";
	}
	else
	{
		for(int i=ans.size()-1;i>=0;i--)
		{
			cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
		}
	}
}
