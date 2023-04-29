#include <bits/stdc++.h>
using namespace std;
typedef long long T;
const int MAXN=100+5;
const int MAXM=10+1;
const int MOD=1e8;
int n,m;
vector<pair<int,int>> sit;
int status[MAXN];
T ans;
T dp[2][1<<MAXM][1<<MAXM];
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
		string tmp;
		cin>>tmp;
		for(int j=1;j<=m;j++)
		{
			int hzi;
			if(tmp[j-1]=='H')
			{
				hzi=1;
			}
			else
			{
				hzi=0;
			}
			status[i]=status[i]|(hzi<<(m-j));
		}
	}
	for(int i=0;i<(1<<m);i++)
	{
		if(i&(i<<1))
		{
			continue;
		}
		if(i&(i<<2))
		{
			continue;
		}
		sit.push_back(pair<int,int>(i,getOneNumber(i)));
	}
	int t=sit.size();
	for(int l=1;l<=n;l++)
	{
		for(int i=0;i<t;i++)
		{
			for(int j=0;j<t;j++)
			{
				for(int k=0;k<t;k++)
				{
					if(sit[i].first&sit[j].first || sit[i].first&sit[k].first || sit[j].first&sit[k].first)
					{
						continue;
					}
					if((sit[i].first&status[l])||(sit[j].first&status[l-1])||(sit[k].first&status[l-2]))
					{
						continue;
					}
					dp[1][sit[i].first][sit[j].first]=max(dp[1][sit[i].first][sit[j].first],dp[0][sit[j].first][sit[k].first]+sit[i].second);
				}
			}
		}
		for(int i=0;i<t;i++)
		{
			for(int j=0;j<t;j++)
			{
				dp[0][sit[i].first][sit[j].first]=dp[1][sit[i].first][sit[j].first];
			}
		}
	}
	for(int i=0;i<t;i++)
	{
		for(int j=0;j<t;j++)
		{
			ans=max(ans,dp[1][sit[i].first][sit[j].first]);
		}
	}
	cout << ans << endl;
	return 0;
} 
