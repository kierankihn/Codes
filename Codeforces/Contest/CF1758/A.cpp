#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		string s_=s;
		reverse(s_.begin(),s_.end());
		string ans=s+s_;
		cout<<ans<<endl;
	}
	
	return 0;
}
