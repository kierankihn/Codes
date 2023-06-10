#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const int MAXM = 26;
int trie[MAXN][MAXM];
int fail[MAXN];
int e[MAXN];
int n, T;
string str, text;
int tot = 0;
void init()
{
	str = text = "";
	memset(trie, 0, sizeof(trie));
	memset(e, 0, sizeof(e));
	memset(fail, 0, sizeof(fail));
	n = 0;
}
void insertWord(string s)
{
	int u = 0;
	for (unsigned int i = 0; i < s.size(); i++)
	{
		if (!trie[u][s[i] - 'a'])
		{
			trie[u][s[i] - 'a'] = ++tot;
		}
		u = trie[u][s[i] - 'a'];
	}
	e[u]++;
}
void getFail()
{
	queue<int> q;
	for (int i = 0; i < MAXM; i++)
	{
		if (trie[0][i])
		{
			q.push(trie[0][i]);
		}
	}
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = 0; i < MAXM; i++)
		{
			if (trie[u][i])
			{
				fail[trie[u][i]] = trie[fail[u]][i];
				q.push(trie[u][i]);
			}
			else
			{
				trie[u][i] = trie[fail[u]][i];
			}
		}
	}
}
int query(string s)
{
	int u = 0, res = 0;
	for (unsigned int i = 0; i < s.size(); i++)
	{
		u = trie[u][s[i] - 'a'];
		for (int j = u; j && e[j] != -1; j = fail[j])
		{
			res += e[j];
			e[j] = -1;
		}
	}
	return res;
}
int main()
{
	cin >> T;
	while (T--)
	{
		init();
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> str;
			insertWord(str);
		}
		getFail();
		cin >> text;
		cout << query(text) << endl;
	}
	return 0;
}
