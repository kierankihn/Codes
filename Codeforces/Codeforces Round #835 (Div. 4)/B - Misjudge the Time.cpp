#include <bits/stdc++.h>
using namespace std;
bool check(int h,int m)
{
	int h_,m_;
	h_=m/10+h-(h%10);
	m_=m%10+(h%10)*10;
	return (h_>=0 && h_<=23) && (m_>=0 && m_<=59);
}
void change(int& h,int& m)
{
	m++;
	if(m>59)
	{
		m=m%60;
		h++;
	}
	if(h>23)
	{
		h=h%24;
	}
}
int main()
{
	int H,M;
	cin>>H>>M;
	while(true)
	{
		if(check(H,M))
		{
			break;
		}
		change(H,M);
	}
	cout<<H<<" "<<M<<endl;
	return 0;
}
