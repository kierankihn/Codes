#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		int maxn=-1,maxnt=0,maxnk=-1;
		int s[200005];
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i];
			if(s[i]==maxn)
			{
				maxnt++;
			}
			if(s[i]>maxn)
			{
				maxnk=maxn;
				maxn=s[i];
				maxnt=1;
			}
			if(s[i]<maxn && s[i]>maxnk)
			{
				maxnk=s[i];
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(s[i]==maxn && maxnt==1)
			{
				cout<<maxn-maxnk<<" ";
			}
			else
			{
				cout<<s[i]-maxn<<" ";
			}
		}
	}
	
	return 0;
}
