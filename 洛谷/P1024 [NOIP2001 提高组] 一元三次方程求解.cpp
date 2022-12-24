#include <bits/stdc++.h>
using namespace std;
double a, b, c, d;
double f(double x)
{
	return a * x * x * x + b * x * x + c * x + d;
}
double solve(double l, double r)
{
	double mid = (l + r) / 2;
	if (r - l <= 0.001)
	{
		return mid;
	}
	if (f(l) == 0)
	{
		return l;
	}
	if (f(r) == 0)
	{
		return r;
	}
	if (f(l) * f(mid) < 0)
	{
		return solve(l, mid);
	}
	else
	{
		return solve(mid, r);
	}
}
int main()
{
	cin >> a >> b >> c >> d;
	for (int i = -100; i <= 100; i++)
	{
		if (f(i) * f(i + 1) > 0)
		{
			continue;
		}
		if (f(i + 1) == 0)
		{
			cout << fixed << setprecision(2) << (double)i + 1 << " ";
			i++;
			continue;
		}
		cout << fixed << setprecision(2) << solve(i, i + 1) << " ";
	}
	cout << endl;
	return 0;
}
