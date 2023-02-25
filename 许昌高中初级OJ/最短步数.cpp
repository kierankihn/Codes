#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
int p1, p2;		  // ����
int q1, q2;		  // ����
int dl[10005][3]; // BFS����
int idx[105][105];
int dx[12] = {2, 2, 1, 1, -1, -1, -2, -2, 2, 2, -2, -2};
int dy[12] = {1, -1, 2, -2, 2, -2, 1, -1, 2, -2, 2, -2};
void BFS()
{
	int head, tail;
	head = tail = 1;
	dl[head][1] = 1;
	dl[head][2] = 1;
	idx[1][1] = 0;
	while (head <= tail)
	{
		if ((idx[p1][p2] != -1) && (idx[q1][q2] != -1))
		{
			return;
		}
		for (int i = 0; i < 12; i++)
		{
			int newx = dl[head][1] + dx[i];
			int newy = dl[head][2] + dy[i];
			if ((newx > 0 && newx <= MAXN) && (newy > 0 && newy <= MAXN) && (idx[newx][newy] == -1))
			{
				tail++;
				dl[tail][1] = newx;
				dl[tail][2] = newy;
				idx[newx][newy] = idx[dl[head][1]][dl[head][2]] + 1;
			}
		}
		head++;
	}
}
int main()
{
	cin >> p1 >> p2;
	cin >> q1 >> q2;
	memset(dl, 0, sizeof(dl));
	memset(idx, -1, sizeof(idx));
	BFS();
	cout << idx[p1][p2] << endl;
	cout << idx[q1][q2] << endl;
	return 0;
}
