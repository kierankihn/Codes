#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
int n;
long long cost[MAXN + 5];
long long ans = -1;
long long p;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> cost[i];
	}
	sort(cost + 1, cost + n + 1);
	for (int i = 1; i <= n; i++)
	{
		if ((n - i + 1) * cost[i] > ans)
		{
			ans = cost[i] * (n - i + 1);
			p = cost[i];
		}
	}
	cout << ans << " " << p << endl;

	return 0;
}