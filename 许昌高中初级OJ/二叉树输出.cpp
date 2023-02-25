#include <bits/stdc++.h>
using namespace std;
const int MAXN = 785;
int nums[MAXN + 5];
queue<string> ans;
int solve(string a, string b, int isok)
{
    if (a.size() == 1)
    {
        if (isok == 1)
        {
            ans.push(a);
        }
        return 1;
    }
    string la, lb, ra, rb, tmp;
    int k = 0;
    if (b.find(a[0]) > 0)
    {
        la = a.substr(1, b.find(a[0]));
        lb = b.substr(0, b.find(a[0]));
        k += solve(la, lb, 0);
    }
    if (b.size() - b.find(a[0]) - 1 > 0)
    {
        ra = a.substr(b.find(a[0]) + 1, b.size() - b.find(a[0]) - 1);
        rb = b.substr(b.find(a[0]) + 1, b.size() - b.find(a[0]) - 1);
        k += solve(ra, rb, 0);
    }
    for (int i = 1; i <= k; i++)
    {
        tmp = tmp + a[0];
    }
    if (isok == 1)
    {
        ans.push(tmp);
    }
    if (b.find(a[0]) > 0)
    {
        solve(la, lb, 1 && isok);
    }
    if (b.size() - b.find(a[0]) - 1 > 0)
    {
        solve(ra, rb, 1 && isok);
    }
    return k;
}
int main()
{
    string a, b;
    cin >> a >> b;
    solve(a, b, 1);
    while (!ans.empty())
    {
        cout << ans.front() << endl;
        ans.pop();
    }
    return 0;
}