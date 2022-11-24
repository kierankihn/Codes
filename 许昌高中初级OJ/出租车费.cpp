#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0)
		{
			break;
		}
		int rest=n%8;
		int k=n/8;
		long long ans=k*18;
		int ws=0;
		if(rest<=4 && rest)
		{
			if(k==0)
			{
				ans+=10;
			}
			else
			{
				ans+=rest*2.4;
				ws=rest*24;
				ws=ws%10;
			}
		}
		if(rest<8 && rest>4)
		{
			ans+=10+(rest-4)*2;
		}
//		long long tmp=ans*10;
//		if(tmp%10)
//		{
//			printf("%.1llf",ans);
//		}
//		else
//		{
//			printf("%d",(int)ans);
//		}
		cout<<ans;
		if(ws!=0)
		{
			cout<<"."<<ws;
		}
		cout<<endl;
	}
	
	return 0;
}
