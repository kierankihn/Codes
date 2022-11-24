#include <bits/stdc++.h>
using namespace std;
struct BigInt
{
	const static int BASEL=4;
	const static int BASEN=1e4;
	vector<int> nums;
	int length;
	struct BigInt operator=(int init)
	{
		nums.clear();
		if(init==0)
		{
			nums.push_back(0);
			length=1;
		}
		while(init)
		{
			int temp=init%BASEN;
			nums.push_back(temp);
			init=init/BASEN;
		}
		length=nums.size();
		return *this;
	}
	struct BigInt operator=(struct BigInt a)
	{
		nums.clear();
		length=a.length;
		for(int i=0;i<length;i++)
		{
			nums[i]=a.nums[i];
		}
		return *this;
	}
	struct BigInt operator+(struct BigInt a)
	{
		struct BigInt ans;
		int next=0;
		int maxl=max(a.length,length);
		for(int i=0;i<maxl;i++)
		{
			int t1,t2;
			if(i>length)
			{
				t1=0;
			}
			else
			{
				t1=nums[i];
			}
			if(i>a.length)
			{
				t2=0;
			}
			else
			{
				t2=a.nums[i];
			}
			int temp=t1+t2;
			temp+=next;
			next=temp/BASEN;
			temp=temp%BASEN;
			ans.nums.push_back(temp);
		}
		ans.length=ans.nums.size();
		return ans;
	}
	struct BigInt operator*(int a)
	{
		int next=0;
		for(int i=0;i<length;i++)
		{
			long long temp=nums[i];
			temp*=a;
			temp+=next;
			next=temp/BASEN;
			temp=temp%BASEN;
		}
		while(next)
		{
			int temp=next%BASEN;
			next=next/BASEN;
			nums.push_back(temp);
			length++;
		}
		return *this;
	}
	struct BigInt operator*(struct BigInt a)
	{
		struct BigInt ans;
		ans=0;
		for(int i=0;i<length;i++)
		{
			int temp=nums[i];
			ans=ans+(a*temp); 
		}
		return ans;
	}
};
ostream &operator<<(ostream &out,struct BigInt a)
{
	if(a.length<500)
	{
		for(int i=1;i+a.length<=125;i++)
		{
			cout<<"0000";
		}
	}
	int temp=a.nums[a.length-1];
	int t[5];
	for(int i=1;i<=4;i++)
	{
		t[i]=temp%10;
		temp=temp/10;
	}
	for(int i=1;i<=4;i++)
	{
		out<<t[i];
	}
	for(int i=a.length-2;i>=0;i--)
	{
		out<<a.nums[i];
	}
	return out;
}
struct BigInt ksm(struct BigInt a,int b)
{
	struct BigInt ans;
	if(b==0)
	{
		ans=1;
	}
	if(b%2==0)
	{
		struct BigInt temp;
		temp=ksm(a,b/2);
		ans=temp*temp;
	}
	if(b%2==1)
	{
		struct BigInt temp;
		temp=ksm(a,(b-1)/2);
		ans=temp*temp*a;
	}
	return ans;
}
int main()
{
	struct BigInt ans;
	ans=2;
//	ans=ans+ans;
	cout<<ans;
	return 0;
}
