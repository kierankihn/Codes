#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
int n;
int nums[MAXN + 5];
int vis[MAXN + 5];
int ans[MAXN + 5];
string input;
void solveA()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (nums[j] < nums[i])
            {
                ans[i]++;
            }
        }
    }
    return;
}
void solveB()
{
    for (int i = n; i >= 1; i--)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (cnt == nums[i] && (!vis[j]))
            {
                ans[i] = j;
                vis[j] = 1;
                break;
            }
            if (!vis[j])
            {
                cnt++;
            }
        }
    }
}
int main()
{
    memset(vis, 0, sizeof(vis));
    cin >> n >> input;
    int prepos = 2;
    for (int i = 1; i < n; i++)
    {
        nums[i] = stoi(input.substr(prepos + 1, input.find(',', prepos + 1) - prepos - 1));
        prepos = input.find(',', prepos + 1);
    }
    nums[n] = stoi(input.substr(prepos + 1, input.size() - prepos - 1));
    if (input[0] == 'A')
    {
        solveA();
        cout << "B=";
    }
    if (input[0] == 'B')
    {
        solveB();
        cout << "A=";
    }
    cout << "(";
    for (int i = 1; i < n; i++)
    {
        cout << ans[i] << ",";
    }
    cout << ans[n] << ")\n";
    return 0;
}