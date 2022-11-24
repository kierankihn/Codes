#include <bits/stdc++.h>
using namespace std;
const int MAXN=1<<8;
void solve(int m,int ans[MAXN+5][MAXN+5])
{
	int n=1<<m;
	if(m==0)
	{
		ans[1][1]=1;
		return;
	}
	else
	{
		solve(m-1,ans);
		for(int i=n/2+1;i<=n;i++)  //Ìî³ä×óÏÂ½Ç 
		{
			for(int j=1;j<=n/2;j++)
			{
				ans[i][j]=ans[i-n/2][j]+n/2;
			}
		}
		for(int i=1;i<=n/2;i++)  //Ìî³äÓÒÉÏ½Ç 
		{
			for(int j=n/2+1;j<=n;j++)
			{
				ans[i][j]=ans[i+n/2][j-n/2];
			}
		}
		for(int i=n/2+1;i<=n;i++)  //Ìî³äÓÒÏÂ½Ç 
		{
			for(int j=n/2+1;j<=n;j++)
			{
				ans[i][j]=ans[i-n/2][j-n/2];
			}
		}
	}
}
int main()
{
	int m;
	int ans[MAXN+5][MAXN+5];
	cin>>m;
	solve(m,ans);
	for(int i=1;i<=1<<m;i++)
	{
		for(int j=1;j<=1<<m;j++)
		{
			cout<<left<<setw(5)<<ans[i][j];
		}
		cout<<endl;
	}
	return 0;
}
