#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5;
bool vis[MAXN+5];
bool isit[MAXN+5];
void solve(int n,int k,string pos)
{
	memset(vis,0,sizeof(vis));
	memset(isit,0,sizeof(isit));
	int ans=0;
	string p=pos;
	int l=pos.size();
	for(int i=0;i<l;i++)
	{
		if(!vis[i])
		{
			int tmp=min(i+k,l-1);
			while(isit[tmp])
			{
				tmp--;
			}
			isit[tmp]=true;
			p[tmp]=pos[i];
			for(int j=max(tmp-k,0);j<=min(tmp+k,l-1);j++)
			{
				if(vis[j]==0 && pos[i]==pos[j])
				{
					vis[j]=1;
					if(!isit[j])
					{
						p[j]='.';
					}
				}
			}
		}
	}
	for(int i=0;i<l;i++)
	{
		if(p[i]!='.')
		{
			ans++;
		}
	}
	cout<<ans<<endl<<p<<endl;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,k;
		string pos;
		cin>>n>>k;
		cin>>pos;
		solve(n,k,pos);
	}
	return 0;
}
