#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[3];
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>a[0]>>a[1]>>a[2];
		sort(a,a+3);
		cout<<a[1]<<endl;
	}
	return 0;
}
