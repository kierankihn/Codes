#include <bits/stdc++.h>
using namespace std;
const int MAXN=105;
int r; //ˮ��ͷ��
int n;//����
int a[MAXN],b[MAXN];//a����ÿ���˴�ˮ��ʱ,b����ÿ��ˮ��ͷǰ�ߵȴ�����ʱ
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
