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
string kmpDeleteAllPatternInText(string text, string pattern)
{
	unsigned long long lp, j = 0;
	lp = pattern.size();
	for (unsigned long long i = 0; i < text.size(); i++)
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
			text = text.substr(0, i - j + 1) + text.substr(i + 1, text.size() - i - 1);
			i = (i > 2 * j + 1) ? i - 2 * j + 1 : 0;
			j = 0;
		}
	}
	return text;
}
int main()
{
	cin >> s >> p;
	getPreArray(p);
	cout << kmpDeleteAllPatternInText(s, p) << endl;
	return 0;
}
