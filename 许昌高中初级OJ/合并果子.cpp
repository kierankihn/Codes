#include <bits/stdc++.h>
using namespace std;
const int MAXN = 114514;
int n;
int ans = 0;
priority_queue<int,vector<int>,greater<int>> nums;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        nums.push(tmp);
    }
    while (nums.size() != 1)
    {
        int tmp1, tmp2;
        tmp1 = nums.top();
        nums.pop();
        tmp2 = nums.top();
        nums.pop();
        nums.push(tmp1 + tmp2);
        ans += tmp1 + tmp2;
    }
    cout << ans << endl;
    return 0;
}