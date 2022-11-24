#include <bits/stdc++.h>
using namespace std;
const int MAXN=105;
int card[MAXN];
int need[MAXN];
int n,sum,ave;
int ans=0;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>card[i];
		sum+=card[i];
	}
	ave=sum/n;
	need[0]=0;
	for(int i=1;i<=n;i++)
	{
		need[i]=need[i-1]+card[i]-ave;
		if(need[i]!=0)
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
