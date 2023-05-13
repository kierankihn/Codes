#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
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
int kmpFullStringExistTime(string text, string pattern)
{
	int lt, lp, j = 0, ans = 0;
	lt = text.size(), lp = pattern.size();
	for (int i = 0; i < lt; i++)
	{
		while (j > 0 && text[i] != pattern[j])
		{
			j = pre[j - 1];
		}
		if (text[i] == pattern[j])
		{
			j++;
		}
		if (j == lp)
		{
			ans++;
			j = 0;
		}
	}
	return ans;
}
int main()
{
	while (cin >> s && s != "#" && cin >> p)
	{
		getPreArray(p);
//		for (int i = 0; i < p.size(); i++)
//		{
//			cout << pre[i] << " ";
//		}
//		cout << endl;
		cout << kmpFullStringExistTime(s, p) << endl;
	}
	return 0;
}
