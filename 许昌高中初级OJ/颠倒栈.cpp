#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
int nums[MAXN + 5];
int main()
{
    int i = 1;
    while (cin >> nums[i])
    {
        i++;
    }
    i--;
    while (i >= 1)
    {
        cout << nums[i] << " ";
        i--;
    }
    cout << endl;
    return 0;
}