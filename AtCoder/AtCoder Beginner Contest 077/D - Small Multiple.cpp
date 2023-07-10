#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int k;
int a[MAXN];
queue<int> q;
int main()
{
    memset(a, 0x3f, sizeof(a));
    cin >> k;
    for (int i = 1; i < 10; i++)
    {
        q.push(i % k);
        a[i % k] = min(a[i % k], i);
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 10; i++)
        {
            if (a[(u * 10 + i) % k] <= a[u] + i)
            {
                continue;
            }
            q.push((u * 10 + i) % k);
            a[(u * 10 + i) % k] = a[u] + i;
        }
    }
    cout << a[0] << endl;
    return 0;
}