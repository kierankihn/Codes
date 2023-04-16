#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50;
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
	ans=0x3f3f3f3f;
	memset(dp,0x3f,sizeof(dp));
	n=readLL();
	for(LL i=1;i<=n;i++)
	{
		num[i]=readLL();
	}
	for(LL i=n+1;i<=2*n;i++)
	{
		num[i]=num[i-n];
	}
	for(LL i=1;i<=2*n;i++)
	{
		dp[i][i+1]=0;
	}
	for(LL l=3;l<=2*n;l++)
	{
		for(LL i=1;i<=2*n-l+1;i++)
		{
			int j=i+l-1;
			for(LL k=i+1;k<j;k++)
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+num[i]*num[j]*num[k]);
			}
		}
	}
	ans=dp[1][n];
	writeLL(ans);
	putchar('\n');
}
