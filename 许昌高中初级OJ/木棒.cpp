#include <bits/stdc++.h>
using namespace std;
void search(vector<vector<int> >& stick,vector<vector<bool> >& mp,vector<bool>& vis,int x,int y)
{
	int n=stick.size();
	while(true)
	{
		vis[x]=true;
		int i;
		for(i=0;i<n;i++)
		{
			if(mp[i][x]==1 && (!vis[i]))
			{
				x=i;
				break;
			}
		}
		if(i==n)
		{
			break;
		}
	}
	while(true)
	{
		vis[y]=true;
		int i;
		for(i=0;i<n;i++)
		{
			if(mp[y][i]==1 && (!vis[i]))
			{
				y=i;
				break;
			}
		}
		if(i==n)
		{
			break;
		}
	}
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		vector<vector<int> > stick;
		vector<vector<bool> > mp;
		vector<bool> vis;
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			vector<int> tmp;
			tmp.resize(2);
			cin>>tmp[0]>>tmp[1];
			stick.push_back(tmp);
			vector<bool> tmp_;
			tmp_.resize(n);
			mp.push_back(tmp_);
			vis.push_back(0); 
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if((stick[j][0]<=stick[i][0])&&(stick[j][1]<=stick[i][1]))
				{
					mp[i][j]=1;
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(mp[i][j] && ((!vis[i])||(!vis[j])))
				{
					search(stick,mp,vis,i,j);
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
