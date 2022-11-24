#include <bits/stdc++.h>
using namespace std;
int main()
{
	int k;
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		long long p,q,n,e,d;
		cin>>n>>d>>e;
		long long delta=(e*d-n-2)*(e*d-n-2)-4*n;
		if(delta<0)
		{
			cout<<"NO\n";
			continue;
		}
		if(delta==0)
		{
			p=q=(2+n-e*d)/2;
		}
		if(delta>0)
		{
			p=(2+n-e*d-sqrt(delta))/2;
			q=(2+n-e*d+sqrt(delta))/2;
		}
		if((n-p-q+2==e*d)&&(p*q==n))
		{
			cout<<p<<" "<<q<<endl;
		}
		else
		{
//			cout<<p<<" "<<q<<endl;
			cout<<"NO\n";
		}
//		int temp=e*d;
//		for(int j=1;j<=sqrt(n);j++)
//		{
//			if(n%j==0)
//			{
//				p=j;
//				q=n/j;
//				if(n-p-q+2==temp)
//				{
//					cout<<p<<" "<<q<<endl;
//					isok=true;
//					break;
//				}
//			}
//		}
//		if(!isok)
//		{
//			cout<<"NO\n";
//		}
	}
	return 0;
}
