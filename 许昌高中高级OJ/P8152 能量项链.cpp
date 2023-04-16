#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200;
typedef __int128 LL;
LL n;
LL ans;
LL num[MAXN*2+5];
LL dp[MAXN*2+5][MAXN*2+5];
inline LL readLL()
{
	LL res=0,k=1;
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
inline void writeLL(LL x)
{
	if(x<0)
		putchar('-'),x=-x;
	if(x>9)
		writeLL(x/10);
	putchar(x%10+'0');
}
int main()
{
	n=readLL();
	for(LL i=1;i<=n;i++)
	{
		num[i]=readLL();
	}
	for(LL i=n+1;i<=2*n;i++)
	{
		num[i]=num[i-n];
	}
	ans=-1;
	memset(dp,0,sizeof(dp));
	for(LL i=1;i<=2*n;i++)
	{
		dp[i][i]=dp[i][i]=0;
	}
	for(LL l=2;l<=2*n;l++)
	{
		for(LL i=1;i<=2*n-l+1;i++)
		{
			int j=i+l-1;
			for(LL k=i;k<j;k++)
			{
				dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+num[i]*num[k+1]*num[j+1]);
			}
		}
	}
	for(LL i=1;i<=n;i++)
	{
		ans=max(ans,dp[i][i+n-1]);
	}
	writeLL(ans);
	putchar('\n');
}
