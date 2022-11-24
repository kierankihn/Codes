#include <bits/stdc++.h>
using namespace std;
const int MAXN=1000;
void quicksort(int* a,int l,int r)
{
	if(l>=r)
	{
		return;
	}
	int i=l;
	int j=r;
	int m=(l+r)/2;
	while(i<j)
	{
		while(i<j && a[j]>=a[m])
		{
			j--;
		}
		while(i<j && a[i]<=m)
		{
			i++;
		}
		if(j>i)
		{
			swap(a[i],a[j]);
		}
	}
	swap(a[m],a[i]);
	m=i; 
	quicksort(a,l,m-1);
	quicksort(a,m+1,r);
}
int main()
{
	int n;
	int a[MAXN+5];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	quicksort(a,1,n);
//	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
