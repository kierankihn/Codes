#include <bits/stdc++.h>
using namespace std;
const int MAXN=5000;
int n;
int ans=0;
vector<vector<int> >pos;
int dp[MAXN+5];
bool cmp(vector<int> a,vector<int> b)
{
	return a[0]<b[0];
}
int solve(int k)
{
	int res=1;
	if(dp[k]!=-1)
	{
		return dp[k];
	}
	else
	{
		for(int i=1;i<k;i++)
		{
			if(pos[k][1]>=pos[i][1])
			{
				res=max(res,solve(i)+1);
			}
		}
	}
	return dp[k]=res;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	cin>>n;
	vector<int> tmp;
	tmp.push_back(0);
	tmp.push_back(0);
	pos.push_back(tmp);
	for(int i=1;i<=n;i++)
	{
		int tmp1,tmp2;
		tmp.clear();
		cin>>tmp1>>tmp2;
		tmp.push_back(tmp1);
		tmp.push_back(tmp2);
		pos.push_back(tmp);
	}
	sort(pos.begin(),pos.end(),cmp);
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,solve(i));
	}
	cout<<ans<<endl;
	return 0;
}
