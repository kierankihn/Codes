#include <bits/stdc++.h>
using namespace std;
const int MAXN=50000;
int check(int dist,int m,int n,int stone[MAXN+5])
{
	int k=0;
	int cnt=0;
	for(int i=1;i<=n+1;i++)
	{
		if((stone[i]-stone[k])<dist)
		{
			cnt++;
		}
		else
		{
			k=i;
		}
	}
	return cnt<=m;
}
int main()
{
	int l,n,m;
	int stone[MAXN+5];
	cin>>l>>n>>m;
	stone[0]=0;
	stone[n+1]=l;
	for(int i=1;i<=n;i++)
	{
		cin>>stone[i];
	}
	int left=0,right=l;
	while(left<=right)
	{
		int mid=(left+right)/2;
		if(check(mid,m,n,stone))
		{
			left=mid+1;
		}
		else
		{
			right=mid-1;
		}
	}
	cout<<left-1<<endl;
	return 0;
}
