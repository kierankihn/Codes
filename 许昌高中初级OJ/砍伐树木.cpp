#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6;
int n;
long long m;
int tree[MAXN + 5];
long long sum(int k)
{
	long long res = 0;
	for (int i = 1; i <= n; i++)
	{
		if (tree[i] > k)
		{
			res += tree[i] - k;
		}
	}
	return res;
}
int main()
{
	cin >> n >> m;
	int maxt = -1;
	for (int i = 1; i <= n; i++)
	{
		cin >> tree[i];
		if (tree[i] > maxt)
		{
			maxt = tree[i];
		}
	}
	int l = 0, r = maxt;
	int mid;
	int ans;
	while (l <= r)
	{
		mid = (l + r) / 2;
		long long s = sum(mid);
		if (s < m)
		{
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
			ans = mid;
		}
	}
	cout << ans << endl;
	return 0;
}
