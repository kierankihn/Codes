#include <bits/stdc++.h>
using namespace std;
const int MAXN=100;
int chess[MAXN*2+5];//1°× 2ºÚ 
int n;
int space;
int step=0;
void print()
{
//	cout<<"step "<<step<<":";
//	step++;
	for(int i=1;i<=n*2+2;i++)
	{
		switch(chess[i])
		{
			case 0:
				cout<<"-";
				break;
			case 1:
				cout<<"o";
				break;
			case 2:
				cout<<"*";
				break; 
		}
	}
	cout<<endl;
	return;
}
void init()
{
	for(int i=1;i<=n;i++)
	{
		chess[i]=1;
	}
	for(int i=n+1;i<=n*2;i++)
	{
		chess[i]=2;
	}
	chess[n*2+1]=0;
	chess[n*2+2]=0;
	space=n*2+1;
	print();
}
void move(int p)
{
	chess[space]=chess[p];
	chess[space+1]=chess[p+1];
	chess[p]=0;
	chess[p+1]=0;
	space=p;
	print();
	return;
}
void solve(int n)
{
	if(n>4)
	{
		move(n);
		move(n*2-1);
		solve(n-1);
	}
	else
	{
		move(4);
		move(8);
		move(2);
		move(7);
		move(1);
	}
	return;
}
int main()
{
	cin>>n;
	init();
	solve(n);
	return 0;
}
