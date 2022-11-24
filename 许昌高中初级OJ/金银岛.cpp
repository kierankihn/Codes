#include <bits/stdc++.h>
using namespace std;
const int MAXN=105;
int k;
struct goods
{
	int p;
	int w;
	double c;//µ¥¼Û
	bool operator<(struct goods b) const
	{
		return c<b.c;
	}
};
bool cmp(struct goods a,struct goods b)
{
	return a.c>b.c;
}
int main()
{
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		int MAXW,s;
		double ans=0;
		struct goods t[MAXN];
		cin>>MAXW>>s;
		for(int j=1;j<=s;j++)
		{
			cin>>t[j].w>>t[j].p;
			t[j].c=((double)t[j].p)/t[j].w;
		}
		sort(t+1,t+s+1,cmp);
		int temp=1;
		while(MAXW!=0) 
		{
			if(temp==s+1)
			{
				break;
			}
			if(MAXW>=t[temp].w)
			{
				MAXW=MAXW-t[temp].w;
				ans+=t[temp].p;
				temp++;
				continue;
			}
			else
			{
				ans+=t[temp].c*MAXW;
				MAXW=0;
			}
		}
		cout<<fixed<<setprecision(2)<<ans<<endl;
//		cout<<endl<<i<<endl<<endl;
//		for(int j=1;j<=s;j++)
//		{
//			cout<<t[j].w<<" "<<t[j].p<<" "<<t[j].c<<endl;
//		}
	}
	return 0;
}
