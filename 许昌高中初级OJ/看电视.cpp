#include <bits/stdc++.h>
using namespace std;
bool cmp(vector<int> a,vector<int> b)
{
	return a[1]<b[1];
}
int main()
{
	int n; 
	while(cin>>n)
	{
		if(!n)
		{
			break;
		}
		vector<vector<int> > t;
		vector<bool> vis;
		vis.resize(n);
		int ans=0;
		for(int i=0;i<n;i++)
		{
			vector<int> tmp;
			tmp.resize(2);
			cin>>tmp[0]>>tmp[1];
			t.push_back(tmp);
			vis[i]=false;
		}
		sort(t.begin(),t.end(),cmp);
		for(int i=0;i<n;i++)
		{
			if(!vis[i])
			{
				vis[i]=true;
				ans++;
				for(int j=i;j<n;j++)
				{
					if(t[j][0]<t[i][1])
					{
						vis[j]=true;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
