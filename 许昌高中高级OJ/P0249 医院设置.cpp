#include <bits/stdc++.h>
using namespace std;
const int MAXN=100;
int n;
int ans=0x3f3f3f3f;
int nums[MAXN+5];
int mp[MAXN+5][MAXN+5];
int main()
{
	memset(mp,0x3f,sizeof(mp));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>nums[i];
		cin>>x>>y;
		if(x)
		{
			mp[x][i]=mp[i][x]=1;
		}
		if(y)
		{
			mp[y][i]=mp[i][y]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		mp[i][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		int sum=0;
		for(int j=1;j<=n;j++)
		{
			sum+=nums[j]*mp[i][j];
		}
		ans=min(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}
