#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 5;
int n;
char a[MAXN][MAXN];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j == 1 && i != n)
			{
				cout << a[i + 1][j];
				continue;
			}
			if (j == n && i != 1)
			{
				cout << a[i - 1][j];
				continue;
			}
			if (i == 1)
			{
				cout << a[i][j - 1];
				continue;
			}
			if (i == n)
			{
				cout << a[i][j + 1];
				continue;
			}
			cout << a[i][j];
		}
		cout << endl;
	}
	return 0;
}