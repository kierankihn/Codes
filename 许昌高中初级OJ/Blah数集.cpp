#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int tmp;
    map<int, int> mp;
    cin >> tmp;
    mp[tmp] = 1;
    map<int, int>::iterator iter = mp.begin();
    cin >> n;
    for (int i = 0; i <= n; iter++, i++)
    {
        mp[(iter->first) * 2 + 1] = 1;
        mp[(iter->first) * 3 + 1] = 1;
    }
    iter = mp.begin();
    for (int i = 1; i < n; i++)
    {
        iter++;
    }
    cout << iter->first << " ";
    cout << endl;
}