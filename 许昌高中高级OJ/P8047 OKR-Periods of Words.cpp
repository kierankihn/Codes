#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int l;
long long ans = 0;
string p;
int pre[MAXN];
void getPreArray(string x)
{
	int l = x.size();
	pre[0] = 0;
	for (int i = 1; i < l; i++)
	{
		int j = pre[i - 1];
		while (j > 0 && x[i] != x[j])
		{
			j = pre[j - 1];
		}
		if (x[i] == x[j])
		{
			j++;
		}
		pre[i] = j;
	}
}
int main()
{
	cin >> l;
	cin >> p;
	getPreArray(p);
	for (int i = 1; i < l; i++)
	{
		int j = i;
		while (pre[j])
		{
			j = pre[j] - 1;
		}
		if (pre[i])
		{
			pre[i] = j + 1;
		}
		if (i != j)
		{
			ans += i - j;
		}
	}
	cout << ans << endl; 
	return 0;
}
