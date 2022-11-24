#include <bits/stdc++.h>
using namespace std;
int main()
{
	int l,m,n;
	cin>>l>>n>>m;
	int stone[50005];
	long long dist[50005];
	stone[0]=0;
	stone[n+1]=l;
	for(int i=1;i<=n;i++)
	{
		cin>>stone[i];
	}
	for(int i=0;i<=n;i++)
	{
		dist[i]=stone[i+1]-stone[i];
	}
	for(int i=1;i<=m;i++)
	{
		long long mindist=1e9;
		int pl;
		for(int j=0;j<=n;j++)
		{
			if(mindist>dist[j])
			{
				mindist=dist[j];
				pl=j;
			}
		}
		if(pl==0)
		{
			long long temp=dist[pl]+dist[pl+1];
			dist[pl]=dist[pl+1]=temp;
		}
		if(pl==n)
		{
			long long temp=dist[pl]+dist[pl-1];
			dist[pl]=dist[pl-1]=temp;
		}
		if(pl>0 && pl<n)
		{
			if(dist[pl-1]<dist[pl+1])
			{
				long long temp=dist[pl]+dist[pl-1];
				dist[pl]=dist[pl-1]=temp;
			}
			else
			{
				long long temp=dist[pl]+dist[pl+1];
				dist[pl]=dist[pl+1]=temp;
			}
		}
	}
	long long ans=1e9;
	for(int j=0;j<=n;j++)
	{
		if(ans>dist[j])
		{
			ans=dist[j];
		}
	}
	cout<<ans<<endl;
	return 0;
}
