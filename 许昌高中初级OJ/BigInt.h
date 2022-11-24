#ifndef BIG_INT_H_
#define BIG_INT_H_
#include <bits/stdc++.h>
class BigInt
{
 private:
	std::vector<int> nums;
	int length;
 public:
 	const static int BASE=1e4;
	friend std::ostream& operator<<(std::ostream& out,BigInt a);
 	friend std::istream& operator>>(std::istream& in,BigInt a);
 	BigInt clear();
 	BigInt operator=(std::string a);
 	std::string operator=(BigInt a);
 	BigInt operator=(int a);
 	BigInt operator=(long long a);
 	bool operator<(BigInt a) const;
 	bool operator>(BigInt a) const;
 	bool operator==(BigInt a) const;
 	bool operator>=(BigInt a) const;
 	bool operator<=(BigInt a) const;
 	BigInt operator+(BigInt a);
 	BigInt operator-(BigInt a);
 	BigInt operator*(BigInt a);
 	BigInt operator/(BigInt a);
 	BigInt operator%(BigInt a);
 	int size();
};
#endif //BIG_INT_H_
