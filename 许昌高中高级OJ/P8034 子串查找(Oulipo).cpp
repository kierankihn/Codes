#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
typedef unsigned long long ull;
const ull P = 857857857;
string a, b;
ull ans;
ull Pn[MAXN];
ull ha[MAXN];
ull hb;
int main()
{
	cin >> a >> b;
	Pn[0] = 1;
	for (ull i = 1; i <= MAXN - 5; i++)
	{
		Pn[i] = Pn[i - 1] * P;
	}
	ha[0] = a[0];
	for (ull i = 1; i < a.size(); i++)
	{
		ha[i] = ha[i - 1] * P + a[i];
	}
	for (ull i = 0; i < b.size(); i++)
	{
		hb = hb * P + b[i];
	}
	for (ull i = 0; i + b.size() <= a.size(); i++)
	{
		int l = i, r = i + b.size() - 1;
		if (ha[r] - ha[l - 1] * Pn[r - l + 1] == hb)
		{
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
