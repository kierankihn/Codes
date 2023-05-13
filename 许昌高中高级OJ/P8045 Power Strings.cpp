#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
string p, s;
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
	while (cin >> s && s != ".")
	{
		getPreArray(s);
		int l = s.size();
		if (l % (l - pre[l - 1]) == 0)
		{
			cout << l / (l - pre[l - 1]) << endl;
		}
		else
		{
			cout << 1 << endl;
		}
	}
	return 0;
}
