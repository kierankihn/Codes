#include <bits/stdc++.h>
using namespace std;
const int MAXN=1000;
int search(int* A,int l,int r,int k)
{
	int mid=(l+r)/2;
	while(l<=r)
	{
		mid=(l+r)/2; 
		if(A[mid]==k)
		{
			return mid;
		}
		if(A[mid]<k)
		{
			l=mid+1;
		}
		if(A[mid]>k)
		{
			r=mid-1;
		}
	}
	return -1;
}
int main()
{
	int n,k;
	int nums[MAXN+5];
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>nums[i];
	}
	cout<<search(nums,1,n,k)<<endl;
	return 0;
}
