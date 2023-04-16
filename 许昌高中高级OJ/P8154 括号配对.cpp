#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200;
typedef long long LL;
LL n;
LL ans;
string str;
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
bool check(char a,char b)
{
	return (a=='('&&b==')')||(a=='['&&b==']');
}
int main()
{
	memset(dp,0x3f,sizeof(dp));
	cin >> str;
	n=str.size();
	for(int i=1;i<=n;i++)
	{
		dp[i][i]=1;
		dp[i][i-1]=dp[i+1][i]=0;
	}
	for(int l=2;l<=n;l++)
	{
		for(int i=1;i<=n-l+1;i++)
		{
			int j=i+l-1;
			if(check(str[i-1],str[j-1]))
			{
				dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
			}
			for(int k=i;k<j;k++)
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
			}
		}
	}
	writeLL(dp[1][n]);
	putchar('\n');
}
