#include <bits/stdc++.h>
using namespace std;
int n;
const int MAXN = 100;
int nums[MAXN + 5];
int main()
{
    while (cin >> n && n)
    {
        stack<int> a;
        int k = 1;
        for (int i = 1; i <= n; i++)
        {
            cin >> nums[i];
        }
        int i;
        for (i = 1; i <= n; i++)
        {
            if ((!a.empty())&&a.top()>n)
            {
                break;
            }
            if ((!a.empty()) && a.top() == nums[i])
            {
                a.pop();
            }
            else
            {
                a.push(k++);
                i--;
            }
        }
        if (a.empty())
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}