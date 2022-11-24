#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e4;
int main()
{
	int n,m;
	int cost[MAXN+5];
	int temp[MAXN+5];
	int ans=-1;
	cin>>n>>m;
	m=n-m;
	for(int i=1;i<=n;i++)
	{
		cin>>cost[i];
	}
	for(int i=1;i<=n-1;i++)
	{
		temp[i]=cost[i]+cost[i+1];
	}
	for(int i=1;i<=m;i++)
	{
		int min=1e9,res;
		for(int j=1;j<=n-i;j++)
		{
			if(temp[j]<min)
			{
				min=temp[j];
				res=j;
			}
		}
		cost[res]=temp[res];
		for(int j=res+1;j<=n-i;j++)
		{
			cost[j]=cost[j+1];
		}
		temp[res-1]=cost[res-1]+cost[res];
		temp[res]=cost[res]+cost[res+1];
		for(int j=res+1;j<=n-i-1;j++)
		{
			temp[j]=temp[j+1];
		}
	}
	for(int i=1;i<=n-m;i++)
	{
		if(ans<cost[i])
		{
			ans=cost[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}
