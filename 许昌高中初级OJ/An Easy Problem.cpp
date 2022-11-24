#include <bits/stdc++.h>
using namespace std;
int calc(int a)
{
	int ans=0;
	while(a)
	{
		ans++;
		a&=a-1;
	}
	return ans;
}
int main()
{
	int n;
	while(cin>>n && n)
	{
		int num=calc(n);
		int res=n;
		while(res++)
		{
			if(num==calc(res))
			{
				cout<<res<<endl;
				break;
			}
		}
	}
	return 0;
}
