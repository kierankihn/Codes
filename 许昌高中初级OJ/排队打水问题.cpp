#include <bits/stdc++.h>
using namespace std;
const int MAXN=105;
int r; //水龙头数
int n;//人数
int a[MAXN],b[MAXN];//a保存每个人打水用时,b保存每个水龙头前边等待总用时
int ans=0; 
int main()
{
	cin>>n>>r;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	memset(b,0,sizeof(b));
	sort(a,a+n);
	int temp=1;
	for(int i=1;i<=n;i++)
	{
		b[temp]+=a[i];
		ans+=b[temp];
		temp++;
		if(temp==r+1)
		{
			temp=1;
		}
	}
	cout<<ans;
	return 0;
}
