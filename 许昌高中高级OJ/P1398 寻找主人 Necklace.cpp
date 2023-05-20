#include <bits/stdc++.h>
using namespace std;
string getMinIsomorphicString(string x)
{
	int i = 0, j = 0, k = 0, l = x.size();
	x = x + x;
	while (i < l && j < l)
	{
		if (i == j)
		{
			j++;
		}
		k = 0;
		while (k < l && x[i + k] == x[j + k])
		{
			k++;
		}
		if (k + 1 == l)
		{
			break;
		}
		if (x[i + k] > x[j + k])
		{
			i = i + k + 1;
			continue;
		}
		else
		{
			j = j + k + 1;
			continue;
		}
	}
	i = min(i, j);
	return x.substr(i, l);
}
int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	if (getMinIsomorphicString(str1) == getMinIsomorphicString(str2))
	{
		cout << "Yes\n";
		cout << getMinIsomorphicString(str1) << endl;
	}
	else
	{
		cout << "No\n";
	}
	return 0;
}
