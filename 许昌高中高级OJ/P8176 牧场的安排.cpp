#include <bits/stdc++.h>
using namespace std;
typedef long long T;
const int MAXN=12+2;
const int MOD=1e8;
int n,m;
vector<pair<int,int>> sit;
int status[MAXN];
T ans;
T dp[MAXN][1<<MAXN][MAXN*MAXN];
int getOneNumber(int x)
{
	int res=0;
	while(x)
	{
		if(x&1)
		{
			res++;
		}
		x=x>>1;
	}
	return res;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int tmp;
			cin>>tmp;
			if(tmp)
			{
				tmp=0;
			}
			else
			{
				tmp=1;
			}
			status[i]=status[i]|(tmp<<(j-1));
		}
	}
	for(int i=0;i<(1<<m);i++)
	{
		if(i&(i<<1))
		{
			continue;
		}
		sit.push_back(pair<int,int>(i,getOneNumber(i)));
	}
	int t=sit.size();
	dp[0][0][0]=1;
	for(int l=1;l<=n;l++)
	{
		for(int i=0;i<t;i++)
		{
			for(int j=0;j<t;j++)
			{
				if(sit[i].first&sit[j].first)
				{
					continue;
				}
				if((sit[i].first&status[l])||(sit[j].first&status[l-1]))
				{
					continue;
				}
				for(int k=0;k<=n*m;k++)
				{
					if(k-sit[i].second>=0)
					{
						dp[l][sit[i].first][k]+=dp[l-1][sit[j].first][k-sit[i].second];
					}
				}
			}
		}
	}
	for(int i=0;i<=n*m;i++)
	{
		for(int j=0;j<t;j++)
		{
			ans+=dp[n][sit[j].first][i];
			ans=ans%MOD;
		}
	}
	cout << ans << endl;
	return 0;
} 
