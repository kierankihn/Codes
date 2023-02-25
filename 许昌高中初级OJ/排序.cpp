#include <bits/stdc++.h>
using namespace std;
const int MAXN = 114514;
int nums[MAXN + 5];
int n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }
    sort(nums + 1, nums + n + 1);
    for (int i = 1; i <= n; i++)
    {
        cout<<nums[i]<<" ";
    }
    cout << endl;
    return 0;
}