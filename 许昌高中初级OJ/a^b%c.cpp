#include <iostream>
using namespace std;
long long ksm(long long a,long long b,long long c)
{
	long long ans=1;
	while(b)
	{
		if(b&1)
		{
			ans=ans*a%c;
		}
		a=a*a%c;
		b=b>>1;
	}
	return ans;
}
int main()
{
	long long a,b,c;
	cin>>a>>b>>c;
	cout<<ksm(a,b,c);
	return 0;
}
