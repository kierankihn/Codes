#include <bits/stdc++.h>
#include "BigInt.h"
int BigInt::size()
{
	return this->length;
}
BigInt BigInt::clear()
{
	length=1;
	nums.clear();
	nums.push_back(0);
	return *this;
}
BigInt BigInt::operator=(std::string a)
{
	(*this).clear();
	length=a.size();
	for(int i=1;i<=length;i++)
	{
		nums.push_back(a[length-i]-'0');
	}
	return *this;
}
std::string BigInt::operator=()
{
	string ans;
	for(int i=0;i<length;i++)
	{
		ans[i]=nums[length-i-1];
	}
	return ans;
}
BigInt BigInt::operator=(int a)
{
	this->clear();
	if(a==0)
	{
		nums.push_back(0);
		length=1;
	}
	while(a)
	{
		int temp=a%BigInt::BASE;
		nums.push_back(temp);
		a=a/BigInt::BASE;
	}
	return *this;
}
BigInt BigInt::operator=(long long a)
{
	this->clear();
	if(a==0)
	{
		nums.push_back(0);
		length=1;
	}
	while(a)
	{
		int temp=a%BigInt::BASE;
		nums.push_back(temp);
		a=a/BigInt::BASE;
	}
	return *this;
}
friend std::ostream& operator<<(std::ostream& out,BigInt a)
{
	std::string tmp=a;
	out<<tmp;
	return out;
}
friend std::istream& operator>>(std::istream& in,BigInt a)
{
	std::string tmp;
	in>>tmp;
	a=tmp;
	return in;
}
bool BigInt::operator<(BigInt a) const
{
	if(a.size()!=length)
	{
		return length<a.size();
	}
	else
	{
		for(int i=length-1;i>=0;i--)
		{
			if(nums[i]!=a.nums[i])
			{
				return nums[i]<a.nums[i];
			}
		}
	}
	return false;
}

