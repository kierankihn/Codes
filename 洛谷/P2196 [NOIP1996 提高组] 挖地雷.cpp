#include <bits/stdc++.h>
using namespace std;
const int MAXN=200;
int n;
int res=-1;
int mp[MAXN+5][MAXN+5];
int dp[MAXN+5][3];  //0Ϊԭ���� 1Ϊdp 2Ϊ��һ����
int solve(int k)
{
	int ans=dp[k][0];
	if(dp[k][1]!=-1)
	{
		return dp[k][1];
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(mp[k][i])
			{
				if(ans<solve(i)+dp[k][0])
				{
					ans=solve(i)+dp[k][0];
					dp[k][2]=i;
				}
			}
		}
	}
	return dp[k][1]=ans;
}
void print_ans(int k)
{
	cout<<k;
	if(dp[k][2]!=-1)
	{
		cout<<" ";
		print_ans(dp[k][2]);
	}
}
int main()
{
	memset(mp,0,sizeof(mp));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>dp[i][0];
		dp[i][1]=-1;
		dp[i][2]=-1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			cin>>mp[i][j];
		}
	}
	int p;
	for(int i=1;i<=n;i++)
	{
		if(solve(i)>res)
		{
			res=solve(i);
			p=i;
		}
	}
	print_ans(p);
	cout<<endl;
	cout<<res<<endl;
	return 0;
}
