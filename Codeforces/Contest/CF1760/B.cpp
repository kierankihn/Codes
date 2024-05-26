#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[3];
	int t;
	cin>>t;
	while(t--)
	{
		int maxn=-1;
		int l;
		cin>>l;
		for(int i=1;i<=l;i++)
		{
			char s;
			cin>>s;
			if((s-'a'+1)>maxn)
			{
				maxn=s-'a'+1;
			}
		}
		cout<<maxn<<endl;
	}
	return 0;
}
