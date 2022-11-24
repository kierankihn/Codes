#include <bits/stdc++.h>
using namespace std;
const int MAXN=1000;
int h[MAXN+5];
int dd[MAXN+5];
int main()
{
	int ans=1;
	int num=0;
	cin>>dd[1];
	h[1]=dd[1];
	int i=2;
	while(cin>>dd[i])
	{
		num++;
		sort(h+1,h+ans+1);
		int temp=1;
		while(dd[i]>h[temp])
		{
			temp++;
			if(temp>ans)
			{
				ans++;
				h[ans]=dd[i];
				break;
			}
		}
		if(temp<=ans)
		{
			h[temp]=dd[i];
		}
	}
//	int res=1,a=dd[1];
//	for(int j=2;j<=num;j++)
//	{
//		if(dd[j]<a)
//		{
//			a=dd[j];
//			res++;
//		}
//	}
	cout<<0<<" "<<ans;
}
