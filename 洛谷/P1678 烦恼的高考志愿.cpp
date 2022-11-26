#include <bits/stdc++.h>
#define cin input
#define cout output
using namespace std;
int search(int* A,int m,int k)
{
	int l=1,r=m;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(A[mid]<=k)
		{
			l=mid+1;
		}
		else
		{
			r=mid;
		}
	}
	return l;
}
int main()
{
	ifstream input("P1678_1.in");
	ofstream output("P1678_1.ans");
	int m,n;
	long long ans=0;
	int school[100005],stu[100005];
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		cin>>school[i];
	}
	school[0]=school[m+1]=1e8;
	sort(school+1,school+m+1);
	for(int i=1;i<=n;i++)
	{
		cin>>stu[i];
		int p=search(school,m,stu[i]);
		ans+=min(abs(school[p]-stu[i]),abs(stu[i]-school[p-1]));
	}
	cout<<ans<<endl;
	return 0;
}
