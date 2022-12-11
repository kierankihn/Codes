#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e8;
int n,k;
int len[MAXN+5];
bool check(int l)
{
	int res=0;
	for(int i=1;i<=n;i++)
	{
		res+=len[i]/l;
	}
	return res>=k;
}
int main()
{
	cin>>n>>k;
	len[0]=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>len[i];
		len[0]=max(len[0],len[i]);
	}
	int l=1,r=len[0];
	int ans=0;
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
