#include <bits/stdc++.h>
using namespace std;
bool check(int a[20005],int n)
{
	int tmp[20005];
	tmp[0]=-1;
	tmp[n]=1;
	for(int i=1;i<n;i++)
	{
		if(a[i+1]==a[i])
		{
			tmp[i]=0;
		}
		else if(a[i+1]>a[i])
		{
			tmp[i]=1;
		}
		else if(a[i+1]<a[i])
		{
			tmp[i]=-1;
		}
	}
	bool isok=false;
	for(int i=0;i<=n+1;i++)
	{
		if(tmp[i-1]==1)
		{
			isok=true;
		}
		if(tmp[i-1]==-1 && isok)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int t;
	int n;
	int a[20005];
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(check(a,n))
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
	return 0;
}
