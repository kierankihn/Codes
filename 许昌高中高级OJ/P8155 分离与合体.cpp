#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300;
typedef __int128 LL;
LL n;
LL len;
LL flag;
LL num[MAXN+5];
LL dp[MAXN+5][MAXN+5][2];
LL vis[MAXN+5];
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
void bfs(LL l,LL r,LL step)
{
	if(l>=r || l==-1 || r==-1)
	{
		return;
	}
	if(step==len)
	{
		flag=1;
		writeLL(dp[l][r][2]);
		putchar(' ');
		return;
	}
	bfs(l,dp[l][r][2],step+1);
	bfs(dp[l][r][2]+1,r,step+1);
}
void printans()
{
	flag=1;
	len=1;
	while(flag)
	{
		flag=0;
		bfs(1,n,1);
		len++;
	}
}
LL solve(LL l,LL r)
{
	if(l==r)
	{
		return dp[l][r][1]=0;
	}
	if(dp[l][r][1]!=-1)
	{
		return dp[l][r][1];
	}
	for(LL k=l;k<r;k++)
	{
		if(vis[k]==0)
		{
			vis[k]=1;
			if((dp[l][r][1]<solve(l,k)+solve(k+1,r)+(num[l]+num[r])*num[k]))
			{
				dp[l][r][1]=solve(l,k)+solve(k+1,r)+(num[l]+num[r])*num[k];
				dp[l][r][2]=k;
			}
		}
		vis[k]=0;
	}
	return dp[l][r][1];
}
int main()
{
	memset(dp,-1,sizeof(dp));
	n=readLL();
	for(LL i=1;i<=n;i++)
	{
		num[i]=readLL();
	}
	for(LL i=1;i<=n;i++)
	{
		dp[i][i][1]=0;
	}
	writeLL(solve(1,n));
	putchar('\n');
	printans();
	putchar('\n');
}
