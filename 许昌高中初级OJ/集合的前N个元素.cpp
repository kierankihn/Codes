#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    map<int, int> mp;
    mp[1] = 1;
    map<int, int>::iterator iter = mp.begin();
    cin >> n;
    for (int i = 0; i <= n; iter++, i++)
    {
        mp[(iter->first) * 2 + 1] = 1;
        mp[(iter->first) * 3 + 1] = 1;
    }
    iter = mp.begin();
    for (int i = 1; i <= n;i++)
    {
        cout << iter->first << " ";
        iter++;
    }
    cout << endl;
}