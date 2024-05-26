#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	int ans=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='v')
		{
			ans++;
		}
		else
		{
			ans+=2;
		}
	}
	cout<<ans<<endl;
	return 0;
}
