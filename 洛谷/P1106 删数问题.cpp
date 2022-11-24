#include <bits/stdc++.h>
using namespace std;
int k;
string n;
int main()
{
	cin>>n>>k;
	int l=n.size();
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<l;j++)
		{
			if((j==l)||(n[j]>n[j+1]))
			{
				n.erase(n.begin()+j);
				break;
			}
		}
	}
	l=n.size();
	while(n[0]=='0')
	{
		n.erase(n.begin());
	}
	if(n.size()==0)
	{
		n="0";
	}
	cout<<n;
	return 0;
}
