#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200;
int n;
int ans;
int num[MAXN*2+5];
int sum[MAXN*2+5];
int dp[MAXN*2+5][MAXN*2+5];
inline int readInt()
{
	int res=0,k=1;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			k=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		res*=10,res+=ch-'0',ch=getchar();
	return k*res;
}
inline void writeInt(int x)
{
	if(x<0)
		putchar('-'),x=-x;
	if(x>9)
		writeInt(x/10);
	putchar(x%10+'0');
}
int main()
{
	n=readInt();
	for(int i=1;i<=n;i++)
	{
		num[i]=readInt();
		sum[i]=sum[i-1]+num[i];
	}
	for(int i=n+1;i<=2*n;i++)
	{
		num[i]=num[i-n];
		sum[i]=sum[i-1]+num[i];
	}
	ans=0x3f3f3f3f;
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=2*n;i++)
	{
		dp[i][i]=dp[i][i]=0;
	}
	for(int l=2;l<=2*n;l++)
	{
		for(int i=1;i<=2*n-l+1;i++)
		{
			int j=i+l-1;
			for(int k=i;k<j;k++)
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans=min(ans,dp[i][i+n-1]);
	}
	writeInt(ans);
	putchar('\n');
	ans=-1;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=2*n;i++)
	{
		dp[i][i]=dp[i][i]=0;
	}
	for(int l=2;l<=2*n;l++)
	{
		for(int i=1;i<=2*n-l+1;i++)
		{
			int j=i+l-1;
			for(int k=i;k<j;k++)
			{
				dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,dp[i][i+n-1]);
	}
	writeInt(ans);
	putchar('\n');
}
