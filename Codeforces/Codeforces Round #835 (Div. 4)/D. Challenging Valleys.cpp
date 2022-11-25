#include <bits/stdc++.h>
using namespace std;
bool check(int a[20005],int n)
{
	int ans=0;
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
	int p,q;
	p=q=1;
	while(p<=n)
	{
		if(tmp[p-1]!=-1)
		{
			p++;
			q=p;
			continue;
		}
		while(tmp[q]==0)
		{
			q++;
		}
		if(tmp[q]==1)
		{
			ans++;
			p=q+1;
			q=p;
		}
		else
		{
			p=q=q+1;
		}
	}
	return ans==1;
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
