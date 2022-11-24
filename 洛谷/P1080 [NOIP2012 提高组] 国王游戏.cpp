#include <bits/stdc++.h>
using namespace std;
bool cmp(int a[3],int b[3])
{
	return a[2]>b[2];
}
int main()
{
	int nums[10005][3];
	int ans=-1;
	int n;
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		cin>>nums[i][1]>>nums[i][2];
	}
	sort(nums+1,nums+n+1,cmp);
	for(int i=1;i<=)
	
	return 0;
}
