#include <bits/stdc++.h>
using namespace std;
bool ask(char a,char b)
{
	cout<<"? "<<a<<" "<<b<<endl;
	char res;
	cin>>res;
	return res=='<'?true:false;
}
int search(string t,char a)
{
	int r,l,mid;
	l=0;
	r=t.size()-1;
	while(l<=r)
	{
		mid=(l+r)/2;
		char b=t[mid];
		if(ask(a,b))
		{
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	return l;
}
int main()
{
	string ans="A";
	int n,q;
	cin>>n>>q;
	for(int i=1;i<n;i++)
	{
		ans.insert(search(ans,'A'+i),1,'A'+i);
	}
	cout<<"! "<<ans<<endl;
	return 0;
}
