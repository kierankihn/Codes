#include <bits/stdc++.h>
using namespace std;
const int MAXM = 1000 + 5;
int n;
int cnt = 0;
int s[MAXM];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int tmp;
		cin >> tmp;
		if (!s[tmp])
		{
			cnt++;
			s[tmp] = 1;
		}
	}
	cout << cnt << endl;
	for (int i = 0; i < MAXM; i++)
	{
		if (s[i])
		{
			cout << i << " ";
		}
	}
	cout << endl;
	return 0;
}
