#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N,K;
	int MAXN=105;
	int nums[MAXN];
	cin>>N>>K;
	for(int i=1;i<=N;i++)
	{
		cin>>nums[i];
	}
	if(K<N)
	{
		for(int i=K+1;i<=N;i++)
		{
			cout<<nums[i]<<" ";
		}
		for(int i=1;i<=K;i++)
		{
			cout<<0<<" ";
		}
	}
	else
	{
		for(int i=1;i<=N;i++)
		{
			cout<<0<<" ";
		}
	}
	cout<<endl;
	
	return 0;
}
