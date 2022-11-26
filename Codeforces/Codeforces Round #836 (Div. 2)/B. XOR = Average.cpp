#include <bits/stdc++.h>
using namespace std;
void solve(int n)
{
	if(n==2)
	{
		cout<<"2 6 ";
		return;
	}
	if(n%2==1)
	{
		for(int i=1;i<=n;i++)
		{
			cout<<"4 ";
		}
	}
	else
	{
		solve((n-2)/2);
		solve((n-2)/2);
		cout<<"2 6 ";
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		solve(n);
		cout<<endl;
	}
	
	return 0;
}
