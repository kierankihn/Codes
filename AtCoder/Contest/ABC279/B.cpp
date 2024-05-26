#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s,t;
	int ans=0;
	cin>>s>>t;
	ans=s.find(t);
	if(ans==string::npos)
	{
		cout<<"No\n";
	}
	else
	{
		cout<<"Yes\n";
	}
	return 0;
}
