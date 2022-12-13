#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,nums[1005][8];
	int numsn[1005][34];
	int ans[8];
	memset(ans,0,sizeof(ans));
	memset(numsn,0,sizeof(numsn));
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		nums[i][0]=0;
		for(int j=1;j<=7;j++)
		{
			cin>>nums[i][j];
		}
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=1;j<=7;j++)
		{
			numsn[i][nums[i][j]]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=33;j++)
		{
			nums[i][0]+=min(numsn[i][j],numsn[0][j]);
		}
		ans[nums[i][0]]++;
	}
	for(int i=7;i>=1;i--)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
