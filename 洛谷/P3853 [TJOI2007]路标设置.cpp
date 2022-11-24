#include <bits/stdc++.h>
using namespace std;
int L,N,K;
int pos[100005];
bool check(int t)
{
	if(t==0)
	{
		return false;
	}
	int add_n=0;
	for(int i=2;i<=N;i++)
	{
		add_n+=(pos[i]-pos[i-1])/t;
		if(add_n>K)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	cin>>L>>N>>K;
	for(int i=1;i<=N;i++)
	{
		cin>>pos[i];
	}
	int r=L,l=1;
	int ans;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			ans=mid;
			l=mid+1; 
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
