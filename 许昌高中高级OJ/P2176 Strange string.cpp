#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e7 + 5;
int n;
int ans;
unsigned char str[MAXN];
void strCopy()
{
	for (int i = 0; i < n; i++)
	{
		str[i + n] = str[i];
	}
}
int getMinIsomorphicString()
{
	int i = 0, j = 0, k = 0, l = n;
	strCopy();
	while (i < l && j < l)
	{
		if (i == j)
		{
			j++;
		}
		k = 0;
		while (k < l && str[i + k] == str[j + k])
		{
			k++;
		}
		if (k + 1 == l)
		{
			break;
		}
		if (str[i + k] > str[j + k])
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
	return i;
}
int main()
{
	cin >> n >> str;
	ans = getMinIsomorphicString();
	for (int i = ans; i < ans + n; i++)
	{
		putchar(str[i]);
	}
	return 0;
}
