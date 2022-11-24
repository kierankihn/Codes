#include <bits/stdc++.h>
using namespace std;
int solve(int n)
{
	int ans;
	double nlgn;
	int nlgn_t;
	nlgn=log10(n)*n;
	nlgn_t=(int)nlgn;
	ans=pow(10,nlgn-nlgn_t);
	return ans;
}
int main()
{
	int n;
	while(cin>>n)
	{
		cout<<solve(n)<<endl;
	}
	return 0;
}
