#include <bits/stdc++.h>
using namespace std;
const int MAXR=1000;
int r;
int nums[MAXR+5][MAXR+5];
int dp[MAXR+5][MAXR+5];
int solve(int i,int j)
{
	if(dp[i][j]!=-1)
	{
		return dp[i][j];
	}
	return dp[i][j]=max(solve(i+1,j),solve(i+1,j+1))+nums[i][j];
}
int main()
{
	memset(dp,-1,sizeof(dp));
	cin>>r;
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=i;j++)
		{
			cin>>nums[i][j];
		}
	}
	for(int i=1;i<=r;i++)
	{
		dp[r][i]=nums[r][i];
	}
	cout<<solve(1,1)<<endl;
	
	return 0;
}
